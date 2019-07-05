//
//  GlobalCommandSystem.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/29/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "GlobalCommandSystem.hpp"
#include "Engine.hpp"
#include <memory>

extern Engine * world;

int GlobalCommandSystem::accept(Message msg)
{
    std::shared_ptr<GlobalMessageType> command = std::static_pointer_cast<GlobalMessageType>(msg.data);
    if (*command == GlobalMessageType::Quit)
        world->running = false;
    
    return 1;
}
