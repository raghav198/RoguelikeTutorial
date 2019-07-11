//
//  Component.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/29/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include <memory>

class Entity;
class Component {
protected:
    std::shared_ptr<Entity> owner;
public:
    Component(std::shared_ptr<Entity> owner) : owner(owner) {}
};
