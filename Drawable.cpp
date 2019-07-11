//
//  Drawable.cpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 7/10/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#include "Drawable.hpp"
#include "Engine.hpp"

extern Engine * world;

void Drawable::draw(TCODConsole * con, int x, int y)
{
    if (transparent)
       con->putCharEx(x, y, display, foreground, world->getTileAt(x, y).background);
    else
        con->putCharEx(x, y, display, foreground, background);
    }
