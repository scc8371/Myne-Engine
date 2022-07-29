#include "Body.h"

//establishes a new body object, used to store data on the physics engine
//inputs: Rectangle bounds: the bounds of the body.
//outputs: none
Body::Body(Rectangle bounds)
{
    this->bounds = bounds;
}