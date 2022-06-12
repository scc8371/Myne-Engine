#include "Font.h"

Font::Font(const char* fontPath, int fontSize){
    
    if(FT_Init_FreeType(ResourceManager::GetInstance()->getFt())){
        std::cout << "Could not instantiate freetype library!" << std::endl;
        return;
    }

    FT_Face face;

    if(FT_New_Face(*ResourceManager::GetInstance()->getFt(), fontPath, 0, &face)){
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

    int atlas_width = w; 

    int x = 0;
    Texture texture = Texture(w, h);
    texture.Bind();

    for(int i = 32; i < 128; i++){
        if(FT_Load_Char(face, i, FT_LOAD_RENDER)){
            printf("loading character %i failed\n", i);
            continue;
        }

        glTexSubImage2D(GL_TEXTURE_2D, 0, x, 0, g->bitmap.width,
         g->bitmap.rows, GL_ALPHA, GL_UNSIGNED_BYTE, g->bitmap.buffer);

        x += g->bitmap.width;

        info[i].ax = g->advance.x >> 6;    
        info[i].ay = g->advance.y >> 6;

        info[i].bw = g->bitmap.width;
        info[i].bh = g->bitmap.rows;

        info[i].b1 = g->bitmap_left;
        info[i].bt = g->bitmap_top;

        info[i].tx = (float)x/w;
    }

    texture.Unbind();
}

void Font::draw(const char* text, Vector2 location){

    // :(

}
