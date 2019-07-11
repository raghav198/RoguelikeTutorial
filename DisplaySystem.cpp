//
//  DisplaySystem.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 7/9/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "DisplaySystem.hpp"
#include "Engine.hpp"

extern Engine * world;

int DisplaySystem::accept(Message msg)
{
    Entity player = *msg.sender;
    world->drawMap();
    
    return 1;
}
