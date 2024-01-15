#include "Restaurant.h"



Player *Restaurant::getPlayer() { return player; }
void Restaurant::setPlayer(Player *player) { this->player = player; }

Restaurant::Restaurant() {
    floor.load("images/floor.jpg");
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);    
    initItems();
    initCounters();
    initClients();
    generateClient();

    //Phase1(warmup)_task#1 
    ofImage tables, gameMachine, jukebox;
    tables.load("images/benches.png");
    decorations.push_back(tables);
    gameMachine.load("images/Aracde.png");
    decorations.push_back(gameMachine);
    jukebox.load("images/Jukebox.png");
    decorations.push_back(jukebox);

}
void Restaurant::initItems(){
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate

    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");
}
void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224,12,32,43);//stoveTop
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    emptyCounterImg.cropFrom(counterSheet,0,245,30,43);//Empty
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity( new BaseCounter(counterWidth,yOffset-7, counterWidth,108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth*2,yOffset, counterWidth, 102, burger, stoveCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*4,yOffset, counterWidth, 102, nullptr, emptyCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset -10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg));

}
void Restaurant::initClients(){
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);

    // Added Inspector Image.
    temp.load("images/People/Doctor2Female.png");
    people.push_back(temp);
}
void Restaurant::tick() {
    ticks++;
    if(ticks % 1000 == 0){
        // Inspector has a 1 out of 5 chance to pop up in restaurant.
        ranInspector = ofRandom(1, 5);
        if(ranInspector == 2)
        {
            generateInspector();
        }
        else
        {
            generateClient();
        }
    }
    player->tick();
    entityManager->tick();

    // If the bool "inspector" (which checks if the inspector is the client leaving) is true.
    if (entityManager->inspector == true)
    {
        // Earnings are halved by 2.
        this->money /= 2;
        // Bool "inspector" is assigned false again.
        entityManager->inspector = false;
    }
}


void Restaurant::generateClient(){
    Burger* b = new Burger(72, 100, 50, 25);
    // Adds bottom bread to clients burger
    b->addIngredient(botBread);
    // Creates a boolean that picks a random number of ingredients from 1 to 4
    int numIngredients = ofRandom(1, 4);
    // Loops through the number of ingredients
    for(int i = 0; i < numIngredients; i++) {
        // Switch that uses 4 cases to pick random ingredients
        switch ((int)ofRandom(4)) {
            case 0:
                b->addIngredient(burger);
                break;
            case 1:
                b->addIngredient(cheese);
                break;
            case 2:
                b->addIngredient(tomato);
                break;
            case 3:
                b->addIngredient(lettuce);
        }
    }
    // Adds top bread to clients burger
    b->addIngredient(topBread);
    entityManager->addClient(new Client(0, 50, 64, 72,people[ofRandom(7)], b));
}

void Restaurant::generateInspector(){
    Burger* insBurger = new Burger(72, 100, 50, 25);
    insBurger->addIngredient(botBread);
    int numIngredients = ofRandom(1, 4);
    for(int i = 0; i < numIngredients; i++) {
        switch ((int)ofRandom(4)) {
            case 0:
                insBurger->addIngredient(burger);
                break;
            case 1:
                insBurger->addIngredient(cheese);
                break;
            case 2:
                insBurger->addIngredient(tomato);
                break;
            case 3:
                insBurger->addIngredient(lettuce);
        }
    }
    insBurger->addIngredient(topBread);
    entityManager->addInspector(new Inspector(0, 50, 64, 72, people[8], insBurger));
}

void Restaurant::render() {
    floor.draw(0,0, ofGetWidth(), ofGetHeight());
    player->render();
    entityManager->render();
    ofSetColor(255, 0, 0);
    ofDrawBitmapString("Money: " + to_string(money), ofGetWidth()/2, 10);
    ofSetColor(256, 256, 256);
    //Decorations being drawn
    //Draws 4 tables in the middle of the screen
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 2; col++)
        {
            decorations[0].draw(250 + (col * 250), 50 + (row * 100), 100, 100);
        }
    }
    //Draws 2 arcade machines in the game
    for (int i = 0; i < 2; i++)
    {
        decorations[1].draw(650, 175 + (i * 100), 100, 100);
    }
    //Draws 1 jukebox in the middle for some fun
    decorations[2].draw(375, 50, 100, 100);

}
void Restaurant::serveClient(){
    if(entityManager->firstClient!= nullptr){
        money += entityManager->firstClient->serve(player->getBurger());
        // Clears burger if client was served.
        player->getBurger()->clear();
        //Line below simply reassures that the money is never below zero
        if (money < 0) { money = 0; }
    }
    else
    {
        // Clears burger if client is not served.
        player->getBurger()->clear();
    }
}
void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    if(key == 's'){
        serveClient();
    }
    //Pressing the 'e' key to add an ingredient will cost the chef
    //  1$ per ingredient
    if (key == 'e')
    {
        money --;
    }
}
