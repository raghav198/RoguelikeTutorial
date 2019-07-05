//
//  Rendering.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/27/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "Rendering.hpp"
#include <libtcod.hpp>
#include "Map.hpp"

void DrawMap(TCODConsole * con, Map map, Point player)
{
    const int width = con->getWidth();
    const int height = con->getHeight();
    
    con->clear();
    int xShift = std::max(player.x - width / 2, 0);
    int yShift = std::max(player.y - height / 2, 0);
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            // the point (px, py) on the console should come from point (width/2, height/2)
            // so (x, y) --> (x - width/2 + px)
            Tile t = map.getTileAt(x + xShift, y + yShift);
            con->putCharEx(x, y, t.x, t.foreground, t.background);
        }
    }
    con->putCharEx(player.x - xShift, player.y - yShift, '@', TCODColor::red, map.getTileAt(player.x, player.y).background);
    con->flush();
}
