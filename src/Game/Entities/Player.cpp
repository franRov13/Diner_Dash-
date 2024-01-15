#include "Player.h"

Player::Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em) : Entity(x, y, width, height, sprite){

    vector<ofImage> chefAnimframes;
    ofImage temp;
    this->burger = new Burger(ofGetWidth()-110, 100, 100, 50);
    temp.cropFrom(sprite, 30,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 159,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 287, 3,67,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 31,129,66,120);
    chefAnimframes.push_back(temp);
    this->chefAnim = new Animation(50, chefAnimframes);
    this->entityManager = em;
    
}
void Player::tick(){
    chefAnim->tick();
    
    //Phase2_Task#4
    /*
    If the left arrow key or right arrow key are pressed,
    the facing value and speed is adjusted accordingly.
    */
    if (ofGetKeyPressed(OF_KEY_LEFT))
    {
        facing = "left";
        x-=speed;        
    }else if (ofGetKeyPressed(OF_KEY_RIGHT))
    {
        facing = "right";
        x+=speed;       
    }
    
    // The code below checks if the player's x-coordinate is out of bounds.
    if (x <= 0)
    {
        x = 0;
    }else if (x + width >= ofGetWidth())
    {
        x = (ofGetWidth() - width);
    }
}

void Player::render(){
    BaseCounter *ac = getActiveCounter();
    if (ac != nullptr) {
        ac->showItem();
    }
    ofSetColor(256, 256, 256);
    ofImage currentFrame = chefAnim->getCurrentFrame();
    if (facing == "left") {
        currentFrame.mirror(false, true);
    }
    currentFrame.draw(x, y, width, height);
    burger->render();
}

void Player::keyPressed(int key){
    if(key == 'e'){
        // Checking if the player is standing on a stove counter and adding the cooked item to the burger if one is present.
        BaseCounter* ac = getActiveCounter();
        if(ac != nullptr){
            if (ac->getCounterType() == counterClass::stoveCounter)
            {
                StoveCounter *stoveCounter = (StoveCounter *)ac;
                if (stoveCounter->itemCooked())
                {
                    Item* item = stoveCounter->getItem();
                    burger->addIngredient(item);
                    stoveCounter->clear();
                }else
                {
                    if (!stoveCounter->itemIsCooking())
                    {
                        stoveCounter->startCooking();
                    }
                }
            }
            // Adding the item associated
            else
            {
                Item* item = ac->getItem();
                if(item != nullptr)
                {
                    burger->addIngredient(item);
                }
            }
        }
    // The 'u' key activates de undo feature.
    } else if(key == 'u') {
        burger->removeLastIngredient();  
}
}
BaseCounter* Player::getActiveCounter(){
    for(Entity* e:entityManager->entities){
        BaseCounter* c = dynamic_cast<BaseCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}

void Player::keyReleased(int key) {
}
void Player::mousePressed(int x, int y, int button) {
}

void Player::setFacing(string facing){ this->facing = facing; }