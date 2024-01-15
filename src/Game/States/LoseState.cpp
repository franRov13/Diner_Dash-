#include "LoseState.h"


// This file creates the visuals and deals with some logic for the lose state.

LoseState::LoseState() {
	startButton = new Button(ofGetWidth() / 2, ofGetHeight() / 2, 64, 50, "Try Again!");
	loseState_img.load("images/loseState.png");
    
}
void LoseState::tick() {
	startButton->tick();
	if (startButton->wasPressed())
	{
		setNextState("Game");
		setFinished(true);
	}
}
void LoseState::render() {
	ofSetColor(255, 255, 255);
	loseState_img.draw(0, 0, ofGetWidth(), ofGetHeight());
	startButton->render();
}

void LoseState::keyPressed(int key){

}

void LoseState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void LoseState::keyReleased(int key){
}

void LoseState::reset(){
	setFinished(false);
	setNextState("");
	startButton->render();
}