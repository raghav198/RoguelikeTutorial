//
//  EntityFactory.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/23/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "EntityFactory.hpp"
#include "PlayerActor.hpp"

std::shared_ptr<Entity> EntityFactory::makePlayer(std::string name)
{
    std::shared_ptr<Entity> player = std::make_shared<Entity>();
    player->name = name;
    player->health = 10;
    player->armor = 0;
    
    player->loc = Point(200, 200);
    
    player->actor = new PlayerActor(player);
    player->drawable = new Drawable(player, '@', TCODColor::red);
    
    return player;
}

std::shared_ptr<Entity> EntityFactory::genericEnemy(Point loc)
{
    static int baddieNum = 0;
    std::shared_ptr<Entity> enemy = std::make_shared<Entity>();
    enemy->name = "baddie " + std::to_string(baddieNum++);
    enemy->health = 5;
    enemy->armor = 1;
    
    enemy->loc = loc;
    
    enemy->actor = nullptr;
    enemy->drawable = new Drawable(enemy, 'o', TCODColor::chartreuse, TCODColor::black);
    
    return enemy;
}
