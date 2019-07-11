//
//  GlobalCommandSystem.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/29/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include "ISystem.hpp"

class GlobalCommandSystem : public ISystem {
public:
    virtual int accept(Message);
};
