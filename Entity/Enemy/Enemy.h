/*
 * Enemy.h
 *
 *  Created on: 18 Jan 2019
 *      Author: PatrickC
 */




#ifndef ENEMY_H_
#define ENEMY_H_

#include <vector>
#include <array>
#include <string>
#include "Entity.h"
#include "Crafts.h"
#include "BasicAttack.h"
#include "Map.h"


using Stats = std::array<int, 11>;
using UnbalanceEfficacy = std::array<int, 4>;
using Position = std::array<int, 2>;


class Enemy:public Entity {
	UnbalanceEfficacy efficacy;

public:
	Enemy(Stats const& s, const std::string & n, Position p, UnbalanceEfficacy ue, std::string r):Entity(s, n, p, r)
	{Entity::addEnemy(this); efficacy = ue; setBasicAttack(new BasicAttack());}
	~Enemy();

	void takeTurn_Craft(Craft* craft);
	void takeTurn_Art(Art* art, Position tar);
	void move(Position pos);

	UnbalanceEfficacy getUnbalanceEfficacy() {return efficacy;}

	Entity* findClosestCharacterInRange();

	virtual void takeTurn() = 0;

	void moveEntity(Position positions);

	bool isEnemy(Entity* entity);

	void useCraft(Craft* usedCraft, Entity* enemy, bool followUpAttack = false);

	virtual int getCount() {return 0;}
};

#endif /* ENEMY_H_ */
