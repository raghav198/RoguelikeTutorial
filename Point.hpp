//
//  Point.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/19/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include<iostream>

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    Point operator-(Point other) {
        return Point(this->x - other.x, this->y - other.y);
    }
    Point operator+(Point other) {
        return Point(this->x + other.x, this->y + other.y);
    }
    
    Point operator*(float scale) {
        return Point(this->x * scale, this->y * scale);
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
    
    friend bool operator==(Point a, Point b) {
        return a.x == b.x && a.y == b.y;
    }
    
    friend bool operator!=(Point a, Point b) {
        return a.x != b.x || a.y != b.y;
    }
};

#endif /* Point_hpp */
