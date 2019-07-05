//
//  SystemManager.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/28/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "SystemManager.hpp"
#include "MessageDispatcherSystem.hpp"
#include <string>

SystemManager::SystemManager(std::shared_ptr<Engine> engine)
{
//    this->engine = engine;
//    this->createSystem("dispatcher", std::make_shared<MessageDispatcherSystem>(std::shared_ptr<SystemManager>(this)));
}

void SystemManager::createSystem(std::string name, std::shared_ptr<ISystem> system)
{
    this->systems.insert(std::pair<std::string, std::shared_ptr<ISystem>>(name, system));
}

std::shared_ptr<ISystem> SystemManager::getSystem(std::string name)
{
    return this->systems.at(name);
}
