//
//  Rendering.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/27/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#pragma once

#include "Map.hpp"
#include "Point.hpp"
#include <libtcod.hpp>
#include <memory>

// The raw pointer here is okay because we are guaranteed to not mess with it
// And it makes passing TCODConsole::root easier (don't want to manage that since TCOD manages it)
void DrawMap(TCODConsole *, Map, Point);
