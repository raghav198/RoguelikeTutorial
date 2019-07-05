//
//  EntityFactory.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/19/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef EntityFactory_hpp
#define EntityFactory_hpp

#include "Entity.hpp"
#include "Point.hpp"

class EntityFactory {
public:
    static std::shared_ptr<Entity> makePlayer(std::string);
    static std::shared_ptr<Entity> genericEnemy(Point);
};

#endif /* EntityFactory_hpp */
