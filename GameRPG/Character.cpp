#include "Character.h"

Character::Character() {

	name = " ";
	race = " ";
	sex = " ";

	playerRace = { "elf", "dwarf", "firelord", "goblin", "human" };

	 level = 0, health = 0, totalHealth = 0, maxHealth = 0, heal = 0;

	 level = 0, current_xp = 0, base_xp = 1, xp_to_level = base_xp, minLevel = 1, maxLevel = 2;

}

void Character::characterCreation() {

	int counter = 0;

	//Caracteristicas basicas de creacion
	std::cout << "Enter Character Name: ";
	std::cin >> name;

	std::cout << "Enter Character race: ";
	std::cout << "Elf\n";
	std::cout << "Dwarf\n";
	std::cout << "FireLord\n";
	std::cout << "Goblin\n";
	std::cout << "Human\n";
	std::cout << "Escriba debajo de tu raza: \n\n";
	std::cin >> race;

	std::for_each(race.begin(), race.end(), [](char& c) {
		c = ::tolower(c);
		});

	for (int i = 0; i < sizeof(playerRace); i++) {
		if (race == "elf") {
			health = 80;
			break;
		}
		if (race == "swarf") {
			health = 120;
			break;
		}
		if (race == "firelord") {
			health = 150;
			break;
		}
		if (race == "goblin") {
			health = 82;
			break;
		}
		if (race == "elf") {
			health = 68;
			break;
		}
		else {
			health = 100;
			break;
		}
	}

	std::cout << "\n";
	std::cout << "Enter Character sex: ";
	std::cin >> sex;
	system("cls");

	//Creacion divertida

	for (int i = 0; i <= counter; i++) {
		if (i == 0)
			std::cout << "Creation Character.\n";
		if (i == 1)
			std::cout << "Creation Character..\n";
		if (i == 2) {
			std::cout << "Creation Character...\n";
			break;
		}
		Sleep(400);
		system("cls");
		counter++;
	}

	name[0] = toupper(name[0]);
	race[0] = toupper(race[0]);
	sex[0] = toupper(sex[0]);

	totalHealth = health;
	maxHealth = totalHealth;
}