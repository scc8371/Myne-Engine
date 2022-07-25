#include "World.h"

World::World(Vector2 gravity){
    this->gravity = gravity;
}

Vector2 World::getGravity(){
    return gravity;
}

void World::addBody(Body* body){
    bodies.push_back(body);
}

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

std::vector<Body*> World::checkCollisions(Body* body){
    //use AABB collision detection to see if body is colliding with any of the other bodies
    std::vector<Body*> collisions;

    for(Body* otherBody : bodies){
        if(body == otherBody) continue;

        Rectangle collision = body->bounds.getIntersection(otherBody->bounds);
        
        if(collision.getSize().x > 0 && collision.getSize().y > 0){
            collisions.push_back(otherBody);
        }
    }

    return collisions;
}