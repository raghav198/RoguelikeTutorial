//
//  MessageDispatcherSystem.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/28/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef MessageDispatcherSystem_hpp
#define MessageDispatcherSystem_hpp

#include "ISystem.hpp"

#include <memory>

class MessageDispatcherSystem : public ISystem {
public:
    virtual int accept(Message);
};

#endif /* MessageDispatcherSystem_hpp */
