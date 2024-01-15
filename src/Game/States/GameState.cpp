#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}
void GameState::tick() {
	restaurant->tick();
	//Player has won the game (WinState)
	// If the money reaches 100:
	if (restaurant->getMoney() >= 100)
	{
		// The state is changed to WinState and it resets the counters and money.
		setNextState("Win");
		setFinished(true);
		restaurant->setMoney(0);
		restaurant->setCount();
		this->restaurant = new Restaurant();
	}
	//Player has lost the game (LoseState)
	// If the count of clients that left because of patience is 10:
	if (restaurant->getCount() == 10) 
	{
		// The state is changed to LoseState and it resets the counters and money.
		setNextState("Lose");
		setFinished(true);
		restaurant->setMoney(0);
		restaurant->setCount();
		this->restaurant = new Restaurant();
	}
}
void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	setFinished(false);
	setNextState("Game");
}