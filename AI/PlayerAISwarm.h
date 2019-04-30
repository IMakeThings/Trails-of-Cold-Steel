/*
 * PlayerAISwarm.h
 *
 *  Created on: 28 Mar 2019
 *      Author: PatrickC
 */

#ifndef PLAYERAISWARM_H_
#define PLAYERAISWARM_H_
#include "PlayerAI.h"

class PlayerAISwarm {
	std::vector<PlayerAI*> playerSet;
public:
	PlayerAISwarm();
	virtual ~PlayerAISwarm();

	void evaluateCost();

	std::vector<PlayerAI*> getPlayerSet() {
		return playerSet;
	}
};

#endif /* PLAYERAISWARM_H_ */
