//
//  Abilities.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/23/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

class Ability {
public:
    virtual int perform() = 0;
    virtual int weight() = 0;
};

