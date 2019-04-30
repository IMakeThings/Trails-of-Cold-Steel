#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include <array>
class Craft;
class Equipment;
class MasterQuartz;
class Art;
class Quartz;
//#include "StatBuff.h"

#include <map>
#include "Dice.h"
#include <functional>

using UnbalanceEfficacy = std::array<int, 4>;
using Stats = std::array<int, 11>;
using Position = std::array<int, 2>;
extern void enterPause();

class Entity {
	//HP EP STR DEF ATS ADF SPD DEX AGL MOV RNG
	Stats baseStats;

	Stats totalStats;

	std::string name;

	std::vector<Craft*> crafts;

	std::vector<Art*> arts;

	std::vector<Equipment*> equipment;

	std::vector<Quartz*> quartz;

	MasterQuartz* masterQuartz;

	Position currentPosition;

	static std::vector<Entity*> madeEnemies;
	static std::vector<Entity*> madeCharacters;
	static std::vector<Entity*> madeEntities;

	int actionTicks;
	int CP;

	Craft* basicAttack;

	Art* castingArt;

	std::string representation;

	//std::vector<Buff*> buffs;

public:

	virtual ~Entity();
	Entity(Stats const& s, const std::string & n, Position p, std::string r) :
			baseStats(s), totalStats(s), name(n), currentPosition(p), representation(
					r) {
		actionTicks = 1000;
		madeEntities.push_back(this);
		CP = 200;
		basicAttack = NULL;
		masterQuartz = NULL;
		castingArt = NULL;
	}

	//Add crafts to usable craft list.
	void addCraft(Craft* c) {
		crafts.push_back(c);
	}
	void addArt(Art* a) {
		arts.push_back(a);
	}

	Art* getCastingArt() {
		return (castingArt);
	}
	void setCastingArt(Art* ca) {
		castingArt = ca;
	}

	std::string getRepresentation() {
		return (representation);
	}
	void setRepresentation(std::string r) {
		representation = r;
	}

	//Returns list of all instantiated Entities
	static std::vector<Entity*> getCharacters() {
		return madeCharacters;
	}
	static std::vector<Entity*> getEnemies() {
		return madeEnemies;
	}
	static std::vector<Entity*> getEntities() {
		return madeEntities;
	}
	static void addCharacter(Entity* charac) {
		madeCharacters.push_back(charac);
	}
	static void addEnemy(Entity* enemy) {
		madeEnemies.push_back(enemy);
	}

	//HP EP STR DEF ATS ADF SPD DEX AGL MOV RNG CP
	// Getters/setters

	//Stats
	Stats getBaseStats() {
		return baseStats;
	}
	void setBaseStats(Stats bs) {
		baseStats = bs;
	}

	Stats getTotalStats() {
		return totalStats;
	}
	void setTotalStats(Stats ts) {
		totalStats = ts;
	}

	int getHP() {
		return totalStats[0];
	}
	void setHP(int HP) {
		totalStats[0] = HP;
	}

	int getEP() {
		return totalStats[1];
	}
	void setEP(int EP) {
		totalStats[1] = EP;
	}

	int getSTR() {
		return totalStats[2];
	}
	void setSTR(int STR) {
		totalStats[2] = STR;
	}

	int getDEF() {
		return totalStats[3];
	}
	void setDEF(int DEF) {
		totalStats[3] = DEF;
	}

	int getATS() {
		return totalStats[4];
	}
	void setATS(int ATS) {
		totalStats[4] = ATS;
	}

	int getADF() {
		return totalStats[5];
	}
	void setADF(int ADF) {
		totalStats[5] = ADF;
	}

	int getSPD() {
		return totalStats[6];
	}
	void setSPD(int SPD) {
		totalStats[6] = SPD;
	}

	int getDEX() {
		return totalStats[7];
	}
	void setDEX(int DEX) {
		totalStats[7] = DEX;
	}

	int getAGL() {
		return totalStats[8];
	}
	void setAGL(int AGL) {
		totalStats[8] = AGL;
	}

	int getMOV() {
		return totalStats[9];
	}
	void setMOV(int MOV) {
		totalStats[9] = MOV;
	}

	int getRNG() {
		return totalStats[10];
	}
	void setRNG(int RNG) {
		totalStats[10] = RNG;
	}

	int getCP() {
		return CP;
	}
	void setCP(int cp) {
		CP = cp;
	}

	//void applyStatBuff(Buff* b);

	//Entity info
	std::string getName() {
		return name;
	}
	void setName(std::string n) {
		name = n;
	}
	std::vector<Craft*> getCrafts() {
		return crafts;
	}
	std::vector<Art*> getArts() {
		return arts;
	}
	Position getPositions() {
		return currentPosition;
	}
	void setPositions(Position positions) {
		currentPosition = positions;
	}
	std::vector<Equipment*> getEquipment() {
		return equipment;
	}
	std::vector<Quartz*> getQuartz() {
		return quartz;
	}
	MasterQuartz* getMasterQuartz() {
		return masterQuartz;
	}
	int getActionTicks() {
		return actionTicks;
	}
	void setActionTicks(int ticks) {
		actionTicks = ticks;
	}
	Craft* getBasicAttack() {
		return basicAttack;
	}
	void setBasicAttack(Craft* ba) {
		basicAttack = ba;
	}

	//Calculations
	//Returns distance from current position to an input position (NO DIAG)
	int getDistanceToPoint(Position positions) {
		return (abs(positions[0] - currentPosition[0])
				+ abs(positions[1] - currentPosition[1]));
	}
	Position getXYdistanceToPoint(Position positions);
	Position findClosestPositionToPointInRange(Position tar);
	Position findClosestPositionOfAttackPoints(
			std::vector<Position> attackPoints);
	//Returns an integer of the attack/art modifier specified by each entity.
	virtual int getAttackModifier() = 0;
	virtual int getArtModifier() = 0;

	//All craft related things
	void useCraft(std::string stringCraft, Entity* enemy);
	virtual void useCraft(Craft* usedCraft) {
	}
	void useCraft(std::string stringCraft);
	virtual void useCraft(Craft* usedCraft, Entity* enemy, bool followUpAttack =
			false) {
	}
	//virtual void useCraft(Craft* usedCraft, Entity* enemy);
	//Returns the damage dealt by a specific craft.
	//int getCraftDamage(Craft* craft);
	//Determines if the Entity has the craft
	bool findCraft(Craft* c);
	Craft* findCraft(std::string c);

	//Arts
	//virtual void useArt(Art* usedArt, Entity* enemy);
	virtual void useArt(Art* usedArt, Entity* enemy) {
	}
	virtual void useArt(Art* usedArt, Position pos);
	virtual void useArt(Art* usedArt) {
	}
	void useArt(std::string stringArt, Entity* enemy);
	void useArt(std::string stringCraft, Position pos);

	virtual int getArtDamage(Art* art) {
		return 0;
	}
	;

	Art* findArt(std::string a);

	//Equipment related things
	void addEquipment(Equipment* e) {
		equipment.push_back(e);
		updateStats_Equipment();
	}
	void addEquipment(std::string e);

	void removeEquipment(Equipment* e);

	//Master Quartz
	void setMasterQuartz(MasterQuartz* mq) {
		masterQuartz = mq;
		updateStats_MasterQuartz();
		updateArts_MasterQuartz();
	}
	//Normal Quartz
	void addQuartz(Quartz* q);

	//Ensures that any updates to stats through items are recorded and updated
	virtual void updateArts_MasterQuartz() {
	}
	virtual void updateStats_Equipment() {
	}
	virtual void updateStats_MasterQuartz() {
	}
	virtual void updateStats_Quartz() {
	}

	int getPhysicalModifier(Entity* enemy);
	int getMagicModifier(Entity* enemy);

	virtual void moveEntity(Position positions);

	virtual void takeTurn() {
	}
	virtual void takeTurn_Craft() {
	}
	virtual void takeTurn_Art() {
	}
	virtual void move() {
	}

	virtual UnbalanceEfficacy getUnbalanceEfficacy() {
		return {0,0,0,0};
	}

	bool isHit(Entity* entity);
};

#endif
