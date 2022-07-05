#include "UISprite.h"

UISprite::UISprite(Texture texture, Rectangle source, Rectangle center, Vector2 scale) : Sprite(texture, source){
    this->center = center;
    this->scale = scale;
    setCenter(center);
}

void UISprite::setCenter(Rectangle center){
    for(int i = 0; i < 3; i++){
        renderSections[0][i].x = source.x;
        renderSections[0][i].width = center.x - source.x;
        renderSections[1][i].x = center.x;
        renderSections[1][i].width = center.width;
        renderSections[2][i].x = center.x + center.width;
        renderSections[2][i].width = (source.x + source.width) - (center.x + center.width);

        renderSections[i][0].y = source.y;
        renderSections[i][0].height = center.y - source.y;
        renderSections[i][1].y = center.y;
        renderSections[i][1].height = center.height;
        renderSections[i][2].y = center.y + center.height;
        renderSections[i][2].height = (source.y + source.height) - (center.y + center.height);

    }
}

/*========================================================

    Renders UI in a grid of 9 squares [3][3]. This method 
    renders each section individually by scaling the individual
    sections of the texture.

    ========================================================*/
void UISprite::draw(Rectangle destination, Color color){
    //checks if the sprite is too small to draw
    Vector2 minSize = (source.getSize() - center.getSize());

    minSize.x *= scale.x;
    minSize.y *= scale.y;

    if(destination.width <= minSize.x || destination.height <= minSize.y){
        Sprite::draw(destination, color);
        printf("UISprite drawn regularly due to its small size.");
        return;
    }

    //center not defined
    if(center.width == 0 || center.height == 0){
        printf("center not defined for UISprite");
        return;
    } 

    Rectangle temp = renderSections[0][0];
    Rectangle renderTemp(destination);

    Vector2 corners(
        (renderSections[0][0].getSize() + renderSections[2][2].getSize()).x * scale.x,
        (renderSections[0][0].getSize() + renderSections[2][2].getSize()).y * scale.y
    );  

    Vector2 corner(
        renderSections[0][0].getSize().x * scale.x,
        renderSections[0][0].getSize().y * scale.y
    );

    //sets the location of the texture to be drawn
    temp.setLocation(Vector2(renderTemp.x, renderTemp.y));
    //scales the texture
    temp.width *= scale.x;
    temp.height *= scale.y;
    drawSection(Vector2(0, 0), temp, color);

    temp = renderSections[1][0];
    temp.setLocation(Vector2(renderTemp.x + corner.x, renderTemp.y));
    temp.width = renderTemp.width - corners.x;
    temp.height *= scale.y;
    drawSection(Vector2(1, 0), temp, color);

    temp = renderSections[2][0];
    temp.setLocation(Vector2((renderTemp.x + renderTemp.width)
     - renderSections[2][0].width * scale.x,
     renderTemp.y));
    temp.width *= scale.x;
    temp.height *= scale.y;
    drawSection(Vector2(2, 0), temp, color);

    temp = renderSections[0][1];
    temp.setLocation(Vector2(renderTemp.x, renderTemp.y + corner.y));
    temp.width *= scale.x;
    temp.height = renderTemp.height - corners.y;
    drawSection(Vector2(0, 1), temp, color);

    temp = renderSections[1][1];
    temp.setLocation(Vector2(renderTemp.x + corner.x, renderTemp.y + corner.y));
    temp.width = renderTemp.width - corners.x;
    temp.height = renderTemp.height - corners.y;
    drawSection(Vector2(1, 1), temp, color);

    temp = renderSections[2][1];
    temp.setLocation(Vector2((renderTemp.x + renderTemp.width)
        - renderSections[2][0].width * scale.x,
        renderTemp.y + corner.y));
    temp.width *= scale.x;
    temp.height = renderTemp.height - corners.y;
    drawSection(Vector2(2, 1), temp, color);

    temp = renderSections[0][2];
    temp.setLocation(Vector2(renderTemp.x,
        (renderTemp.y + renderTemp.height) - renderSections[0][2].height * scale.y));
    temp.width *= scale.x;
    temp.height *= scale.y;
    drawSection(Vector2(0, 2), temp, color);

    temp = renderSections[1][2];
    temp.setLocation(Vector2(renderTemp.x + corner.x,
        (renderTemp.y + renderTemp.height) - renderSections[0][2].height * scale.y));
    temp.width = renderTemp.width - corners.x;
    temp.height *= scale.y;
    drawSection(Vector2(1, 2), temp, color);

    temp = renderSections[1][2];
    temp.setLocation(Vector2(renderTemp.x + corner.x,
        (renderTemp.y + renderTemp.height) - renderSections[0][2].height * scale.y));
    temp.width = renderTemp.width - corners.x;
    temp.height *= scale.y;
    drawSection(Vector2(1, 2), temp, color);

    temp = renderSections[2][2];
    temp.setLocation(Vector2((renderTemp.x + renderTemp.width)
        - renderSections[2][0].width * scale.x,
        (renderTemp.y + renderTemp.height) - renderSections[0][2].height * scale.y));
    temp.width *= scale.x;
    temp.height *= scale.y;
    drawSection(Vector2(2, 2), temp, color);
}
