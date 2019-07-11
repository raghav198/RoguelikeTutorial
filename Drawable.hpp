//
//  Drawable.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 7/5/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef Drawable_hpp
#define Drawable_hpp

#include "Component.hpp"
// #include "Engine.hpp"
#include <libtcod.hpp>

extern Engine * world;

class Drawable : public Component {
private:
    char display;
	bool transparent;
    TCODColor foreground;
    TCODColor background;
public:
    Drawable(std::shared_ptr<Entity> e, char d, TCODColor f, TCODColor b) :
		Component(e), display(d), foreground(f), background(b), transparent(false) {}
	Drawable(std::shared_ptr<Entity> e, char d, TCODColor f) : 
		Component(e), display(d), foreground(f), background(0, 0, 0), transparent(true) {}
    void draw(TCODConsole * con, int x, int y)
    {
		if (transparent);
			// con->putCharEx(x, y, display, foreground, world->getTileAt(x, y).background);
		else
			con->putCharEx(x, y, display, foreground, background);
    }
};

#endif /* Drawable_hpp */
