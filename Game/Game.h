/*
 * Game.h
 *
 *  Created on: 26 Jan 2019
 *      Author: PatrickC
 */

#ifndef GAME_H_
#define GAME_H_

#include "Entity.h"
#include "Map.h"

class Game {
	std::vector<Entity*> turnOrder;

public:
	Game();
	virtual ~Game();

	void gameLoop();


	void showMap();



	//Combat stuff
	Entity* nextEntityTurn();

	void initiateCombat();
};

#endif /* GAME_H_ */
