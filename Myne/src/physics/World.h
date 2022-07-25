#pragma once
#include <math.h>
#include "../utils/Vector2.h"
#include "Body.h"
#include "DynamicBody.h"
#include <vector>

class World{
public:
    World(Vector2 gravity);
    Vector2 getGravity();
    void update(float deltaTime);
    void addBody(Body* body);

    std::vector<Body*> checkCollisions(Body* body);
private:   
    Vector2 gravity;
    std::vector<Body*> bodies;
};