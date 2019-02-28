/*
 * Greatsword.h
 *
 *  Created on: 17 Feb 2019
 *      Author: PatrickC
 */
#include "Character.h"

#ifndef GREATSWORD_H_
#define GREATSWORD_H_

class Greatsword:public Character {
	static const Stats baseStats;
	static const AttackRanks ranks;
	static const std::string representation;
	static int count;

public:
	Greatsword(std::string n, Position position);

	int getAttackModifier();
	int getArtModifier();
};



#endif /* GREATSWORD_H_ */
