//
//  Rectangle.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/25/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include "Point.hpp"
#include <iterator>


class RectangleIterator : public std::iterator<std::forward_iterator_tag, Point*>
{
    Point cur;
    Point orig;
    Point shape;
public:
    RectangleIterator(Point cur, Point shape) : orig(cur), cur(cur), shape(shape) {}
    RectangleIterator(const RectangleIterator& itr) : RectangleIterator(itr.cur, itr.shape) {}
    
    RectangleIterator& operator++()
    {
        if (cur.x == orig.x + shape.x)
        {
            cur.x = orig.x;
            cur.y++;
        }
        else
        {
            cur.x++;
        }
        return *this;
    }
    bool operator==(const RectangleIterator& rhs)
    {
        return rhs.cur.x == this->cur.x && rhs.cur.y == this->cur.y;
    }
    bool operator!=(const RectangleIterator& rhs)
    {
        return rhs.cur.x != this->cur.x || rhs.cur.y != this->cur.y;
    }
    Point operator*()
    {
        return this->cur;
    }
};

struct Rectangle {
    Point p1, p2;
    bool filled = true;
    
    Rectangle(int x, int y, int w, int h) : p1(x, y), p2(x + w, y + h) {};
    Rectangle(Point p1, Point p2) : p1(p1), p2(p2) {};
    Rectangle(Point c, int w, int h) : p1(c), p2(c + Point(w, h)) {};
    Rectangle() : p1(0, 0), p2(0, 0) {}
    
    Point shape();
    Point center();
    Rectangle trisect(bool, Rectangle&, Rectangle&);
    
    friend std::ostream& operator<<(std::ostream&, const Rectangle&);
    RectangleIterator begin()
    {
        return RectangleIterator(this->p1, this->shape());
    }
    
    RectangleIterator end()
    {
        return RectangleIterator(Point(this->p1.x, this->p2.y + 1), this->shape());
    }
};
