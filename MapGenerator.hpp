//
//  MapGenerator.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/27/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include "Rectangle.hpp"
#include "Map.hpp"
#include "EntityManager.hpp"

struct MapGenerator {
    Rectangle roi;
    virtual void generate() = 0;
    virtual void apply(Map&) = 0;
    
    MapGenerator(Rectangle roi) : roi(roi) {}
};
