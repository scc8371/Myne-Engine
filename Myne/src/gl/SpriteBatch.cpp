#include "SpriteBatch.h"

SpriteBatch::SpriteBatch(){
    oldEntries = std::vector<size_t>();
    queue = std::vector<QueueEntry>();
    VBOS = std::vector<VBO>();
}

void SpriteBatch::draw(Texture texture, Rectangle source, Rectangle destination){

    if(queue.size() == 0){
        QueueEntry temp = QueueEntry(texture);
        temp.addEntry(source, destination);
        queue.push_back(temp);
    }   
    else if(queue.back().texture.ID == texture.ID){
        //combines the meshes of the last item in the queue
        //batches the information
        queue.back().addEntry(source, destination);
    }
    else{
        QueueEntry temp = QueueEntry(texture);
        temp.addEntry(source, destination);
        queue.push_back(temp);
    }
}

Vertex::Vertex(GLfloat x, GLfloat y, GLfloat u, GLfloat v){
    this->x = x;
    this->y = y;
    this->u = u;
    this->v = v;
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
        queue[i].texture.Bind();
        VBOS[i].Bind();

        if(queue[i].isUpdated){

           glBufferData(GL_ARRAY_BUFFER, (queue[i].quads.size() + 1) * sizeof(Vertex),
            &queue[i].quads[0], GL_DYNAMIC_DRAW);                     
        }

        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat),
            NULL);

        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
            4 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

        glEnableVertexAttribArray(1);

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

SpriteBatch::QueueEntry::QueueEntry(Texture texture) : texture(texture)
{
    quads = std::vector<Vertex>();
};

void SpriteBatch::QueueEntry::addEntry(Rectangle source, Rectangle destination){

    
    Vertex temp[6] = {
        Vertex(destination.getX(), destination.getY(), 
            source.getX(), source.getY()),
        
        Vertex(destination.getX() + destination.getWidth(), destination.getY(), 
            source.getX() + source.getWidth(), source.getY()),
       
        Vertex(destination.getX() + destination.getWidth(), 
            destination.getY() + destination.getHeight(), 
            source.getX() + source.getWidth(), 
            source.getY() + source.getHeight()),
        
        Vertex(destination.getX(), destination.getY(),
            source.getX(), source.getY()),
        
        Vertex(destination.getX(), destination.getY() + destination.getHeight(),
            source.getX(), source.getY() + source.getHeight()),
       
        Vertex(destination.getX() + destination.getWidth(), 
            destination.getY() + destination.getHeight(), 
            source.getX() + source.getWidth(), 
            source.getY() + source.getHeight())
    };

    for(int i = 0; i < 6; i++){
        quads.push_back(temp[i]);
    }
}