/*
 * Game.cpp
 *
 *  Created on: 26 Jan 2019
 *      Author: PatrickC
 */

#include <iostream>
#include "Weapon.h"
#include "Shoes.h"
#include "Crafts.h"
#include "Quartz.h"
#include "MasterQuartz.h"
#include "Enemy.h"
#include "Map.h"
#include "time.h"
#include "Entity.h"
#include "Character.h"
#include "Game.h"
#include "Dice.h"
#include "Tachi.h"
#include <algorithm>
#include "Armour.h"
#include "ForceLvl1.h"
#include "FlyingFeline.h"
#include <algorithm>
#include "Greatsword.h"
#include "Attack1.h"
extern void enterPause();



using Position = std::array<int, 2>;

bool initiated = false;




Game::Game() {




	Map::generate();
	Map::update();

	srand(time(NULL));

	Tachi* tachi = new Tachi("Tachi", {10,10});

	tachi->addEquipment(new Kazekiri());
	tachi->addEquipment(new LeatherJacket());
	tachi->addEquipment(new LeatherShoes());
	tachi->setMasterQuartz(new Forcelvl1());
	tachi->addQuartz(new Attack1());



	std::string input;
	std::string target;

	(new FlyingFeline({11,9}));
	(new FlyingFeline({11,7}));

	(new FlyingFeline({15,15}));

	//tachi->updateArts_MasterQuartz();
	//tachi->updateStats_Equipment();
	//tachi->updateStats_MasterQuartz();
	//tachi->updateStats_Quartz();


	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	initiateCombat();

	gameLoop();
}


void Game::gameLoop() {
	std::cout << R"(
		░░░░░░░░▄▄▄▀▀▀▄▄███▄░░░░░░░░░░░░░░
		░░░░░▄▀▀░░░░░░░▐░▀██▌░░░░░░░░░░░░░
		░░░▄▀░░░░▄▄███░▌▀▀░▀█░░░░░░░░░░░░░
		░░▄█░░▄▀▀▒▒▒▒▒▄▐░░░░█▌░░░░░░░░░░░░
		░▐█▀▄▀▄▄▄▄▀▀▀▀▌░░░░░▐█▄░░░░░░░░░░░
		░▌▄▄▀▀░░░░░░░░▌░░░░▄███████▄░░░░░░
		░░░░░░░░░░░░░▐░░░░▐███████████▄░░░
		░░░░░le░░░░░░░▐░░░░▐█████████████▄
		░░░░toucan░░░░░░▀▄░░░▐█████████████▄ 
		░░░░░░has░░░░░░░░▀▄▄███████████████ 
		░░░░░arrived░░░░░░░░░░░░█▀██████░░
	)" ;
	std::cout << "\n\n";
	std::string lose;
	std::cout << "When the game begins, you are linked to yourself. It is encouraged to relink on your first turn.\n\nPress enter to continue.";
	getline(std::cin, lose);
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	Map::update();
	Map::display();
	std::cout << "Turn order:\n\n";
	for(int i = 0; i < (signed)turnOrder.size(); i++) {
		std::cout << "(" << i+1 << ")\t" << turnOrder[i]->getName() << "\t(" << turnOrder[i]->getRepresentation() << ")\t" << turnOrder[i]->getPositions()[0]+1 << "-" << turnOrder[i]->getPositions()[1]+1 << std::endl;
	}
	enterPause();
	while(true) {
		nextEntityTurn()->takeTurn();
		std::cout << "Turn order:\n\n";
		for(int i = 0; i < (signed)turnOrder.size(); i++) {
			std::cout << "(" << i+1 << ")\t" << turnOrder[i]->getName() << "\t(" << turnOrder[i]->getRepresentation() << ")\t" << turnOrder[i]->getPositions()[0]+1 << "-" << turnOrder[i]->getPositions()[1]+1 << std::endl;
		}
		enterPause();

		//Killing
		for(int j = Entity::getEntities().size() - 1; j >= 0; j--) {
			if(Entity::getEntities()[j]->getHP() <= 0) {
				for(int i = turnOrder.size()-1; i >= 0; i--) {
					if(turnOrder[i] == Entity::getEntities()[j]) {
						turnOrder.erase(turnOrder.begin() + i);
						break;
					}
				}
				delete Entity::getEntities()[j];
			}
		}
		if(Entity::getCharacters().size() == 0) {
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou fucking suck!\nPress enter to exit.";
			getline(std::cin, lose);
			return;
		}
	}

}

Game::~Game() {
	// TODO Auto-generated destructor stub
}


Entity* Game::nextEntityTurn() {
	Entity* entityTurn;
	std::sort(turnOrder.begin(), turnOrder.end(), [](Entity* a, Entity* b) {return a->getActionTicks() < b->getActionTicks();});

	while(true) {
		for(int entity = 0; entity < (signed)turnOrder.size(); entity++) {
			if(turnOrder[entity]->getCastingArt() != NULL && turnOrder[entity]->getCastingArt()->castTick()) {
				turnOrder[entity]->useArt(turnOrder[entity]->getCastingArt());
			}
			if(turnOrder[entity]->getActionTicks() <= 0 && turnOrder[entity]->getCastingArt() == NULL) {
				entityTurn = turnOrder[entity];


				if(entity != (signed)turnOrder.size()-1) {
					turnOrder[entity]->setActionTicks(1000 * (1-((turnOrder[entity]->getTotalStats()[6] + Dice::rollDx(1,20,0))/100.0)));
				} else if (initiated) {
					turnOrder[entity]->setActionTicks(1000 * (1-((turnOrder[entity]->getTotalStats()[6] + Dice::rollDx(1,20,0))/100.0)) + 500);
				}
				turnOrder.push_back(turnOrder[entity]);
				turnOrder.erase(turnOrder.begin() + entity);
				initiated = true;
				return (entityTurn);
			}
			turnOrder[entity]->setActionTicks(turnOrder[entity]->getActionTicks() - 10);
		}
	}
}


void Game::initiateCombat() {
	turnOrder = Entity::getEntities();
	for(int i = 0; i < (signed)turnOrder.size(); i++) {
		turnOrder[i]->setActionTicks(1000 * (10/float(turnOrder[i]->getSPD() + Dice::rollDx(1,20,0))));
	}

	std::sort(turnOrder.begin(), turnOrder.end(), [](Entity* a, Entity* b) {return a->getActionTicks() < b->getActionTicks();});

}





