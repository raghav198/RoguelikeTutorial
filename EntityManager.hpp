//
//  EntityManager.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 7/5/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef EntityManager_hpp
#define EntityManager_hpp

#include "Entity.hpp"
#include "Point.hpp"
#include <vector>
#include <iterator>

class EntityManager {
private:
    std::vector<std::shared_ptr<Entity>> entities;
public:
    bool blockingEntitiesAtLoc(Point);
    void addEntity(std::shared_ptr<Entity> e)
    {
        entities.push_back(e);
    }

	auto begin() { return entities.begin(); }
	auto end() { return entities.end(); }


};

#endif /* EntityManager_hpp */
