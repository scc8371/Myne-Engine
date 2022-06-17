#include "SpriteBatch.h"

SpriteBatch* SpriteBatch::instance = NULL;

SpriteBatch::SpriteBatch(){}

SpriteBatch* SpriteBatch::GetInstance(){
    if(!instance){
        instance = new SpriteBatch();
    }

    return instance;
}

void SpriteBatch::initialize(){
    GetInstance()->oldEntries = std::vector<size_t>();
    GetInstance()->queue = std::vector<QueueEntry>();
    GetInstance()->VBOS = std::vector<VBO>();
}

void SpriteBatch::draw(Texture texture, Rectangle source, Rectangle destination, Color color, Shader* shader){

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


Vertex::Vertex(GLfloat x, GLfloat y, GLfloat u, GLfloat v, Color color){
    this->x = x;
    this->y = y;
    this->u = u;
    this->v = v;

    GLfloat* colors = color.toFloats();

    r = colors[0];
    g = colors[1];
    b = colors[2];
    a = colors[3];
    
    delete[] colors;
    colors = nullptr;
}

void SpriteBatch::render(){
    
    int size = oldEntries.size();
    int qsize = queue.size();

    for(int i = 0; i < qsize; i++){
        if(i > size - 1){
            queue[i].isUpdated = true;    
            continue;
        }

        if(oldEntries[i] != getHash(queue[i])){
            queue[i].isUpdated = true;
            continue;
        }     

        queue[i].isUpdated = false;
    }

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

    oldEntries.clear();

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

size_t SpriteBatch::getHash(QueueEntry entry){
    size_t result = entry.texture.ID;
    for(int i = 0; i < entry.quads.size(); i++){
        result = (result << 1) ^ getHash(entry.quads[i]);
    }

    return result;
}

//hashes a vertex.. converts all data to one binary string.
size_t SpriteBatch::getHash(Vertex vertex){
    size_t result = vertex.x;
    result ^= (size_t)vertex.y << 1;
    result ^= (size_t)vertex.u << 2;
    result ^= (size_t)vertex.v << 3;

    return result;
}

SpriteBatch::QueueEntry::QueueEntry(Texture texture, Shader* shader) : texture(texture), shader(shader)
{
    quads = std::vector<Vertex>();
};

void SpriteBatch::QueueEntry::addEntry(Rectangle source, Rectangle destination, Color color){

    
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

void SpriteBatch::colorWindow(float r, float g, float b, float a){
	//sets the color of the window.
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}