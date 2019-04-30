/*
 * PlayerAISwarm.cpp
 *
 *  Created on: 28 Mar 2019
 *      Author: PatrickC
 */

#include <algorithm>
#include <PlayerAISwarm.h>

PlayerAISwarm::PlayerAISwarm() {
	for (int i = 0; i < 500; i++) {
		playerSet.push_back(new PlayerAI());
	}

}

PlayerAISwarm::~PlayerAISwarm() {
	// TODO Auto-generated destructor stub
}

void PlayerAISwarm::evaluateCost() {
	std::vector<int> costs;

	std::sort(playerSet.begin(), playerSet.end());

	for (int i = 0; i < playerSet.size() - 1; i++) {
		playerSet.push_back(new PlayerAI(playerSet[i], playerSet[i + 1]));
	}
}

