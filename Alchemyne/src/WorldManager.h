//#pragma once
//#include "World.h"
//class WorldManager {
//	static WorldManager* instance;
//	World* world;
//
//	WorldManager() {
//		world = new World(new b2Vec2(0, 10.0f));
//	}
//	~WorldManager() {
//		delete instance;
//	}
//
//public:
//	static WorldManager* getInstance() {
//		if (!instance) {
//			instance = new WorldManager();
//		}
//		return instance;
//	}
//
//	/// <summary>
//	/// returns pointer to the physics world.
//	/// </summary>
//	/// <returns>pointer to the physics world</returns>
//	World* getWorld() {
//		return world;
//	}
//
//	void addBody(b2Body body) {
//		//....
//	}
//};