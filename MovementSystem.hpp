//
//  MovementSystem.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/28/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef MovementSystem_hpp
#define MovementSystem_hpp

#include "ISystem.hpp"

class MovementSystem : public ISystem {
public:
    virtual int accept(Message);
};

#endif /* MovementSystem_hpp */
