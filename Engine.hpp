//
//  Engine.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/28/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef Engine_hpp
#define Engine_hpp

#include <libtcod.hpp>
#include <memory>
#include <map>

#include "Entity.hpp"
#include "Map.hpp"
#include "ISystem.hpp"



#include <string>

class Engine {
    friend class ISystem;
private:
    std::vector<std::shared_ptr<Entity>> entities;
    std::map<std::string, std::shared_ptr<ISystem>> systems;
    
    Map map;
    
    std::shared_ptr<ISystem> getSystem(std::string);
    void createSystem(std::string, std::shared_ptr<ISystem>);
    
    void setupMap();
    void setupSystems();
    void setupConsole();
    
public:
    std::shared_ptr<Entity> player;
    void frame();
    bool running;
    void publish(Message);
    Tile getTileAt(int, int);
    void recomputeFOV()
    {
        map.recomputeFOV(player->x, player->y);
    }
    void addEntity(std::shared_ptr<Entity> e)
    {
        this->entities.push_back(e);
    }
    void setup()
    {
        setupMap();
        setupSystems();
        setupConsole();
        running = true;
    }
};

#endif /* Engine_hpp */
