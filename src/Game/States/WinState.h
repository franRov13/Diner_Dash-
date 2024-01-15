#pragma once

#include "State.h"
#include "Restaurant.h"
#include "Button.h"

class WinState: public State{
    public: 
        WinState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
	
	private:
		Button* startButton;
		ofImage winState_img;
};