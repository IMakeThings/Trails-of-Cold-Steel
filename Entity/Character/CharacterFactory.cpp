/*
 * CharacterFactory.cpp
 *
 *  Created on: 19 Feb 2019
 *      Author: PatrickC
 */

#include "CharacterFactory.h"

std::map<std::string, std::function<Character*()>> CharacterFactory::characterMap;
bool CharacterFactory::loaded = false;

CharacterFactory::CharacterFactory() {
	return;
}

void CharacterFactory::loadCharacters() {
	loaded = true;
	characterMap["001C"] =
			[]() -> Character* {return new Tachi("New Tachi", {0,0});};
	characterMap["002C"] =
			[]() -> Character* {return new Greatsword("New Greatsword", {0,0});};
}

