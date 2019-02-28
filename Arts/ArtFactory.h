/*
 * ArtFactory.h
 *
 *  Created on: 17 Feb 2019
 *      Author: PatrickC
 */

#ifndef ARTFACTORY_H_
#define ARTFACTORY_H_
#include "Arts.h"
#include "FireBolt.h"
#include <functional>

class ArtFactory {
	static std::map<std::string, std::function<Art*()>> artMap;
	static bool loaded;

public:
	ArtFactory();

	static void loadArts();
	static Art* getNewArt(std::string ID) {return artMap.find(ID)->second();}
	static std::map<std::string, std::function<Art*()>> getArtMap() {return artMap;}
	static void regArt(std::string ID, std::function<Art*()> f) {artMap[ID] = f;}

	static bool isLoaded() {return loaded;}
};



#endif /* ARTFACTORY_H_ */
