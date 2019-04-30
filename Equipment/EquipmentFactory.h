/*
 * EquipmentFactory.h
 *
 *  Created on: 19 Feb 2019
 *      Author: PatrickC
 */

#ifndef EQUIPMENTFACTORY_H_
#define EQUIPMENTFACTORY_H_

#include "Equipment.h"
#include "Armour.h"
#include "Shoes.h"
#include "Weapon.h"
#include <functional>
#include <map>

class EquipmentFactory {
	static std::map<std::string, std::function<Equipment*()>> equipmentMap;
	static bool loaded;

public:
	EquipmentFactory();

	static void loadEquipments();
	static Equipment* getNewEquipment(std::string ID) {
		return equipmentMap.find(ID)->second();
	}
	static std::map<std::string, std::function<Equipment*()>> getEquipmentMap() {
		return equipmentMap;
	}
	static void regEquipment(std::string ID, std::function<Equipment*()> f) {
		equipmentMap[ID] = f;
	}

	static bool isLoaded() {
		return loaded;
	}
};

#endif /* EQUIPMENTFACTORY_H_ */
