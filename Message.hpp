//
//  Message.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/28/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include <libtcod.hpp>
#include "Entity.hpp"
#include <memory>

enum MessageType {
    Move,
    Attack,
    Render,
    Global // things like fullscreen, inventory, etc.
};

enum GlobalMessageType {
    Empty,
    Quit
};

struct DisplayInfo {
    std::shared_ptr<Entity> source;
    TCODConsole * con;
};

struct Message {
    std::shared_ptr<Entity> sender;
    MessageType type;
    std::shared_ptr<void> data;
    
    template <class T>
    static Message createMessage(MessageType type, std::shared_ptr<Entity> owner, T data)
    {
        Message msg;
        msg.type = type;
        msg.sender = owner;
        msg.data = std::static_pointer_cast<void>(std::make_shared<T>(data));
        return msg;
    }
};
