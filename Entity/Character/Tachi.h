/*
 * Tachi.h
 *
 *  Created on: 11 Feb 2019
 *      Author: PatrickC
 */
#include "Character.h"
#include "AutumnLeafCutter.h"
#include "Motivate.h"

#ifndef TACHI_H_
#define TACHI_H_

class Tachi: public Character {
	static const Stats baseStats;
	static const AttackRanks ranks;
	static const std::string representation;
	static int count;

public:
	Tachi(std::string n, Position position);
	Tachi(std::string n, Position position, PlayerAI* p);
	int getAttackModifier();
	int getArtModifier();
};

#endif /* TACHI_H_ */
