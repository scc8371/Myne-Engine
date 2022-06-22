#include "Font.h"

Font::Font(){}

Font::Font(const char* fontPath, int fontSize){

    if(FT_Init_FreeType(ResourceManager::getInstance()->getFt())){
        std::cout << "Could not instantiate freetype library!" << std::endl;
        return;
    }

    FT_Face face;

    if(FT_New_Face(*ResourceManager::getInstance()->getFt(), fontPath, 0, &face)){
        std::cout << "Failed to load font" << std::endl;
        return;
    }

    FT_Set_Pixel_Sizes(face, 0, fontSize);

    FT_GlyphSlot g = face->glyph;
    int w, h = 0;

    for(int i = 32; i < 128; i++){
        if(FT_Load_Char(face, i, FT_LOAD_RENDER)){
            printf("loading character %i failed\n", i);
            continue;
        }

        w += g->bitmap.width;
        h = std::max(h, (int)g->bitmap.rows);
    }

    int x = 0;
    this->texture = Texture(w, h);
    this->texture.Bind();

    for(int i = 32; i < 128; i++){
        if(FT_Load_Char(face, i, FT_LOAD_RENDER)){
            printf("loading character %i failed\n", i);
            continue;
        }

        glTexSubImage2D(GL_TEXTURE_2D, 0, x, 0, g->bitmap.width,
         g->bitmap.rows, GL_RED, GL_UNSIGNED_BYTE, g->bitmap.buffer);

        info[i].ax = g->advance.x >> 6;    
        info[i].ay = g->advance.y >> 6;

        info[i].bw = g->bitmap.width;
        info[i].bh = g->bitmap.rows;

        info[i].b1 = g->bitmap_left;
        info[i].bt = g->bitmap_top;

        info[i].tx = (float)x / w;
        info[i].tw = (float)g->bitmap.width / w;
        info[i].th = (float)g->bitmap.rows / h;

        x += g->bitmap.width;
    }

    this->texture.Unbind();
}

void Font::draw(const char* text, Vector2 location, Color color){

    Vector2 pos = location;

    //checks if character is within the drawable range of chars
    for(int i = 0; i < strlen(text); i++){
        if(text[i] < 32 || text[i] >= 128){
            continue;
        }

        CharacterInfo ch = info[(int)text[i]];

        int width = ch.bw;
        int height = ch.bh;
        int x = pos.x + ch.b1; 
        int y = pos.y - ch.bt;

        Rectangle source(ch.tx, 0, ch.tw, ch.th);
        Rectangle bounds(x, y, width, height);

        SpriteBatch::getInstance()->draw(texture, source, bounds, color, ResourceManager::getInstance()->getFontShader());

        pos.x += ch.ax;
    }
}


