//
//  RoomsGenerator.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/29/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "RoomsGenerator.hpp"
#include "Engine.hpp"
#include "EntityFactory.hpp"
#include <libtcod.hpp>

#define MIN_ROOM_SIZE 3
#define MAX_ROOM_SIZE 10

extern Engine * world;

void RoomGenerator::generate()
{
    Point start = this->roi.p1;
    Point size = this->roi.shape();
    TCODBsp bsp(start.x, start.y, size.x, size.y);
    bsp.splitRecursive(NULL, 10, MAX_ROOM_SIZE, MAX_ROOM_SIZE, 1.5f, 1.5);
    this->listener.setGenerator(this);
    bsp.traverseInvertedLevelOrder(&(this->listener), NULL);
}

void RoomGenerator::apply(Map& map)
{
     TCODRandom * rand = TCODRandom::getInstance();
    for (Rectangle rect : this->rooms)
    {
        rect.filled = false;
        map.place(rect, Shape::OpenRect, Tile::WALL());
        
        // place up to 3 enemies in each room
        int enemies = rand->getInt(0, 3);
        for (int i = 0; i < enemies; i++)
        {
            Point loc(0, 0);
            loc.x = rand->getInt(rect.p1.x, rect.p2.x);
            loc.y = rand->getInt(rect.p1.y, rect.p2.y);
            world->addEntity(EntityFactory::genericEnemy(loc));
        }
    }
    
    for (auto corridor : this->corridors)
        map.dig(corridor.first, corridor.second, Tile::FLOOR());
    
    
    
    
}
