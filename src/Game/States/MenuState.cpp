#include "MenuState.h"

MenuState::MenuState() {
	string text = "Start";
	startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, "Start");
}
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void MenuState::render() {
	ofSetBackgroundColor(230, 230, 250);
	startButton->render();
	//Phase1_task#2
	/*
	Implement a start screen which displays the game instructions. The basic
	instructions are that you pickup ingredients by pressing ‘e’ when the player is in front
	of the counter and you serve clients with ‘s’. Any other functionalities or special
	instructions should be added as implemented.
	*/
	ofSetColor(0);
	ofDrawBitmapString("Game instructions: ", (ofGetWidth()/2) - 400, (ofGetHeight()/2) + 200);		ofDrawBitmapString("Press [e] to pickup ingredients", (ofGetWidth()/2) - 395, (ofGetHeight()/2) + 220);
	ofDrawBitmapString("Press [s] serve clients", (ofGetWidth()/2) - 395, (ofGetHeight()/2) + 240);
	ofDrawBitmapString("Press [u] to delete/undo the last added ingredient", (ofGetWidth()/2) - 395, (ofGetHeight()/2) + 260);
	ofDrawBitmapString("Use the [left & right arrow keys] to move the chef from left to right respectevely.", (ofGetWidth()/2) - 395, (ofGetHeight()/2) + 280);

}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}