//
//  Abilities.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/23/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef Abilities_hpp
#define Abilities_hpp

class Ability {
public:
    virtual int perform() = 0;
    virtual int weight() = 0;
};

#endif /* Abilities_hpp */
