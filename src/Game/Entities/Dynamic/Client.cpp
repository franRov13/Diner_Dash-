#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
    this->originalPatience = patience;  //Initializes/stores the original patience value
}
Client::~Client(){
    delete burger;
}
void Client::render(){
    //Phase1_Task#2 (Clients slowly turn red as they lose their patience)
    if(patience <=originalPatience*0.75 && patience > originalPatience*0.5)
    {
        /*
        If the clients patience is <= 75% if their initial patience, but greater than 
        50% of their initial patience. This line sets the client's color to a bright
        red
        */
        ofSetColor(255, 0, 0);
    }else if(patience <= originalPatience*0.5 && patience > originalPatience*0.25)
    {
        /*
        If the clients patience is <= 50% if their initial patience, but greater than 
        25% of their initial patience. This line sets the client's color to a 
        slightly darker shade of red
        */
        ofSetColor(213, 0, 0);
    }else if(patience <=originalPatience*0.25 && patience > 0)
    {
        /*
        If the clients patience is <= 25% if their initial patience, but greater than 
        0 of their initial patience. This line sets the client's color to an
        even darker shade of red
        */
        ofSetColor(170, 0, 0);
    }
    
    sprite.draw(x, y, width, height);
    ofSetColor (255,255,255);
    burger->render();
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    burger->setY(y);
    if(patience == 0){
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger){
    int totalPrice = 0;
    /*
    This loop checks for every ingredient in the client's burger,
    adding the cost for each ingredient to the totalPrice variable.
    */
    for (auto& ingredient : burger->ingredients)
    {
        if (ingredient->getName() == "cheese")
        {
            totalPrice += 3;
        }else if (ingredient->getName() == "lettuce" || ingredient->getName() == "tomato")
        {
            totalPrice += 2;
        }else if (ingredient->getName() == "patty")
        {
            totalPrice += 4;
        }
    }
    //Top and bottom bun prices.
    totalPrice += 2;
    
    //Sets the price of the client's burger to the totalPrice calculated.
    burger->price = totalPrice; 
    
    //If both burgers are the same:
    if (this->burger->equals(burger)) 
    { 
        //The client is marked as leaving and it's charged with the corresponding price.
        isLeaving = true;   
        return totalPrice; 
    } 
    //If the next client exists:
    else if (nextClient != nullptr) 
    {
        //It will serve the client.
        return nextClient->serve(burger);
    } 
    else 
    {
        // Return $0 since no burger was served.
        return 0;
    }
}