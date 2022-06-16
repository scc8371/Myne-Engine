#pragma once
#include "../ResourceManager.h"
#include <opengl/opengl.h>
#include <vector>
#include "../texture/Texture.h"
#include "../utils/Rectangle.h"
#include "VBO.h"
#include "VAO.h"
#include "Shader.h"


#include <thread>

struct Vertex{
            Vertex(GLfloat x, GLfloat y, GLfloat u, GLfloat v);
            GLfloat x, y, u, v;
};

class SpriteBatch{
    
public:
    static SpriteBatch* GetInstance();
    //source == texture data position
    //destination == where it draws on screen
    void draw(Texture texture, Rectangle source, Rectangle destination, Shader* shader = ResourceManager::GetInstance()->getShader());
    void render();
    static void initialize();
    void colorWindow(float r, float g, float b, float a);

    struct QueueEntry{
        QueueEntry(Texture texture, Shader* shader);

        Texture texture;
        std::vector<Vertex> quads;      
        bool isUpdated;
        Shader* shader;

        void addEntry(Rectangle source, Rectangle destination);          
    };

private:    
    static SpriteBatch* instance;
    SpriteBatch();
    std::vector<size_t> oldEntries;
    std::vector<QueueEntry> queue;
    std::vector<VBO> VBOS;   

    VAO vao;
    
    size_t getHash(QueueEntry entry);
    size_t getHash(Vertex v);
};
