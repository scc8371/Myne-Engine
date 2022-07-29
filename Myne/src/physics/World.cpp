#include "World.h"

//establishes a new world object, which stores a gravity vector
//inputs: Vector2 gravity: the gravity of the world
//outputs: none
World::World(Vector2 gravity){
    this->gravity = gravity;
}

//sets the gravity of the world
//inputs: Vector2 gravity: the new gravity of the world
//outputs: none
Vector2 World::getGravity(){
    return gravity;
}

//adds a new physics body to the world
//inputs: Body* body: the body to add to the world
//outputs: none
void World::addBody(Body* body){
    bodies.push_back(body);
}

//updates the world
//inputs: float deltaTime: the time since the last update
//outputs: none
void World::update(float deltaTime){
    for(Body* body : bodies){
        //check if body is polymorphic to DynamicBody
        if(dynamic_cast<DynamicBody*>((DynamicBody*)body)){
            DynamicBody* dynamicBody = (DynamicBody*)body;
            dynamicBody->update(deltaTime, gravity);
        }

        checkCollisions(body);

    }
}

//checks for collisions between the given body and all other bodies in the world
//inputs: Body* body: the body to check for collisions with
//outputs: none
//method of collision detection: AABB
void World::checkCollisions(Body* body){
    //use AABB collision detection to see if body is colliding with any of the other bodies
    std::vector<Body*> collisions;

    for(Body* otherBody : bodies){
        if(body == otherBody) continue;

        Rectangle collision = body->bounds.getIntersection(otherBody->bounds);
        
        //if the intersection is not empty, then the bodies are colliding
        if(collision.width != 0 && collision.height != 0){
            collisions.push_back(otherBody);
        }
    }

    //resolve collisions by moving body out of collision
    for(Body* otherBody : collisions){
        Rectangle collision = body->bounds.getIntersection(otherBody->bounds);

        //if the collision is on the x axis, move the body on the x axis
        if(collision.width < collision.height){
            if(body->bounds.x < otherBody->bounds.x){
                body->bounds.x -= collision.width;
            }
            else{
                body->bounds.x += collision.width;
            }
        }
        //if the collision is on the y axis, move the body on the y axis
        else{
            if(body->bounds.y < otherBody->bounds.y){
                body->bounds.y -= collision.height;
            }
            else{
                body->bounds.y += collision.height;
            }
        }

        //check if both bodies are dynamic
        if(dynamic_cast<DynamicBody*>((DynamicBody*)body) && dynamic_cast<DynamicBody*>((DynamicBody*)otherBody)){
            DynamicBody* dynamicBody = (DynamicBody*)body;
            DynamicBody* otherDynamicBody = (DynamicBody*)otherBody;

            //if the bodies are moving towards each other, reverse their velocities
            if(dynamicBody->getVelocity().x > 0 && otherDynamicBody->getVelocity().x < 0){
                dynamicBody->setVelocity(Vector2(-dynamicBody->getVelocity().x, dynamicBody->getVelocity().y));
                otherDynamicBody->setVelocity(Vector2(-otherDynamicBody->getVelocity().x, otherDynamicBody->getVelocity().y));
            }
            else if(dynamicBody->getVelocity().x < 0 && otherDynamicBody->getVelocity().x > 0){
                dynamicBody->setVelocity(Vector2(-dynamicBody->getVelocity().x, dynamicBody->getVelocity().y));
                otherDynamicBody->setVelocity(Vector2(-otherDynamicBody->getVelocity().x, otherDynamicBody->getVelocity().y));
            }
            else if(dynamicBody->getVelocity().y > 0 && otherDynamicBody->getVelocity().y < 0){
                dynamicBody->setVelocity(Vector2(dynamicBody->getVelocity().x, -dynamicBody->getVelocity().y));
                otherDynamicBody->setVelocity(Vector2(otherDynamicBody->getVelocity().x, -otherDynamicBody->getVelocity().y));
            }
            else if(dynamicBody->getVelocity().y < 0 && otherDynamicBody->getVelocity().y > 0){
                dynamicBody->setVelocity(Vector2(dynamicBody->getVelocity().x, -dynamicBody->getVelocity().y));
                otherDynamicBody->setVelocity(Vector2(otherDynamicBody->getVelocity().x, -otherDynamicBody->getVelocity().y));
            }

            //Reduce the velocity of the bodies by 30%
            dynamicBody->setVelocity(dynamicBody->getVelocity() * 0.7f);
            otherDynamicBody->setVelocity(otherDynamicBody->getVelocity() * 0.7f);
        }
    }
}