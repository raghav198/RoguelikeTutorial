//
//  Actor.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/19/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include "Component.hpp"

class Actor : public Component {
public:
    virtual void act() = 0;
    Actor(std::shared_ptr<Entity> owner) : Component(owner) {}
};
