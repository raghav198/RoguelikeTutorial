//
//  main.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/19/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include <iostream>
#include <libtcod.hpp>
#include <string>

#include "Engine.hpp"
#include "Entity.hpp"
#include "EntityFactory.hpp"
#include "Actor.hpp"
#include "CityMapGenerator.hpp"
#include "MapGenerator.hpp"
#include "Rendering.hpp"

extern Engine * world;

int main(int argc, const char * argv[])
{
//    Engine * e = new Engine();
    world = new Engine();
    world->setup();
    while (!TCODConsole::isWindowClosed() && world->running)
        world->frame();
}

//int old_main(int argc, const char * argv[])
//{
//
//    Map map(600, 600);
//    CityMapGenerator * mapGen = new CityMapGenerator(Rectangle(0, 0, 600, 600));
//    mapGen->generate();
//    mapGen->apply(map);
//
//    /*std::cout << "Roads:\n";
//    for (Rectangle road : mapGen->roads)
//        std::cout << road << "\n";*/
//
//    std::cout << "Buildings:\n";
//    for (Rectangle building : mapGen->buildings)
//        std::cout << building << "\n";
//    TCODConsole::setCustomFont("arial10x10.png", TCOD_FONT_TYPE_GRAYSCALE | TCOD_FONT_LAYOUT_TCOD);
//    TCODConsole::initRoot(100, 100, "My First Roguelike");
//
//    std::shared_ptr<Entity> player = EntityFactory::makePlayer("Raghav");
//
//    while (!TCODConsole::isWindowClosed())
//    {
//        Action playerAction = player->actor->act();
//        if (playerAction.type == SYSTEM)
//            break;
//        else
//        {
//            player->x += playerAction.loc.x;
//            player->y += playerAction.loc.y;
//        }
//        /*TCODConsole::root->clear();
//        TCODConsole::root->putChar(player->x, player->y, '@');
//        TCODConsole::root->flush();*/
//        TCODConsole * root = TCODConsole::root;
//        DrawMap(root, map, Point(player->x, player->y));
//    }
//    return 0;
//}
