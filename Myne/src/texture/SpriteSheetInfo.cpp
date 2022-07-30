#include "SpriteSheetInfo.h"

SpriteSheetInfo::SpriteSheetInfo(float sheetWidth, float sheetHeight, float sheetScale, float edgeCenter, float pixelsPerSprite){
    this->sheetWidth = sheetWidth;
    this->sheetHeight = sheetHeight;
    this->sheetScale = sheetScale;
    this->edgeCenter = edgeCenter;
    this->pixelsPerSprite = pixelsPerSprite;

    sheetScaleX = 1.0f / sheetWidth;
    sheetScaleY = 1.0f / sheetHeight;

    center = 1.0f - edgeCenter * 2.0f;
}

Rectangle SpriteSheetInfo::spriteAt(int x, int y){
    return Rectangle(x * sheetScaleX, y * sheetScaleY, sheetScaleX, sheetScaleY);
}

Rectangle SpriteSheetInfo::centerAt(int x, int y){
    return Rectangle((x + edgeCenter) * sheetScaleX,
                    (y + edgeCenter) * sheetScaleY,
                    center * sheetScaleX, center * sheetScaleY);
}
