//
//  Entity.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/19/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include <string>

#include "Point.hpp"


class Drawable;
class Actor;
class Destructible;

class Entity {
public:
//    int x, y;
    Point loc;
    std::string name;
    
    Entity() : loc(0, 0) {};
    
    Actor * actor;
    Drawable * drawable;
    Destructible * destructible;
    
    
};
