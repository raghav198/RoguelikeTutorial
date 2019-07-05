//
//  Rendering.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/27/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef Rendering_hpp
#define Rendering_hpp

#include "Map.hpp"
#include "Point.hpp"
#include <libtcod.hpp>
#include <memory>

// The raw pointer here is okay because we are guaranteed to not mess with it
// And it makes passing TCODConsole::root easier (don't want to manage that since TCOD manages it)
void DrawMap(TCODConsole *, Map, Point);


#endif /* Rendering_hpp */
