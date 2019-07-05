//
//  CityMapGenerator.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/25/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "CityMapGenerator.hpp"
#include "BuildingsGenerator.hpp"
#include "Map.hpp"
#include<random>

#define K 3 // at depth 3 has a 50% chance to terminate
#define N 3 // 3rd order

static std::default_random_engine generator;

void recurse(Rectangle roi, CityMapGenerator * map, int depth)
{
    std::uniform_real_distribution<double> uniform(0, 1);
    double r = uniform(generator);
    double crit = std::pow(depth, N) / (std::pow(depth, N) + std::pow(K, N));
    if (r < crit)
        return map->buildings.push_back(roi);
    
    int H, W;
    Point size = roi.shape();
    H = size.y;
    W = size.x;
    
    if (H < 9 || W < 9)
        return;
    
    bool orientation;
    if (H / W > 3)
        orientation = true;
    else if (W / H > 3)
        orientation = false;
    else
        orientation = uniform(generator) < 0.5;
    
    Rectangle child1, child2;
    map->roads.push_back(roi.trisect(orientation, child1, child2));
    
    recurse(child1, map, depth + 1);
    recurse(child2, map, depth + 1);
}

void CityMapGenerator::generate()
{
    recurse(this->roi, this, 0);
}

void CityMapGenerator::apply(Map& map)
{
    map.place(this->roi, Shape::FilledRect, Tile::ROAD());
    for (Rectangle rect : this->buildings)
    {
        map.place(rect, Shape::FilledRect, Tile::GRASS());
//        map.placeComponent(rect, Place::GlassWall);
        BuildingsGenerator * gen = new BuildingsGenerator(rect);
        gen->generate();
        gen->apply(map);
    }
}
