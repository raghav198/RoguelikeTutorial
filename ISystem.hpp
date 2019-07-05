//
//  ISystem.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/28/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef ISystem_hpp
#define ISystem_hpp

#include "Message.hpp"
#include<memory>

class ISystem {
public:
    virtual int accept(Message) = 0;
    std::shared_ptr<ISystem> lookup(std::string);
//    ISystem(std::shared_ptr<Engine> engine) : engine(engine) {}
};

#endif /* ISystem_hpp */
