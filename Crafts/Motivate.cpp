/*
 * Motivate.cpp
 *
 *  Created on: 17 Feb 2019
 *      Author: PatrickC
 */

#include "Motivate.h"
//#include "StatBuff.h"

const std::string Motivate::name = "Motivate";
const int Motivate::craftPoints = 30;
const int Motivate::AoESize = 4;
const int Motivate::unbalance = 0;
const Targetting Motivate::targetting = 5;

void Motivate::displayHitDescription(Entity* hitter, Entity* hittee, int dmg) {
	std::cout << hitter->getName() << " screamed some motivational things at "
			<< hittee->getName() << ".\n\nThis filled " << hittee->getName()
			<< " with determination.\n";
	std::cout << hittee->getName() << " gained +10 CP and 25% STR!";
}

//May automate this when buff class is made
void Motivate::displaySpecificCraftDescription() {
	std::cout << "STR +25%, CP +10.";
}

void Motivate::craftOnHitFunctions(Entity* entity) {
	giveCP(entity);
}

void Motivate::STRbuff(Entity* character) {
	//character->applyStatBuff(new StatBuff(3, {0,0,character->getSTR() * 0.25,0,0,0,0,0,0,0,0}));
}

int Motivate::getBaseDamage() {
	return 0;
}

