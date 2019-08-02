//
//  EntityManager.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 7/5/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include "Entity.hpp"
#include "Point.hpp"
#include <vector>
#include <iterator>

class EntityManager {
private:
    std::vector<std::shared_ptr<Entity>> entities;
public:
    std::shared_ptr<Entity> blockingEntitiesAtLoc(Point);
    void addEntity(std::shared_ptr<Entity> e)
    {
        entities.push_back(e);
    }

	auto begin() { return entities.begin(); }
	auto end() { return entities.end(); }


};
