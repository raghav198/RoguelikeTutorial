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

// old_act()
//{
//    TCOD_key_t key;
//    TCODSystem::checkForEvent(TCOD_KEY_PRESSED, &key, NULL);
//    if (key.vk == TCODK_ESCAPE)
//    {
//        return Action(SYSTEM, EXIT);
//    }
//    else if (key.vk == TCODK_UP)
//    {
//        return Action(MOVE, Point(0, -1));
//    }
//    else if (key.vk == TCODK_DOWN)
//    {
//        return Action(MOVE, Point(0, 1));
//    }
//    else if (key.vk == TCODK_RIGHT)
//    {
//        return Action(MOVE, Point(1, 0));
//    }
//    else if (key.vk == TCODK_LEFT)
//    {
//        return Action(MOVE, Point(-1, 0));
//    }
//    return Action(MOVE, Point(0, 0));
//}

void PlayerActor::act()
{
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
        dest = Point(this->owner->x, this->owner->y - 1);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else if (key.vk == TCODK_DOWN || key.c == 'j')
    {
        dest = Point(this->owner->x, this->owner->y + 1);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else if (key.vk == TCODK_LEFT || key.c == 'h')
    {
        dest = Point(this->owner->x - 1, this->owner->y);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else if (key.vk == TCODK_RIGHT || key.c == 'l')
    {
        dest = Point(this->owner->x + 1, this->owner->y);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else if (key.c == 'y')
    {
        dest = Point(this->owner->x - 1, this->owner->y - 1);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else if (key.c == 'u')
    {
        dest = Point(this->owner->x + 1, this->owner->y - 1);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else if (key.c == 'b')
    {
        dest = Point(this->owner->x - 1, this->owner->y + 1);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else if (key.c == 'n')
    {
        dest = Point(this->owner->x + 1, this->owner->y + 1);
        msg = Message::createMessage(MessageType::Move, this->owner, dest);
    }
    else
    {
        msg = Message::createMessage(MessageType::Global, this->owner, GlobalMessageType::Empty);
    }
    world->publish(msg);
}