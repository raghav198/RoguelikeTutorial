//
//  Map.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/26/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include<vector>
#include <libtcod.hpp>

#include "Rectangle.hpp"
#include "Entity.hpp"
#include "EntityManager.hpp"

template <class T>
using matrix = std::vector<std::vector<T>>;

enum Place {
    Wall,
    GlassWall,
    Block,
    GlassBlock,
    Floor
};

enum Shape {
    FilledRect,
    OpenRect,
    BrokenRect
};

struct Tile {
    char x;
    bool blocked = false;
    bool losBlocked = false;
    TCODColor foreground = TCODColor::white;
    TCODColor background = TCODColor::black;
    static Tile const & WALL()
    {
        static Tile _wall(' ');
        _wall.blocked = true;
        _wall.losBlocked = true;
        _wall.background = TCODColor::brass;
        return _wall;
    }
    static Tile const & ROAD()
    {
        static Tile _road(' ');
        _road.background = TCODColor::darkGrey;
        return _road;
    }
    static Tile const & GRASS()
    {
        static Tile _grass('"');
        _grass.foreground = TCODColor::darkGreen;
        return _grass;
    }
    static Tile const & FLOOR()
    {
        static Tile _floor(':');
        _floor.foreground = TCODColor::darkBlue;
        return _floor;
    }
    static Tile const & ROAT()
    {
        static Tile _road(' ');
        _road.background = TCODColor::darkGrey;
        return _road;
    }

    Tile() : x(' ') {}
    Tile(char x) : x(x) {}
};


class Map {
private:
    matrix<bool> explored;
    matrix<bool> visible;
    matrix<Tile> grid;
    
    TCODMap * _map;

public:
    Map(int, int);
    Map() {}
    
    void setTile(int x, int y, Tile tile)
    {
        grid[x][y] = tile;
        _map->setProperties(x, y, !tile.losBlocked, !tile.blocked);
    }
    
    void recomputeFOV(int x, int y)
    {
        _map->computeFov(x, y, 15, true, FOV_PERMISSIVE_8);
    }
    
    void placeComponent(Rectangle, Place);
    void place(Rectangle, Shape, Tile);
    void placeBroken(Rectangle, Tile, float);
    void dig(Point, Point, Tile);
    Tile getTileAt(int, int);
    void draw(TCODConsole *, EntityManager);
};

#endif /* Map_hpp */
