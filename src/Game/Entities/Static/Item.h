#pragma once

#include "ofMain.h"

class Item {    
public:
    Item(ofImage, string);
    ofImage sprite;
    string name;
   
   string getName() {return name;}
};
