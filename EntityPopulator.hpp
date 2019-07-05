//
//  EntityPopulator.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 7/5/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef EntityPopulator_hpp
#define EntityPopulator_hpp

#include "Rectangle.hpp"
#include "EntityManager.hpp"
class EntityPopulator {
    Rectangle roi;
    EntityManager& manager;
    
public:
    EntityPopulator(Rectangle roi, EntityManager& manager) : roi(roi), manager(manager) {}
    void populate();
};

#endif /* EntityPopulator_hpp */
