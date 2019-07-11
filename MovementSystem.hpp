//
//  MovementSystem.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/28/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include "ISystem.hpp"

class MovementSystem : public ISystem {
public:
    virtual int accept(Message);
};
