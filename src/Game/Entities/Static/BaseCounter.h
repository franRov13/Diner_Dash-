#pragma once

#include "Item.h"
#include "Entity.h"

enum counterClass
{
    normCounter,
    stoveCounter
};

class BaseCounter: public Entity {
    private:
        Item *item;

    public:
        BaseCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
        Item* getItem();
        void showItem();

        counterClass counterType;
        counterClass getCounterType();

};
