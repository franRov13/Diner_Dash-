#include "BaseCounter.h"

BaseCounter::BaseCounter(int x, int y, int width, int height,Item* item, ofImage sprite) : Entity(x, y, width, height, sprite){
    this->item = item;
    counterType = counterClass::normCounter;
}

Item* BaseCounter::getItem(){
    return item;
}

void BaseCounter::showItem(){
    if (item != nullptr){
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
}

counterClass BaseCounter::getCounterType()
{
    return counterType;
}
