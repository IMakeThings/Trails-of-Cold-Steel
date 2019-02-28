/*
 * CharacterFactory.h
 *
 *  Created on: 19 Feb 2019
 *      Author: PatrickC
 */

#ifndef CHARACTERFACTORY_H_
#define CHARACTERFACTORY_H_

#include "Character.h"
#include "Tachi.h"
#include "GreatSword.h"
#include <functional>

class CharacterFactory {
	static std::map<std::string, std::function<Character*()>> characterMap;
	static bool loaded;

public:
	CharacterFactory();

	static void loadCharacters();
	static Character* getNewCharacter(std::string ID, std::string n, Position p) {return characterMap.find(ID)->second();}
	static std::map<std::string, std::function<Character*()>> getCharacterMap() {return characterMap;}
	static void regCharacter(std::string ID, std::function<Character*()> f) {characterMap[ID] = f;}

	static bool isLoaded() {return loaded;}
};




#endif /* CHARACTERFACTORY_H_ */
