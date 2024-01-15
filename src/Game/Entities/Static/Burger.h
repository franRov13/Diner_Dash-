#pragma once

#include "Entity.h"
#include "Item.h"

class Burger {
  private:
    int x, y, width, height;
  public:
    Burger(int, int, int, int);
    void addIngredient(Item *item);
    void render();
    void clear();
    void setY(int y) {
        this->y = y;
    }
    void removeLastIngredient();
    /*
    equals() method which checks that the target Burger
    has the same ingredients and quantities as the parameter Burger
    and returns a boolean indicating if they are the same
    */
    bool equals(Burger* other);
    /*
      Made both variables public in order 
      for them to be accessed more easily
    */
    int price;
    vector<Item *> ingredients;

};
