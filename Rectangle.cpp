//
//  Rectangle.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/25/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "Rectangle.hpp"
#include <random>
#include <libtcod.hpp>

Point Rectangle::shape()
{
    return this->p2 - this->p1;
}

Point Rectangle::center()
{
    return (this->p1 + this->p2) * 0.5;
}

Rectangle Rectangle::trisect(bool orientation, Rectangle& child1, Rectangle& child2)
{
    int H, W;
    Point size = this->shape();
    H = size.y;
    W = size.x;
    
    TCODRandom * rand = TCODRandom::getInstance();
    rand->setDistribution(TCOD_DISTRIBUTION_GAUSSIAN_RANGE);
    
    double width = rand->get(0.0, 1.0/12, 1.0/24);
    
    if (orientation)
    {
        width *= H;
        double top_bound = (H - width) / 2;
        double bot_bound = top_bound + width;
        
        child1 = Rectangle(this->p1, W, top_bound);
        child2 = Rectangle(this->p1 + Point(0, bot_bound), W, top_bound);
        
        return Rectangle(this->p1 + Point(0, top_bound), W, width);
    }
    else
    {
        width *= W;
        double top_bound = (W - width) / 2;
        double bot_bound = top_bound + width;
        
        child1 = Rectangle(this->p1, top_bound, H);
        child2 = Rectangle(this->p1 + Point(bot_bound, 0), top_bound, H);
        
        return Rectangle(this->p1 + Point(top_bound, 0), width, H);
    }
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rect)
{
    os << "Rectangle[" << rect.p1 << " -> " << rect.p2 << "]";
    return os;
}
