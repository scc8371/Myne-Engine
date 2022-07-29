#include "SpriteBatch.h"

SpriteBatch* SpriteBatch::instance = NULL;

SpriteBatch::SpriteBatch(){}

//gets the instance of the singleton SpriteBatch
//inputs: none
//outputs: SpriteBatch* - pointer to the singleton SpriteBatch
SpriteBatch* SpriteBatch::getInstance(){
    if(!instance){
        instance = new SpriteBatch();
    }

    return instance;
}

//initializes the SpriteBatch
//inputs: none
//outputs: none
void SpriteBatch::initialize(){
    getInstance()->oldEntries = std::vector<size_t>();
    getInstance()->queue = std::vector<QueueEntry>();
    getInstance()->VBOS = std::vector<VBO>();
}

//draws a texture to the screen
//inputs: Texture texture - the texture to draw, 
//        Rectangle source - the source rectangle of the texture to draw (where it is on the texture sheet)
//        Rectangle destination - the destination rectangle of the texture to draw (where it is drawn on the screen)
//        Color color - the color to draw the texture (default is how it is on the texture sheet)
//        Shader shader - the shader to use to draw the texture (default is the default shader)
void SpriteBatch::draw(Texture texture, Rectangle source, Rectangle destination, Color color, Shader* shader){

    //create a new queue entry
    if(queue.size() == 0){
        QueueEntry temp = QueueEntry(texture, shader);
        temp.addEntry(source, destination, color);
        queue.push_back(temp);
    }   
    else if(queue.back().texture.ID == texture.ID && shader->ID == queue.back().shader->ID){
        //combines the meshes of the last item in the queue
        //batches the information
        queue.back().addEntry(source, destination, color);
    }
    else{
        QueueEntry temp = QueueEntry(texture, shader);
        temp.addEntry(source, destination, color);
        queue.push_back(temp);
    }
}

//establishes coordinates for a Vertex object
//inputs: GLfloat x - the x coordinate, GLfloat y - the y coordinate, Glfloat u - the first UV coordinate, GLfloat v - the second UV coordinate
Vertex::Vertex(GLfloat x, GLfloat y, GLfloat u, GLfloat v, Color color){
    this->x = x;
    this->y = y;
    this->u = u;
    this->v = v;

    //sets the color
    GLfloat* colors = color.toFloats();

    r = colors[0];
    g = colors[1];
    b = colors[2];
    a = colors[3];

    delete[] colors;
    colors = nullptr;
}

//renderer for the SpriteBatch, draws all the textures in the queue
//inputs: none
//outputs: none
void SpriteBatch::render(){
   
    int size = oldEntries.size();
    int qsize = queue.size();

    //updates the queue if it has changed
    for(int i = 0; i < qsize; i++){
        if(i > size - 1){
            queue[i].isUpdated = true;    
            continue;
        }

        //checks if the queue entry has been updated
        if(oldEntries[i] != getHash(queue[i])){
            queue[i].isUpdated = true;
            continue;
        }     

        //if not, sets the queue entry to not updated
        queue[i].isUpdated = false;
    }

    //establishes VBOs for each queue entry
    while(!(VBOS.size() == queue.size())){
       if(VBOS.size() > queue.size()){
           VBOS.back().Delete();
           VBOS.pop_back();
       } 
       else{
           VBO vbo = VBO();
           VBOS.push_back(vbo);
       }
    }

    //deletes the old VBOs
    oldEntries.clear();

    //renders the queue
    for(int i = 0; i < qsize; i++){

        queue[i].shader->Activate();

        queue[i].texture.Bind();
        VBOS[i].Bind();

        if(queue[i].isUpdated){

           glBufferData(GL_ARRAY_BUFFER, (queue[i].quads.size() + 1) * sizeof(Vertex),
            &queue[i].quads[0], GL_DYNAMIC_DRAW);                     
        }     

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat),
            NULL);

        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
            8 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat),
            (void*)(4 * sizeof(GLfloat)));

        glEnableVertexAttribArray(2);

        VBOS[i].Unbind();

        glDrawArrays(GL_TRIANGLES, 0, queue[i].quads.size());

        oldEntries.push_back(getHash(queue[i]));
        queue[i].isUpdated = false;
    }
    queue.clear();
}

//hashes the contents of the queue entry to speed up the process of rendering
//inputs: QueueEntry entry - the queue entry to hash
//outputs: size_t - the hash of the queue entry
size_t SpriteBatch::getHash(QueueEntry entry){
    size_t result = entry.texture.ID;
    for(int i = 0; i < entry.quads.size(); i++){
        result = (result << 1) ^ getHash(entry.quads[i]);
    }

    return result;
}

//hashes a vertex.. converts all data to one binary string.
//inputs: Vertex vertex - the vertex to hash
//outputs: size_t - the hash of the vertex
size_t SpriteBatch::getHash(Vertex vertex){
    size_t result = *(size_t*)&vertex.x;
    result ^= *(size_t*)&vertex.y << 1;
    result ^= *(size_t*)&vertex.u << 2;
    result ^= *(size_t*)&vertex.v << 3;

    return result;
}

//Establishes a queue Entry
//inputs: Texture texture - the texture to draw, Shader* shader - the shader to use to draw the texture
//outputs: none
SpriteBatch::QueueEntry::QueueEntry(Texture texture, Shader* shader) : texture(texture), shader(shader)
{
    quads = std::vector<Vertex>();
};

//adds an entry to the queue
//inputs: Rectangle source - the source rectangle of the texture to draw (where it is on the texture sheet)
//        Rectangle destination - the destination rectangle of the texture to draw (where it is drawn on the screen)
//        Color color - the color to draw the texture (default is how it is on the texture sheet)
//outputs: none
void SpriteBatch::QueueEntry::addEntry(Rectangle source, Rectangle destination, Color color){

    //establishes triangle patterns for the textures (makes a square), adds the coordinates to a quad entry in the queue
    Vertex temp[6] = {
        Vertex(destination.getX(), destination.getY(), 
            source.getX(), source.getY(), color),
        
        Vertex(destination.getX() + destination.getWidth(), destination.getY(), 
            source.getX() + source.getWidth(), source.getY(), color),
       
        Vertex(destination.getX() + destination.getWidth(), 
            destination.getY() + destination.getHeight(), 
            source.getX() + source.getWidth(), 
            source.getY() + source.getHeight(), color),
        
        Vertex(destination.getX(), destination.getY(),
            source.getX(), source.getY(), color),
        
        Vertex(destination.getX(), destination.getY() + destination.getHeight(),
            source.getX(), source.getY() + source.getHeight(), color),
       
        Vertex(destination.getX() + destination.getWidth(), 
            destination.getY() + destination.getHeight(), 
            source.getX() + source.getWidth(), 
            source.getY() + source.getHeight(), color)
    };

    for(int i = 0; i < 6; i++){
        quads.push_back(temp[i]);
    }
}

//Changes the background color of the window.
//inputs: float r - the red value of the background color, 
//        float g - the green value of the background color,
//        float b - the blue value of the background color
//        float a - the alpha value of the background color
//outputs: none
void SpriteBatch::colorWindow(float r, float g, float b, float a){
	//sets the color of the window.
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}