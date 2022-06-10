#pragma once
#include "../library/opengl.h"
#include <vector>
#include "../texture/Texture.h"
#include "../utils/Rectangle.h"
#include <hash.hpp>
#include "VBO.h"
#include "VAO.h"

class SpriteBatch{
    
    struct Vertex{
        GLfloat x, y, u, v;
    };

public:
    SpriteBatch();
    //source == texture data position
    //destination == where it draws on screen
    void draw(Texture texture, Rectangle source, Rectangle destination);
    void render();
private:    
    struct QueueEntry{
        QueueEntry(Texture texture);

        Texture texture;
        std::vector<Vertex[6]> quads;      
        bool isUpdated;

        void addEntry(Rectangle source, Rectangle destination);  
    };

    std::vector<size_t> oldEntries;
    std::vector<QueueEntry> queue;
    std::vector<VBO> VBOS;

    VAO vao;

    size_t getHash(QueueEntry entry);
    size_t getHash(Vertex v);
};
