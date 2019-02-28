#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"
#include "Crafts.h"
#include "Arts.h"
#include "MasterQuartz.h"
#include "Map.h"
#include "BasicAttack.h"
#include "Equipment.h"
#include "Quartz.h"

using Stats = std::array<int, 11>;
using AttackRanks = std::array<int, 4>;

extern void Console();

class Character:public Entity {
	AttackRanks ranks;

	Entity* link;

public:
	Character(Stats const& s, const std::string & n, Position p, AttackRanks ar, std::string r):Entity(s, n, p, r) {Entity::addCharacter(this); ranks = ar; link = this; setBasicAttack(new BasicAttack());}
	~Character() {}

	void useCraft(Craft* usedCraft, Entity* enemy, bool followUpAttack = false);
	void useCraft(Craft* usedCraft);

	void useArt(Art* usedArt, Entity* enemy);
	void useArt(Art* usedArt);

	bool isCharacter(Entity* entity);

	void takeTurn();

	void showCurrentRange();

	void updateArts_MasterQuartz();
	void updateStats_Equipment();
	void updateStats_MasterQuartz();
	void updateStats_Quartz();

	void takeTurn_Craft();
	void takeTurn_Art();
	void takeTurn_BasicAttack();
	void move();
	void takeTurn_Link();

	int getArtDamage(Art* art);

	void setLink(Entity* charac) {link = charac;}
	Entity* getLink() {return link;}

	void moveAttack(Craft* usedCraft, Position pos);


	bool isUnbalanced(Entity* enemy, Craft* usedCraft);
};

#endif
