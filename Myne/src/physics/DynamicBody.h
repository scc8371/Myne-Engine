
#pragma once
#include "Body.h"
#include "DynamicBody.h"

class DynamicBody : public Body{
public:
    DynamicBody(Rectangle bounds, Vector2 velocity);
    void update(float deltaTime, Vector2 gravity);
    Vector2 getVelocity();
    void setVelocity(Vector2 velocity);
private:
    Vector2 velocity;
};