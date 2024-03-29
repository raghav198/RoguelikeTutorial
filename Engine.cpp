//
//  Engine.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/28/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "Engine.hpp"
#include "Map.hpp"
#include "EntityFactory.hpp"
#include "Rendering.hpp"
#include "CityMapGenerator.hpp"
#include "MovementSystem.hpp"
#include "MessageDispatcherSystem.hpp"
#include "GlobalCommandSystem.hpp"
#include "DisplaySystem.hpp"
#include "Actor.hpp"

#include <memory>

Engine * world;

void Engine::setupMap()
{
    this->map = Map(600, 600);
    std::unique_ptr<CityMapGenerator> mapGen = std::make_unique<CityMapGenerator>(Rectangle(0, 0, 600, 600));
    mapGen->generate();
    mapGen->apply(this->map);
    
   /* player = EntityFactory::makePlayer("Raghav");
    TCODRandom * rand = TCODRandom::getInstance();
    while(this->map.getTileAt(player->loc.x, player->loc.y).blocked)
    {
        std::cout << player->loc << " was blocked\n";
        player->loc.x = rand->get(0, 600);
        player->loc.y = rand->get(0, 600);
    }
    this->entities.push_back(player);
    
    this->recomputeFOV();*/
}

void Engine::setupEntities()
{
	player = EntityFactory::makePlayer("Raghav");
	TCODRandom * rand = TCODRandom::getInstance();
	while (this->map.getTileAt(player->loc.x, player->loc.y).blocked)
	{
		player->loc.x = rand->get(0, 600);
		player->loc.y = rand->get(0, 600);
	}
	this->addEntity(player);
	this->recomputeFOV();
}

void Engine::setupSystems()
{
    this->createSystem("dispatcher", std::make_shared<MessageDispatcherSystem>());
    this->createSystem("movement", std::make_shared<MovementSystem>());
    this->createSystem("global", std::make_shared<GlobalCommandSystem>());
    this->createSystem("display", std::make_shared<DisplaySystem>());
}

void Engine::setupConsole()
{
    TCODConsole::setCustomFont("arial10x10.png", TCOD_FONT_TYPE_GRAYSCALE | TCOD_FONT_LAYOUT_TCOD);
    TCODConsole::initRoot(100, 100, "My First Roguelike");
    mapArea = TCODConsole::root;
}

void Engine::frame()
{
    for (std::shared_ptr<Entity> entity : this->entities)
    {
        if (entity->actor != nullptr)
            entity->actor->act();
    }
}

Tile Engine::getTileAt(int x, int y)
{
    return this->map.getTileAt(x, y);
}

bool Engine::locIsBlocked(int x, int y)
{
	return this->getTileAt(x, y).blocked || this->entities.blockingEntitiesAtLoc(Point(x, y));
}

void Engine::createSystem(std::string name, std::shared_ptr<ISystem> system)
{
    this->systems.insert(std::pair<std::string, std::shared_ptr<ISystem>>(name, system));
}

std::shared_ptr<ISystem> Engine::getSystem(std::string name)
{
    return this->systems.at(name);
}

void Engine::publish(Message msg)
{
    this->getSystem("dispatcher")->accept(msg);
}
