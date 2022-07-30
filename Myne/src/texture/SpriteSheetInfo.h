#pragma once
#include "../utils/Rectangle.h"

struct SpriteSheetInfo{
    //Creates a new SpriteSheetInfo object
    //sheetWidth is the number of sprites in the sheet horizontally
    //sheetHeight is the number of sprites in the sheet vertically
    //sheetScale scales the size of pixels in the sheet
    //edgeCenter is the number of pixels from the edge of the sprite to the center of the sprite
    SpriteSheetInfo(float sheetWidth, float sheetHeight, float sheetScale, float edgeCenter, float pixelsPerSprite);

    //returns bounds of a sprite at a specific location
    Rectangle spriteAt(int x, int y);

    //returns the center of a sprite at a specific location
    Rectangle centerAt(int x, int y);

    float sheetWidth;
    float sheetHeight;
    float sheetScale;
    float edgeCenter;
    float pixelsPerSprite;

    float sheetScaleX;
    float sheetScaleY;
    
    float center;  
};
