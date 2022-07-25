#include "DynamicBody.h"

DynamicBody::DynamicBody(Rectangle bounds, Vector2 velocity) : Body(bounds)
{
    this->velocity = velocity;
}

void DynamicBody::update(float deltaTime, Vector2 gravity)
{
    velocity += gravity * deltaTime;
    bounds.x += velocity.x * deltaTime;
    bounds.y += velocity.y * deltaTime;
}

Vector2 DynamicBody::getVelocity()
{
    return velocity;
}

void DynamicBody::setVelocity(Vector2 velocity)
{
    this->velocity = velocity;
}