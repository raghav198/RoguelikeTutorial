//
//  EntityManager.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 7/5/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "EntityManager.hpp"

std::shared_ptr<Entity> EntityManager::blockingEntitiesAtLoc(Point loc)
{
    // naively assume all entities are blocking for now
    for (std::shared_ptr<Entity> e : entities)
    {
        if (e->loc == loc)
            return e;
    }
    return nullptr;
}
