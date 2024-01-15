#pragma once

#include <vector>
#include "BaseCounter.h"
#include "StoveCounter.h"
#include "EntityManager.h"
#include "Player.h"
#include "ofMain.h"

class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        int ticks=0;
        std::vector<ofImage> people;
        int money =0;
        std::vector<ofImage> decorations;
        int ranInspector;
    public:
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        ofImage floor;
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void generateInspector();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        //Getters
        int getCount() {return entityManager->clientsLeft;}
        int getMoney() {return money;}
        //Setters
        void setCount() { entityManager->setCount(); }
        void setMoney(int a) { this->money = a; }
};
