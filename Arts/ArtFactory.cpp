/*
 * ArtFactory.cpp
 *
 *  Created on: 17 Feb 2019
 *      Author: PatrickC
 */

#include "ArtFactory.h"

std::map<std::string, std::function<Art*()>> ArtFactory::artMap;
bool ArtFactory::loaded = false;

ArtFactory::ArtFactory() {
	return;
}

void ArtFactory::loadArts() {
	loaded = true;
	artMap["FireBolt"] = []() -> Art* {return new FireBolt();};
}

