//
//  PlayerActor.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/19/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include "Actor.hpp"

class Entity;

class PlayerActor : public Actor {
public:
    virtual void act();
    PlayerActor(std::shared_ptr<Entity> owner) : Actor(owner) {}
};
