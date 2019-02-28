/*
 * Map.h
 *
 *  Created on: 18 Jan 2019
 *      Author: PatrickC
 */

#include <string>
#include <vector>
#include <array>

#include "Character.h"
#include "Enemy.h"

#ifndef MAP_H_
#define MAP_H_

using _Map = std::array<std::array<std::string, 17>, 17>;

class Map {
	static _Map map;
public:
	//Map();

	//static _Map getMap() {return map;}

	static void generate();

	static void display();
	static void displayAoE(Craft* usedCraft, Position pos);
	static void displayAoE(std::vector<Position> positions);
	static void displayAoE(Position pos) {map[pos[0]][pos[1]] = "X"; 	display(); update();}

//	static void addEntity(Entity* charac) {Entitys.push_back(charac);}
//	static void addEntity(std::vector<Entity*> charac) {Entitys = charac;}

//	static void removeEntity(Entity* entity);

	static void update();
};



#endif /* MAP_H_ */
