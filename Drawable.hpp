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
#include <libtcod.hpp>

class Drawable : public Component {
private:
    char display;
    TCODColor foreground;
    TCODColor background;
public:
    Drawable(std::shared_ptr<Entity> e, char d, TCODColor f, TCODColor b) : Component(e), display(d), foreground(f), background(b) {}
    void draw(TCODConsole * con, int x, int y)
    {
        con->putCharEx(x, y, display, foreground, background);
    }
};

#endif /* Drawable_hpp */
