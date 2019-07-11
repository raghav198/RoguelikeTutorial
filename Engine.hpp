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
#include "EntityManager.hpp"
#include "Map.hpp"
#include "ISystem.hpp"
#include "Rendering.hpp"



#include <string>

class Engine {
    friend class ISystem;
private:
    // std::vector<std::shared_ptr<Entity>> entities;
    std::map<std::string, std::shared_ptr<ISystem>> systems;
    
    Map map;
	EntityManager entities;
    
    std::shared_ptr<ISystem> getSystem(std::string);
    void createSystem(std::string, std::shared_ptr<ISystem>);
    
    void setupMap();
	void setupEntities();
    void setupSystems();
    void setupConsole();
    
public:
    std::shared_ptr<Entity> player;
    void frame();
    bool running;
	bool locIsBlocked(int, int);
    void publish(Message);
    Tile getTileAt(int, int);
    TCODConsole * mapArea;
    void recomputeFOV()
    {
        map.recomputeFOV(player->x, player->y);
    }
    void addEntity(std::shared_ptr<Entity> e)
    {
        // this->entities.push_back(e);
		this->entities.addEntity(e);
    }
    void setup()
    {
        setupMap();
		setupEntities();
        setupSystems();
        setupConsole();
        running = true;
    }
    void drawMap() { recomputeFOV(); map.draw(mapArea, entities); }
};

#endif /* Engine_hpp */
