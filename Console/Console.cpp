/*
 * Console.cpp
 *
 *  Created on: 19 Feb 2019
 *      Author: PatrickC
 */

#include "ArtFactory.h"
#include "CraftFactory.h"
#include "CharacterFactory.h"
#include "EnemyFactory.h"
#include "EquipmentFactory.h"
#include "MasterQuartzFactory.h"
#include "QuartzFactory.h"
#include <iostream>

std::string input;

extern int convertPosition(std::string newPosition);

void consoleArt() {
	std::cout << "\n\nDo you want to add or remove arts from an entity?\n(1) add\t\t(2) remove\t\t(Enter) exit\n\n";
	getline(std::cin, input);
	if(input == "") {
		return;
	}

	if(input == "1") {
		std::cout << "\nSelect an existing entity\n\n";
		for(int i = 0; i < (signed)Entity::getEntities().size();i++) {
			std::cout << "(" << i+1 << ") " << Entity::getEntities()[i]->getName() << std::endl;
		}

		getline(std::cin,input);

		int selection = convertPosition(input);

		if(selection < 0 || selection >= Entity::getEntities().size()) {
			std::cout << "\nInvalid selection.\n\n";
			enterPause();
			return;
		}

		Entity* chosenEntity = Entity::getEntities()[selection];

		std::cout << "\n\nSee art names?\n(1) Yes\t\t(2) No\n\n";

		getline(std::cin,input);

		std::cout << std::endl;

		if(!ArtFactory::isLoaded()) {
			ArtFactory::loadArts();
		}

		if (input == "1") {
			for(auto elem : ArtFactory::getArtMap()) {
			   std::cout << elem.first << std::endl;
			}
		}

		std::cout << "\nNow input an art name\n";

		getline(std::cin, input);

		if(ArtFactory::getArtMap().count(input) > 0) {
			Art* chosenArt = ArtFactory::getNewArt(input);
			chosenEntity->addArt(chosenArt);
		} else {
			std::cout << "Invalid art selection\n\n";
			enterPause();
			return;
		}
		return;
	}
}

void consoleCraft() {
	std::cout << "\n\nDo you want to add or remove crafts from an entity?\n(1) add\t\t(2) remove\t\t(Enter) exit\n\n";
	getline(std::cin, input);
	if(input == "") {
		return;
	}

	if(input == "1") {
		std::cout << "\nSelect an existing entity\n\n";
		for(int i = 0; i < (signed)Entity::getEntities().size();i++) {
			std::cout << "(" << i+1 << ") " << Entity::getEntities()[i]->getName() << std::endl;
		}

		getline(std::cin,input);

		int selection = convertPosition(input);

		if(selection < 0 || selection >= Entity::getEntities().size()) {
			std::cout << "\nInvalid selection.\n\n";
			enterPause();
			return;
		}

		Entity* chosenEntity = Entity::getEntities()[selection];

		std::cout << "\n\nSee craft names?\n(1) Yes\t\t(2) No\n\n";

		getline(std::cin,input);

		std::cout << std::endl;

		if(!CraftFactory::isLoaded()) {
			CraftFactory::loadCrafts();
		}

		if (input == "1") {
			for(auto elem : CraftFactory::getCraftMap()) {
			   std::cout << elem.first << std::endl;
			}
		}

		std::cout << "\nNow input a craft name (It's like an ID so it has the be exactly the same).\n";

		getline(std::cin, input);

		if(CraftFactory::getCraftMap().count(input) > 0) {
			Craft* chosenCraft = CraftFactory::getNewCraft(input);
			chosenEntity->addCraft(chosenCraft);
		} else {
			std::cout << "Invalid craft selection\n\n";
			return;
		}
		return;
	}
}

void consoleMenu() {
	//Intro
	std::cout << "You have entered the console screen.\nThis is basically god mode, where you can do most things.\nYou can press enter to leave this screen.\n\n";


	//Selection output
	std::cout << "Select one of the following.\n(1) Arts\t\t(2) Crafts\t\t(3) Characters\n(4) Enemies\t\t(5) MasterQuartz\t\t(6) Quartz\n";

	getline(std::cin, input);

	if(input == "") {
		return;
	}

	if(input == "1") {
		consoleArt();
	} else if(input == "2") {
		consoleCraft();
	}
	//else if(input == "3") {
//		consoleCharacter();
//	} else if(input == "4") {
//		consoleEnemy();
//	} else if(input == "5") {
//		consoleMQ();
//	} else if(input == "6") {
//		consoleQ();
//	}

	std::cout << "(0) do more.\n";
	getline(std::cin, input);
	if(input == "0") {
		consoleMenu();
	}
}

