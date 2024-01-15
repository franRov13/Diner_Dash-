#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    ingredients.push_back(item);
}

void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x-5,y-(counter * 10)+55,width*0.70,height*0.70);
        counter++;
    }
}

// Undo feature.
void Burger::removeLastIngredient() {
    
    // Checks if there are ingredients.
    if (!ingredients.empty()) {

        // Deletes the last added ingredient. 
        ingredients.pop_back();
    }
}

void Burger::clear(){
    ingredients.clear();
}

//equals() method implementation
bool Burger::equals(Burger* other) {
    // Check if the two burgers have the same number of ingredients
    if (ingredients.size() != other->ingredients.size()) {
        return false;
    }

    // Create maps to store the ingredients and their quantities for both burgers
    map<string, int> thisIngredients;
    map<string, int> otherIngredients;

    // Loops through the ingredients of this burger and count the quantity of each ingredient
    for (Item* ingredient : ingredients) {
        // Skip top and bottom buns for now
        if (ingredient->getName() == "Top Bun" || ingredient->getName() == "Bottom Bun") {
            continue;
        }
        // Check if the ingredient is already in the map, if yes then increment the quantity by 1, if not add the ingredient with a quantity of 1
        if (thisIngredients.count(ingredient->getName()) > 0) {
            thisIngredients[ingredient->getName()]++;
        } else {
            thisIngredients[ingredient->getName()] = 1;
        }
    }

    // Loops through the ingredients of the other burger and count the quantity of each ingredient
    for (Item* ingredient : other->ingredients) {
        // Skip top and bottom buns for now
        if (ingredient->getName() == "Top Bun" || ingredient->getName() == "Bottom Bun") {
            continue;
        }
        
        // Check if the ingredient is already in the map, if yes then increment the quantity by 1, if not add the ingredient with a quantity of 1
        if (otherIngredients.count(ingredient->getName()) > 0) {
            otherIngredients[ingredient->getName()]++;
        } else {
            otherIngredients[ingredient->getName()] = 1;
        }
    }

    // Check if the ingredients and quantities match, ignoring the order of the ingredients
    for (auto const&[ingredient, quantity] : thisIngredients) {
        // Skip top and bottom buns for now
        if (ingredient == "Top Bun" || ingredient == "Bottom Bun") {
            continue;
        }

        // Check if the ingredient is present in other burger's ingredients and has the same quantity, if not then return false
        if (otherIngredients.count(ingredient) == 0 || otherIngredients[ingredient] != quantity) {
            return false;
        }
    }

    // Check if the top and bottom buns match
    if (ingredients[0]->getName() != other->ingredients[0]->getName() ||
        ingredients[ingredients.size()-1]->getName() != other->ingredients[other->ingredients.size()-1]->getName()) {
        return false;
    }

    return true;
}
