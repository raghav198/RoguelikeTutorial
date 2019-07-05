//
//  SystemManager.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/28/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef SystemManager_hpp
#define SystemManager_hpp

#include "ISystem.hpp"
#include <map>
#include <memory>

class SystemManager {
    std::map<std::string, std::shared_ptr<ISystem>> systems;
public:
    std::shared_ptr<ISystem> getSystem(std::string);
    void createSystem(std::string, std::shared_ptr<ISystem>);
    SystemManager(std::shared_ptr<Engine>);
};

#endif /* SystemManager_hpp */
