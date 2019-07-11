//
//  MessageDispatcherSystem.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/28/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//


#include "MessageDispatcherSystem.hpp"
#include <string>

int MessageDispatcherSystem::accept(Message msg)
{
    if (msg.type == MessageType::Move)
    {
        std::shared_ptr<ISystem> movementSys = this->lookup("movement");
        movementSys->accept(msg);
    }
    else if (msg.type == MessageType::Global)
    {
        std::shared_ptr<ISystem> globalSys = this->lookup("global");
        globalSys->accept(msg);
    }
    else if (msg.type == MessageType::Render)
    {
        std::shared_ptr<ISystem> displaySys = this->lookup("display");
        displaySys->accept(msg);
    }
    return 0;
}
