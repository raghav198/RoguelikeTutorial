//
//  EntityFactory.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/23/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "EntityFactory.hpp"
#include "PlayerActor.hpp"
#include "Drawable.hpp"
#include "Destructible.hpp"
#include "PlayerActor.hpp"

#include <libtcod.hpp>

std::shared_ptr<Entity> EntityFactory::makePlayer(std::string name)
{
    std::shared_ptr<Entity> player = std::make_shared<Entity>();
    player->name = name;
    
    player->loc = Point(200, 200);
    
    player->actor = new PlayerActor(player);

    player->drawable = new Drawable(player, '@', TCODColor::red, TCODColor::black);
    player->destructible = new Destructible(player, 10, 0, 0);

    
    return player;
}

std::shared_ptr<Entity> EntityFactory::genericEnemy(Point loc)
{
    static int baddieNum = 0;
    std::shared_ptr<Entity> enemy = std::make_shared<Entity>();
    enemy->name = "baddie " + std::to_string(baddieNum++);
    
    enemy->loc = loc;
    
    enemy->actor = nullptr;
    enemy->drawable = new Drawable(enemy, 'o', TCODColor::chartreuse, TCODColor::black);
    enemy->destructible = new Destructible(enemy, 5, 1, 0);
    
    return enemy;
}
