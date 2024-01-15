#pragma once

#include "Entity.h"
#include "Client.h"
#include "Inspector.h"

class EntityManager {

public:
	Client* firstClient;
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeLeavingClients();
	void addInspector(Inspector *inspector);
	std::vector<Entity*> entities;
	int clientsLeft{};
	//Setters
	void setCount(){ this->clientsLeft = {};}
	// Bool to check if inspector isLeaving because of patience.
	bool inspector;

};