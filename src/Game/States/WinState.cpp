#include "WinState.h"


// This creates the visuals and deals with some logic for the win state.

WinState::WinState() {
	startButton = new Button(ofGetWidth() / 2, ofGetHeight() / 2, 64, 50, "Try Again!");
	winState_img.load("images/winState.png");
}
void WinState::tick() {
	startButton->tick();
	if (startButton->wasPressed())
	{
		setNextState("Game");
		setFinished(true);
	}
	
}
void WinState::render() {
	ofSetColor(255, 255, 255);
	winState_img.draw(0, 0, ofGetWidth(), ofGetHeight());
	startButton->render();
}

void WinState::keyPressed(int key){

}

void WinState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void WinState::keyReleased(int key){
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}