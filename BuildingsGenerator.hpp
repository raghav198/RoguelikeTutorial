//
//  BuildingsGenerator.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/27/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef BuildingsGenerator_hpp
#define BuildingsGenerator_hpp

#include "MapGenerator.hpp"
#include "Map.hpp"
#include <libtcod.hpp>

#define MIN_ROOM_SIZE 10
#define MAX_ROOM_SIZE 60

struct BuildingsGenerator : MapGenerator {
    BuildingsGenerator(Rectangle roi) : MapGenerator(roi) {}
    
    std::vector<Rectangle> houses;
    
    class : public ITCODBspCallback {
        BuildingsGenerator * gen;
    public:
        void setGenerator(BuildingsGenerator * gen) { this->gen = gen; }
        bool visitNode(TCODBsp * node, void * data)
        {
            if (node->isLeaf())
            {
                TCODRandom * rand = TCODRandom::getInstance();
                int w = rand->getInt(MIN_ROOM_SIZE, node->w - 2);
                int h = rand->getInt(MIN_ROOM_SIZE, node->h - 2);
                int x = rand->getInt(node->x + 1, node->x + node->w - w - 1);
                int y = rand->getInt(node->y + 1, node->y + node->h - h - 1);
                
                this->gen->houses.push_back(Rectangle(x, y, w, h));
            }
            return true;
        }
    } listener;
    
    virtual void generate();
    virtual void apply(Map&);
};

#endif /* BuildingsGenerator_hpp */
