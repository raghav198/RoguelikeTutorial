//
//  Destructible.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 7/9/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "Destructible.hpp"

void Destructible::takeDamage(int damage)
{
    TCODRandom * rand = TCODRandom::getInstance();
    damage = rand->getInt(0, AC);
    HP -= damage;
}
