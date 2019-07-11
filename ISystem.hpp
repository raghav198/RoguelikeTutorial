//
//  ISystem.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/28/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include "Message.hpp"
#include<memory>

class ISystem {
public:
    virtual int accept(Message) = 0;
    std::shared_ptr<ISystem> lookup(std::string);
//    ISystem(std::shared_ptr<Engine> engine) : engine(engine) {}
};
