//
//  CityMapGenerator.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/25/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include<vector>
#include "Rectangle.hpp"
#include "Map.hpp"
#include "MapGenerator.hpp"

struct CityMapGenerator : MapGenerator {
    std::vector<Rectangle> roads;
    std::vector<Rectangle> buildings;
    
    CityMapGenerator(Rectangle roi) : MapGenerator(roi) {}
    
    virtual void generate();
    virtual void apply(Map&);
};

