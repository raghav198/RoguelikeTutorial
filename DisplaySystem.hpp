//
//  DisplaySystem.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 7/9/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef DisplaySystem_hpp
#define DisplaySystem_hpp

#include "ISystem.hpp"
#include <libtcod.hpp>

class DisplaySystem : public ISystem {
public:
    virtual int accept(Message);
};

#endif /* DisplaySystem_hpp */
