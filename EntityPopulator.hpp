//
//  EntityPopulator.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 7/5/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include "Rectangle.hpp"
#include "EntityManager.hpp"
class EntityPopulator {
    Rectangle roi;
    EntityManager& manager;
    
public:
    EntityPopulator(Rectangle roi, EntityManager& manager) : roi(roi), manager(manager) {}
    void populate();
};
