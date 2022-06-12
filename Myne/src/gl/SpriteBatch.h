#pragma once
#include <opengl/opengl.h>
#include <vector>
#include "../texture/Texture.h"
#include "../utils/Rectangle.h"
#include "VBO.h"
#include "VAO.h"

#include <thread>

struct Vertex{
            Vertex(GLfloat x, GLfloat y, GLfloat u, GLfloat v);
            GLfloat x, y, u, v;
};

class SpriteBatch{
    
public:

    SpriteBatch();
    //source == texture data position
    //destination == where it draws on screen
    void draw(Texture texture, Rectangle source, Rectangle destination);
    void render();

    struct QueueEntry{
        QueueEntry(Texture texture);

        Texture texture;
        std::vector<Vertex> quads;      
        bool isUpdated;

        void addEntry(Rectangle source, Rectangle destination);          
    };

private:    
    
    std::vector<size_t> oldEntries;
    std::vector<QueueEntry> queue;
    std::vector<VBO> VBOS;   

    VAO vao;

    size_t getHash(QueueEntry entry);
    size_t getHash(Vertex v);
};
