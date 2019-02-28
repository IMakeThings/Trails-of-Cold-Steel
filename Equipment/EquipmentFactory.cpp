/*
 * EquipmentFactory.cpp
 *
 *  Created on: 19 Feb 2019
 *      Author: PatrickC
 */

#include "EquipmentFactory.h"

std::map<std::string, std::function<Equipment*()>> EquipmentFactory::equipmentMap;
bool EquipmentFactory::loaded = false;


EquipmentFactory::EquipmentFactory() {
	return;
}

void EquipmentFactory::loadEquipments() {
	loaded = true;
	equipmentMap["001A"] = []() -> Equipment* {return new LeatherJacket();};
	equipmentMap["001S"] = []() -> Equipment* {return new LeatherShoes();};
	equipmentMap["001W"] = []() -> Equipment* {return new Kazekiri();};
}





