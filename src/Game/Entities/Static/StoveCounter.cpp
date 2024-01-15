#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite) : BaseCounter(x, y, width, height, item, sprite)
{
    counterType = counterClass::stoveCounter;
    //Sets the time it takes to cook the burger on the stove
    this->timeToTake = (5 * ofGetFrameRate());
    //Keeps track of how long the item was cooking
    ticks = 0;
    //Sets the initial state of the stove
    isCooking = false;
    isCooked = false;
}

void StoveCounter::tick()
{
    //If the stove is cooking a burger, increment the tick counter
    if (isCooking)
    {
        ticks++;
    }
    //If the item is cooked, stop cooking
    if (ticks == timeToTake)
    {
        isCooked = true;
        isCooking = false;
    }
}

void StoveCounter::render()
{
    //Draws the base counter sprite
    BaseCounter::render();
    //If the stove is cooking an item, this section draws the progress bar
    if (isCooking)
    {
        // Calculate how much of the progress bar should be filled in based on how long the burger has been cooking
        float time = (1.0 * ticks / timeToTake);
        float wRect = (76 * time);
        //Draws the background of the progress bar 
        ofSetColor(0, 0, 0);
        ofDrawRectangle(x + 10, y + (height / 2), 76, 10);
        //Draws the filled in part of the progress bar
        ofSetColor(255, 255, 255);
        ofDrawRectangle(x + 10, y + (height / 2), wRect, 10);
        //Resets the color of the progress bar
        ofSetColor(255, 255, 255);
    }
    //When the burger is cooked, draws a green rectangle over the progress bar to indicate it's done
    if (isCooked)
    {
        ofSetColor(0, 255, 0);
        ofDrawRectangle(x + 10, y + height / 2, 76, 10);
    }
}

bool StoveCounter::itemIsCooking()
{
    return isCooking;
}

bool StoveCounter::itemCooked()
{
    return isCooked;
}
//Starts cooking the burger on the stove
void StoveCounter::startCooking()
{
    isCooking = true;
    isCooked = false;
}
// Stops cooking the burger and resets the stove to its initial state
void StoveCounter::clear()
{
    isCooking = false;
    isCooked = false;
    ticks = 0;
}