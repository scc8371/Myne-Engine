//#pragma once
//#include <vector>
//#include "Player.h"
//#include "Enemy.h"
//#include "Material.h"
//#include "Weapon.h"
//
//typedef EntityType T;
//
//class EntityManager
//{
//	static EntityManager* instance;
//	std::vector<Entity> entityList;
//
//	EntityManager() {
//		entityList = std::vector<Entity>();
//	}
//
//	~EntityManager() {
//		delete instance;
//	}
//
//public:
//	static EntityManager* getInstance() {
//		if (!instance) {
//			instance = new EntityManager();
//		}
//
//		return instance;
//	}
//
//	/// <summary>
//	/// Adds an entity to the list
//	/// </summary>
//	/// <param name="entity">Entity to add</param>
//	void add(Entity entity) {
//		entityList.push_back(entity);
//	}
//
//	void remove(Entity* entity) {
//		for (int i = 0, size = entityList.size(); i < size; i++) {
//			if (&entityList[i] == entity) {
//				entityList.erase(entityList.begin() + i);
//			}
//		}
//	}
//
//	/// <summary>
//	/// returns pointer to the player object
//	/// </summary>
//	/// <returns>pointer to the player object</returns>
//	Entity* player() {
//		for (int i = 0, size = entityList.size(); i < size; i++) {
//			if (entityList[i].getType() == EntityType::Player) {
//				return &entityList[i];
//			}
//		}
//	}
//
//	/// <summary>
//	/// returns all of a specific entity present in this manager
//	/// </summary>
//	/// <returns>list of T entities</returns>
//	std::vector<Entity*> getEntities(T entityType) {
//		std::vector<Entity*> returnedEntities;
//
//		for (int i = 0, size = entityList.size(); i < size; i++) {
//			if (entityList[i].getType() == entityType) {
//				returnedEntities.push_back(&entityList[i]);
//
//				//can't be more than one player.
//				if (entityType == EntityType::Player) {
//					return;
//				}
//			}
//		}
//
//		return returnedEntities;
//	}
//};

