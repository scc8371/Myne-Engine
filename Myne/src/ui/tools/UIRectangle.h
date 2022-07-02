#pragma once
#include "../../utils/Rectangle.h"

class UIRectangle{
public:
    UIRectangle(float xMin, float yMin, float xMax, float yMax,
    float anchorXMin, float anchorYMin, float anchorXMax, float anchorYMax);
    UIRectangle(){}
    Rectangle toRectangle(Rectangle rectangle);

private:
    float xMin, yMin, xMax, yMax, anchorXMin, anchorYMin, anchorXMax, anchorYMax;
};
