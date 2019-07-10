//
//  PlayerActor.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/19/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include <stdio.h>

#include "PlayerActor.hpp"
#include "Engine.hpp"


#include <libtcod.hpp>

extern Engine * world;

void PlayerActor::act()
{
    
    Message doDraw = Message::createMessage(MessageType::Render, this->owner, this->owner);
    world->publish(doDraw);
    
    TCOD_key_t key;
    TCODSystem::waitForEvent(TCOD_KEY_PRESSED, &key, NULL, true);

    Message msg;
    Point dest(0, 0);
    if (key.vk == TCODK_ESCAPE)
    {
        msg = Message::createMessage(MessageType::Global, this->owner, GlobalMessageType::Quit);
    }
    else if (key.vk == TCODK_UP || key.c == 'k')
    {
        dest = this->owner->loc + Point(0, -1); //Point(this->owner->x, this->owner->y - 1);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else if (key.vk == TCODK_DOWN || key.c == 'j')
    {
        dest = this->owner->loc + Point(0, 1); //Point(this->owner->x, this->owner->y + 1);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else if (key.vk == TCODK_LEFT || key.c == 'h')
    {
        dest = this->owner->loc + Point(-1, 0); //Point(this->owner->x - 1, this->owner->y);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else if (key.vk == TCODK_RIGHT || key.c == 'l')
    {
        dest = this->owner->loc + Point(1, 0); //Point(this->owner->x + 1, this->owner->y);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else if (key.c == 'y')
    {
        dest = this->owner->loc + Point(-1, -1); //Point(this->owner->x - 1, this->owner->y - 1);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else if (key.c == 'u')
    {
        dest = this->owner->loc + Point(1, -1); //Point(this->owner->x + 1, this->owner->y - 1);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else if (key.c == 'b')
    {
        dest = this->owner->loc + Point(-1, 1); //Point(this->owner->x - 1, this->owner->y + 1);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else if (key.c == 'n')
    {
        dest = this->owner->loc + Point(1, 1); //Point(this->owner->x + 1, this->owner->y + 1);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else
    {
        msg = Message::createMessage(MessageType::Global, this->owner, GlobalMessageType::Empty);
    }
    world->publish(msg);
}
