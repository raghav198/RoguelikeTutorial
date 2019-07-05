//
//  BuildingsGenerator.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/27/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "BuildingsGenerator.hpp"
#include "RoomsGenerator.hpp"

void BuildingsGenerator::generate()
{
    Point start = this->roi.p1;
    Point size = this->roi.shape();
    TCODBsp bsp(start.x, start.y, size.x, size.y);
    bsp.splitRecursive(NULL, 10, MAX_ROOM_SIZE, MAX_ROOM_SIZE, 1.5f, 1.5);
    this->listener.setGenerator(this);
//    BSPListener listener(this);
    bsp.traverseInvertedLevelOrder(&(this->listener), NULL);
}

void BuildingsGenerator::apply(Map& map)
{
    for (Rectangle rect : this->houses)
    {
        map.place(rect, Shape::FilledRect, Tile::FLOOR());
        
        RoomGenerator * gen = new RoomGenerator(rect);
        gen->generate();
        gen->apply(map);
        
        map.placeBroken(rect, Tile::FLOOR(), 0.2);
    }
}
