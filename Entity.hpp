//
//  Entity.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/19/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp


#include <string>
#include "Actor.hpp"
#include "Drawable.hpp"
#include "Point.hpp"

class Entity {
public:
//    int x, y;
    Point loc;
    int health;
    int armor;
    std::string name;
    
    Entity() : loc(0, 0) {};
    Entity * withName(std::string name) {this->name = name; return this; };
    Entity * withHealth(int health) {this->health = health; return this; };
    
    Actor * actor;
    Drawable * drawable;
    
};

#endif /* Entity_hpp */
