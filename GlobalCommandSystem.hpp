//
//  GlobalCommandSystem.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/29/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef GlobalCommandSystem_hpp
#define GlobalCommandSystem_hpp

#include "ISystem.hpp"

class GlobalCommandSystem : public ISystem {
public:
    virtual int accept(Message);
};

#endif /* GlobalCommandSystem_hpp */
