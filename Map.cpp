//
//  Map.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/26/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "Map.hpp"
#include "Rectangle.hpp"
#include "Point.hpp"
#include "Engine.hpp"

extern Engine * world;

template <class T>
void initMatrix(int x, int y, matrix<T>& mat)
{
    for (int i = 0; i < x; i++)
        mat.push_back(std::vector<T>(y));
}

Map::Map(int x, int y)
{
    x++;
    y++;
    initMatrix(x, y, this->explored);
    initMatrix(x, y, this->visible);
    initMatrix(x, y, this->grid);
    this->_map = new TCODMap(x, y);
}

void Map::placeComponent(Rectangle rect, Place placeType)
{
    Tile t;
    if (placeType == Place::Wall)
        t = Tile::WALL();
    else if (placeType == Place::GlassWall)
        t = Tile::GRASS();

    for (Point p : rect)
    {
        setTile(p.x, p.y, t);
//        this->grid[p.x][p.y] = t;
    }
}

void Map::place(Rectangle rect, Shape shape, Tile tile)
{
    if (shape == Shape::FilledRect)
    {
        for (Point p : rect)
            setTile(p.x, p.y, tile);
//            grid[p.x][p.y] = tile;
    }
    else if (shape == Shape::OpenRect || shape == Shape::BrokenRect)
    {
        // horizontal lines
        for (int x = rect.p1.x; x <= rect.p2.x; x++)
        {
            setTile(x, rect.p1.y, tile);
            setTile(x, rect.p2.y, tile);
//            grid[x][rect.p1.y] = tile;
//            grid[x][rect.p2.y] = tile;
        }
        
        // vertical lines
        for (int y = rect.p1.y; y <= rect.p2.y; y++)
        {
            setTile(rect.p1.x, y, tile);
            setTile(rect.p2.x, y, tile);
//            grid[rect.p1.x][y] = tile;
//            grid[rect.p2.x][y] = tile;
        }
    }
}

void Map::placeBroken(Rectangle rect, Tile tile, float breaks)
{
    TCODRandom * rand = TCODRandom::getInstance();
    for (int x = rect.p1.x; x <= rect.p2.x; x++)
    {
        if (rand->getDouble(0, 1) < breaks) grid[x][rect.p1.y] = tile;
        if (rand->getDouble(0, 1) < breaks) grid[x][rect.p2.y] = tile;
    }
    
    for (int y = rect.p1.y; y <= rect.p2.y; y++)
    {
        if (rand->getDouble(0, 1) < breaks) grid[rect.p1.x][y] = tile;
        if (rand->getDouble(0, 1) < breaks) grid[rect.p2.x][y] = tile;
    }
}

void Map::dig(Point start, Point finish, Tile tile)
{
    TCODRandom * rand = TCODRandom::getInstance();
    Point cur = start;
    while (cur != finish)
    {
        bool horiz = rand->get(0.0, 1.0) < 0.5;
        int length = rand->get(0, (horiz ? abs(finish.x - cur.x) : abs(finish.y - cur.y)));
        int direction = (horiz ? finish.x : finish.y) > (horiz ? cur.x : cur.y) ? 1 : -1;
        for (int i = 0; i < length; i++)
        {
            setTile(cur.x, cur.y, tile);
//            grid[cur.x][cur.y] = tile;
            if (horiz) cur.x += direction;
            else cur.y += direction;
        }
    }
}

Tile Map::getTileAt(int x, int y)
{
    /*if (this->moveBlock[x][y])
    {
        if (this->losBlock[x][y])
            return Tile::WALL();
        return Tile::GRASS();
    }
    return Tile::ROAD();*/
    return grid[x][y];
}


void Map::draw(TCODConsole * con, EntityManager entities)
{
    const int width = con->getWidth();
    const int height = con->getHeight();
    
//    std::shared_ptr<Entity> player = entities[0];
    std::shared_ptr<Entity> player = world->player;
    
    con->clear();
    int xShift = std::max(player->loc.x - width / 2, 0);
    int yShift = std::max(player->loc.y - height / 2, 0);
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            // the point (px, py) on the console should come from point (width/2, height/2)
            // so (x, y) --> (x - width/2 + px)
            
            Tile t = grid[x + xShift][y + yShift];
            if (_map->isInFov(x + xShift, y + yShift))
            {
                con->putCharEx(x, y, t.x, t.foreground, t.background);
                explored[x + xShift][y + yShift] = true;
            }
            else if (explored[x + xShift][y + yShift])
                con->putCharEx(x, y, t.x, t.foreground * 0.5, t.background * 0.5);
        }
    }
    
    for (std::shared_ptr<Entity> entity : entities)
    {
        if (entity->drawable == nullptr) continue;
        if (_map->isInFov(entity->loc.x, entity->loc.y))
            entity->drawable->draw(con, entity->loc.x - xShift, entity->loc.y - yShift);
    }
    con->flush();
}
