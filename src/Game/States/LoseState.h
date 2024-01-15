#pragma once

#include "State.h"
#include "Restaurant.h"
#include "Button.h"

class LoseState: public State{
    public: 
        LoseState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
	
	private:
		ofImage loseState_img;
		Button *startButton;
};