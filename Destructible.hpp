//
//  Destructible.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 7/9/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include "Component.hpp"
#include <libtcod.hpp>

class Destructible : public Component {
private:
    int maxHP;
    int HP;
    int AC;
    int EV;
public:
    Destructible(std::shared_ptr<Entity> owner, int hp, int armor, int evasion) : Component(owner), maxHP(hp), HP(hp), AC(armor), EV(evasion) {}
    
};
