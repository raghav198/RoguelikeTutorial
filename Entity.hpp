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
#include "Destructible.hpp"

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

#endif /* Entity_hpp */
