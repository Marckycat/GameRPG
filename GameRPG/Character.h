#pragma once
#include "Header.h"

class Character {


public:
	Character();

	std::string name, race, sex;
	std::vector<std::string> playerRace;
	int health, totalHealth, maxHealth, nextLevel, heal;

	int level, current_xp, base_xp, xp_to_level, minLevel, maxLevel;

	void characterCreation();

};
