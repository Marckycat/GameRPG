
#include "Character.h"

void HUD();
void Combat();
void CombatHUD();
void Moving();
void CreateMonster();
void LevelUp();


int monsterHp = 0;
int monsterXp = 0;
int monsterLevel = 0;

std::string monsterName[] = { "Goblin", "Dwarf", "Orge", "Witch", "Demon", "Wizard" };
int currentMonsterNames = 5;
std::string currentMonster = " ";

int counter = 0;

Character character;

int main() {

	character.characterCreation();

	HUD();
	Moving();

	system("pause");

	return 0;
}

void HUD() {
	Sleep(500);
	system("cls");
	std::cout << "Name: " << character.name << "       Health: " << character.totalHealth << "\nRace: " <<
		character.race << "\nSex: " << character.sex << "\nLevel: " << character.level << "\nxp: " <<
		character.current_xp << "\nXp to Level: " << character.xp_to_level << std::endl;

	Moving();
}

void CombatHUD() {
	Sleep(500);
	system("cls");
	std::cout << "Name: " << character.name << "     |    Monster Name: " << currentMonster <<
		"\nHealth: " << character.totalHealth << "         |        Monster Health: " <<
		monsterHp << "\nLevel: " << character.level << "         |         Monster Level: " <<
		monsterLevel << std::endl;
}

void Combat() {
	CombatHUD();
	int playerAttack;
	//int playerDamage = 8 * level / 2;
	int playerDamage = 30;
	int monsterAttack = 6 * monsterLevel / 2;

	if (character.totalHealth >= 1 && monsterHp >= 1) {
		std::cout << "\n";
		std::cout << "1. Attack\n";
		std::cout << "2. Block\n";
		std::cout << "3. RUN!\n";
		std::cout << "\n";
		std::cin >> playerAttack;

		if (playerAttack == 1) {
			//Attack
			std::cout << "Atacando... lo hiciste " << playerDamage << " hacia " << currentMonster << std::endl;
			monsterHp = monsterHp - playerDamage;
			Sleep(1000);
			CombatHUD();
			if (monsterHp >= 1) {
				std::cout << "\n";
				std::cout << "El Monstruo esta Atacando\n";
				character.totalHealth = character.totalHealth - monsterAttack;
				std::cout << "Haz sufrido " << monsterAttack << " hp " << character.totalHealth << std::endl;
				//Cambiando la funcion
				if (character.totalHealth <= 0) {
					character.totalHealth = 0;
					system("cls");
					std::cout << "Haz muerto! \nTu nivel acutal: " << character.level <<
						" te a matado por " << currentMonster << std::endl;
					Sleep(2000);
					exit(0);
				}
			}
			else if (monsterHp <= 0) {
				monsterHp = 0;
				std::cout << "\n";
				std::cout << "Haz Perdido " << currentMonster << " eres recompensado con " <<
					monsterXp << " xp.\nBien hecho\n";
				if (character.level != character.maxLevel) {
					character.current_xp += monsterXp;
					LevelUp();
				}

				Sleep(1000);
				HUD();
			}
			Sleep(1000);
			Combat();
		}
		else if (playerAttack == 2) {
			//Block
			std::cout << "Bloquear\n";
			int i = rand() % 100 + 1;
			if (i >= 50) {
				std::cout << "Haz bloqueado un ataque entrante\n";
				character.heal = character.level * 10 / 2;
				std::cout << "Haz sido sanado por " << character.heal << std::endl;
				character.totalHealth += character.heal;
				Sleep(1000);
				Combat();
			}
			else {
				std::cout << "No lograste bloquear el ataque\n";
				character.totalHealth -= monsterAttack;
				std::cout << "Te apuñalaron por la espalda " << monsterAttack << " actual hp " <<
					character.totalHealth << std::endl;
				Sleep(1000);
				Combat();
			}
		}
		else if (playerAttack == 3) {
			//Run
			std::cout << "Intentas correr\n";
			int x = rand() % 100 + 1;
			if (x >= 50) {
				std::cout << "Huyes\n";
				HUD();
			}
			else {
				std::cout << "Fallaste en escapar\n";
				std::cout << "El Monstruo te ataca salvajemente\n";
				character.totalHealth -= monsterAttack + 10;
				std::cout << "Haz sufirdo daño" << monsterAttack + 10 << "Su estado de salud es" <<
					character.totalHealth << std::endl;
				Sleep(1000);
				Combat();
			}
		}
		else {
			std::cout << "Invalid Number\n";
			Sleep(500);
			Combat();
		}
	}
}

void Moving() {

	int choice;

	std::cout << "\n\n";
	std::cout << "1. Move Forward\n";
	std::cout << "2. Relax\n";
	std::cout << "3. Move Backwards\n";
	std::cout << "\n";

	std::cin >> choice;

	if (choice == 1) {
		int temp = rand() % 100 + 1;
		std::cout << "Empiezas a anvanzar...\n";
		if (temp >= 50) {
			//Encuentra el mounstro
			CreateMonster();
			std::string tempName = monsterName[rand() % currentMonsterNames];
			std::cout << "A " << tempName << "¡Preparate para pelear!\n";
			currentMonster = tempName;
			Sleep(1000);
			Combat();
		}
		std::cout << "You find nothing of interesting\n";
		Sleep(1000);
		HUD();

	}
	else if (choice == 2) {
		std::cout << "You want to set up camp for the evening\n";
		if (character.totalHealth <= 99) {
			character.totalHealth += 10 * character.level;
		}
		std::cout << "You healed by resting. Health is now " << character.totalHealth << std::endl;
		Sleep(1000);
		HUD();

	}
	else if (choice == 3) {
		int temp = rand() % 100 + 1;
		std::cout << "Empiezas a retroceder...\n";
		if (temp >= 50) {
			//Encuentra el mounstro
			CreateMonster();
			std::string tempName = monsterName[rand() % currentMonsterNames];
			std::cout << "A " << tempName << "¡Preparate para pelear!\n";
			currentMonster = tempName;
			Sleep(1000);
			Combat();
		}
		std::cout << "No encuentras nada interesante\n";
		Sleep(1000);
		HUD();

	}
	else {
		std::cout << "Invalid Number\n";
		Sleep(500);
		Moving();
	}
}

void LevelUp() {

	if (character.current_xp >= character.nextLevel) {
		character.xp_to_level += floor(character.level + 25 * pow(2, character.level / 7));
		character.totalHealth = floor(character.totalHealth + 13 * pow(2, character.level / 8));
		
		if (character.level >= character.minLevel && character.level <= character.maxLevel) {
			character.level;
		}
		else {
			character.level = 0;
		}
		character.maxHealth = character.totalHealth;
		std::cout << "Espera ¿Que es esto un nivel superior? ahora es este tu nivel " << character.level << std::endl;
		std::cout << "!Tu salud total a aumentado en 20 punto¡ Su salud maxima es " << character.totalHealth << std::endl;
		std::cout << "\n";
		Sleep(1000);
		
		
	}
	Sleep(2000);
	HUD();
}

void CreateMonster() {
	monsterHp = 30;
	monsterLevel = (rand() % 3) + character.level;
	monsterHp = (rand() % 30) * monsterLevel;

	monsterXp = monsterHp;

	if (monsterHp == 0)
		CreateMonster();
	if (monsterLevel == 0)
		CreateMonster();

}