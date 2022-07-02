#include "UIRectangle.h"

UIRectangle::UIRectangle(float xMin, float yMin, float xMax, float yMax,
    float anchorXMin, float anchorYMin, float anchorXMax, float anchorYMax){
    this->xMin = xMin;
    this->yMin = yMin;
    this->xMax = xMax;
    this->yMax = yMax;
    this->anchorXMin = anchorXMin;
    this->anchorYMin = anchorYMin;
    this->anchorXMax = anchorXMax;
    this->anchorYMax = anchorYMax;
}

Rectangle UIRectangle::toRectangle(Rectangle parent){
    float axMin = parent.x + (parent.width * anchorXMin);
    float ayMin = parent.y + (parent.height * anchorYMin);
    float axMax = parent.x + (parent.width * anchorXMax);
    float ayMax = parent.y + (parent.height * anchorYMax);

    Rectangle result(xMin + axMin,
                     yMin + ayMin,
                     xMax + axMax - xMin - axMin,
                     yMax + ayMax - yMin - ayMin);

    return result;
}
