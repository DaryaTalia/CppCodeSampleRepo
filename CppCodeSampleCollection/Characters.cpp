#include <iostream>
#include "Characters.h"

GenericCharacter::GenericCharacter(std::string _name) : name(_name) {
	this->type = CharacterType::UNKNOWN;
	this->icon = '/';
	this->myClass = new AbstractClass();
	this->myAbilities = {};

	this->_maxHealth = 30;
	this->_currHealth = _maxHealth;

	this->_lowAttackDamage = 0;
	this->_highAttackDamage = 0;

	this->increasingHealth = false;
	this->incHealthLife = 0;

	this->decreasingHealth = false;
	this->decHealthLife = 0;

	this->increasingHealth = false;
	this->incHealthLife = 0;

	this->freezingHealth = false;
	this->frzHealthLife = 0;

	this->skippingTurn = false;
	this->skipTurnLife = 0;

	this->hidingTurn = false;
	this->hideTurnLife = 0;

	this->increasingAttack = false;
	this->incAttackLife = 0;

	this->decreasingAttack = false;
	this->decAttackLife = 0;
}

GenericCharacter::~GenericCharacter() {
	this->myClass = NULL;
	delete myClass;
}

AbstractClass GenericCharacter::ChooseClass()
{
	return AbstractClass();
}




Player::Player(string _name) : GenericCharacter(_name) {
	this->type = CharacterType::PLAYER;
	this->icon = '+';
}

Player::~Player() {

}

AbstractClass Player::ChooseClass() {

	// Ask player to pick the class
	int selection = 0;
	while (selection < 1 || selection > 6) {

		std::cout << "What class is " << name << "? \n";

		// Class Options
		{
			std::cout
				<< "1. Bard \n"
				<< "2. Cleric \n"
				<< "3. Fighter \n"
				<< "4. Ranger \n"
				<< "5. Rogue \n"
				<< "6. Wizard \n"
				<< "\n\n";
		}

		std::cin >> selection;
		std::cout << std::endl;

		switch (selection) {
			case 1: {
				//this->myClass = new Bard();
				(*myClass) = Bard();
				std::cout << name << " is a Bard: " << myClass->description << ".\n";
				std::cout << std::endl;
				break;
			}
			case 2: {
				myClass = new Cleric();
				std::cout << name << " is a Cleric: " << myClass->description << ".\n";
				std::cout << std::endl;
				break;
			}
			case 3: {
				myClass = new Fighter();
				std::cout << name << " is a Fighter: " << myClass->description << ".\n";
				std::cout << std::endl;
				break;
			}
			case 4: {
				myClass = new Ranger();
				std::cout << name << " is a Ranger: " << myClass->description << ".\n";
				std::cout << std::endl;
				break;
			}
			case 5: {
				myClass = new Rogue();
				std::cout << name << " is a Rogue: " << myClass->description << ".\n";
				std::cout << std::endl;
				break;
			}
			case 6: {
				myClass = new Wizard();
				std::cout << name << " is a Wizard: " << myClass->description << ".\n";
				std::cout << std::endl;
				break;
			}

			default: {
				std::cout << "Invalid selection, enter a valid choice between 1 and 6. ";
				std::cout << std::endl;
				break;
			}
		}//end switch statement
	}
	std::cout << std::endl;

	// After the class is picked...
	ChooseAbilities();

	return (*myClass);
}

void Player::ChooseAbilities() {
	int code = 0;

	std::cout << myClass->name << " class has the following abilities: \n";
	vector<AbstractAbility*>::iterator classAbilities = myClass->GetAbilityList()->begin();
	int abilityIndex = 1;

	while (classAbilities != myClass->GetAbilityList()->end()) {
		std::cout << abilityIndex++ << ". " << (*classAbilities)->name << ": " << (*classAbilities)->description;
		classAbilities++;
		std::cout << std::endl;
	}

	// Ask the player to choose 2 abilities

	int ability1 = 0; 
	int ability2 = 0;

	// First Ability 
	while (ability1 < 1 || ability1 > myClass->GetAbilityList()->size()) {
		std::cout << std::endl;
		std::cout << "What will their first ability be? \t";
		std::cin >> ability1;
		std::cout << std::endl;

		if (ability1 < 1 || ability1 > myClass->GetAbilityList()->size()) {
			std::cout << "Invalid selection, enter a valid ability option. \t";
		}
	}
	std::cout << std::endl;

	ability1--;
	myAbilities.emplace_back(myClass->GetAbilityList()->at(ability1));
	std::cout << name << " has " << (*myClass->GetAbilityList()) [ability1]->name << "\n";
	std::cout << std::endl;

	// Second Ability 
	ability1++;
	while ((ability2 < 1 || ability2 > myClass->GetAbilityList()->size()) && ability2 != ability1 ) {
		std::cout << std::endl;
		std::cout << "What will their second ability be? \t";
		std::cin >> ability2;
		std::cout << std::endl;

		if (ability2 < 1 || ability2 > myClass->GetAbilityList()->size()) {
			std::cout << "Invalid selection, enter a valid ability option. \t";
		}

		if (ability2 == ability1) {
			std::cout << "Invalid selection, choose a different ability \t";
		}
	}
	std::cout << std::endl;

	ability2--;
	myAbilities.emplace_back(myClass->GetAbilityList()->at(ability2));
	std::cout << name << " has " << (*myClass->GetAbilityList())[ability2]->name << "\n";
	std::cout << std::endl;
}

void Player::Reset() {

}




AbstractClass Enemy::ChooseClass()
{
	return AbstractClass();
}

void Enemy::Reset() {

}

