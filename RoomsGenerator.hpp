//
//  RoomsGenerator.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/29/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include "MapGenerator.hpp"
#include "Map.hpp"
#include <utility>
#include <libtcod.hpp>

struct RoomGenerator : MapGenerator {
    RoomGenerator(Rectangle roi) : MapGenerator(roi) {}
    std::vector<Rectangle> rooms;
    std::vector<std::pair<Point, Point>> corridors;
    
    class : public ITCODBspCallback {
        RoomGenerator * gen;
    private:
        Point getNearCenter(int x, int y, int w, int h)
        {
            TCODRandom * rand = TCODRandom::getInstance();
            int cx = (int)rand->getDouble(x, x + w, x + w / 2);
            int cy = (int)rand->getDouble(y, y + h, y + h / 2);
            return Point(cx, cy);
        }
    public:
        void setGenerator(RoomGenerator * gen) { this->gen = gen; }
        bool visitNode(TCODBsp * node, void * data)
        {
            
            if (node->isLeaf())
                gen->rooms.push_back(Rectangle(node->x, node->y, node->w, node->h));
            else
            {
                TCODBsp * left = node->getLeft();
                TCODBsp * right = node->getRight();
                
//                Point centerLeft = Point(left->x + left->w / 2, left->y + left->h / 2);
//                Point centerRight = Point(right->x + right->w / 2, right->y + right->h / 2);
                Point centerLeft = getNearCenter(left->x, left->y, left->w, left->h);
                Point centerRight = getNearCenter(right->x, right->y, right->w, right->h);
                
                gen->corridors.push_back(std::pair<Point, Point>(centerLeft, centerRight));
            }
            return true;
        }
    } listener;
    
    std::vector<Rectangle> houses;
    
    virtual void generate();
    virtual void apply(Map&);
};
