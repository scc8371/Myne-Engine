#include "DynamicBody.h"

//establishes a new dynamic body object, which is a body that can move
//inputs: Rectangle bounds: the bounds of the body, Vector2 velocity: the velocity of the body
//outputs: none
DynamicBody::DynamicBody(Rectangle bounds, Vector2 velocity) : Body(bounds)
{
    this->velocity = velocity;
}

//updates the dynamic body
//inputs: float deltaTime: the time since the last update, float gravity: the gravity of the world
//outputs: none
void DynamicBody::update(float deltaTime, Vector2 gravity)
{
    velocity += gravity * deltaTime;
    bounds.x += velocity.x * deltaTime;
    bounds.y += velocity.y * deltaTime;
}

//gets the velocity of the dynamic body
//inputs: none
//outputs: Vector2: the velocity of the dynamic body
Vector2 DynamicBody::getVelocity()
{
    return velocity;
}

//sets the velocity of the dynamic body
//inputs: Vector2 velocity: the new velocity of the dynamic body
//outputs: none
void DynamicBody::setVelocity(Vector2 velocity)
{
    this->velocity = velocity;
}