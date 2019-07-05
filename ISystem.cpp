//
//  ISystem.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/29/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//


#include "Engine.hpp"

#include <memory>

extern Engine * world;

std::shared_ptr<ISystem> ISystem::lookup(std::string system)
{
    return world->getSystem(system);
}
