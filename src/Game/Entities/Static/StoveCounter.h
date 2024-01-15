#pragma once
#include "BaseCounter.h"

class StoveCounter : public BaseCounter
{
    private:
        //subject to change
        int ticks, timeToTake;  
        bool isCooking, isCooked;
    public:
        StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
        void tick();
        void startCooking();
        void render();
        void clear();
        bool itemCooked();
        bool itemIsCooking();
};