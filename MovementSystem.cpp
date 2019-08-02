//
//  MovementSystem.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/28/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "MovementSystem.hpp"
#include "Engine.hpp"

extern Engine * world;

int MovementSystem::accept(Message msg)
{
    std::shared_ptr<Point> dest = std::static_pointer_cast<Point>(msg.data);
    std::shared_ptr<Entity> target = world->entities.blockingEntitiesAtLoc(*dest);
    if (target != nullptr)
    {
        Message atk = Message::createMessage(MessageType::Attack, msg.sender, *target);
        world->publish(atk);
        std::cout << "Attacking " << target->name << "\n";
    }
    else if (!world->getTileAt(dest->x, dest->y).blocked)
    {
        msg.sender->loc = *dest;
        if (msg.sender == world->player)
            world->recomputeFOV();
    }
    
    return 1;
}
