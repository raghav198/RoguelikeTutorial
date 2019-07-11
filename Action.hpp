//
//  Action.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/19/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

//#ifndef Action_hpp
//#define Action_hpp

#pragma once

#include "Point.hpp"

enum ActionType {
    MOVE,
    ATTACK,
    CAST,
    SYSTEM
};
enum SystemAction {
    FULLSCREEN,
    EXIT
};

struct Action {
    ActionType type;
    union {
        Point loc;
        SystemAction action;
    };
    Action(ActionType type, Point loc) : type(type), loc(loc) {}
    Action(ActionType type, SystemAction action) : type(type), action(action) {}
};

//#endif /* Action_hpp */
