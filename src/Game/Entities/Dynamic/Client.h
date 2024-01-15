#pragma once

#include "Entity.h"
#include "Burger.h"

class Client: public Entity{
    private:
        Burger* burger;
        int originalPatience;
        int patience = 6000;
        
    public:
        Client(int, int, int, int, ofImage, Burger*);
        virtual ~Client();
        void tick();
        void render();
        int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;
        int getPatience() {return patience;}


};