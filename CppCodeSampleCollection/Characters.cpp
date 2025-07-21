#include <iostream>
#include "Characters.h"

GenericCharacter::GenericCharacter(std::string _name) : name(_name) {
	type = CharacterType::UNKNOWN;
	icon = '/';
	myClass = new AbstractClass();

	_maxHealth = 30;
	_currHealth = _maxHealth;

	_lowAttackDamage = 0;
	_highAttackDamage = 0;

	increasingHealth = false;
	incHealthLife = 0;

	decreasingHealth = false;
	decHealthLife = 0;

	increasingHealth = false;
	incHealthLife = 0;

	freezingHealth = false;
	frzHealthLife = 0;

	skippingTurn = false;
	skipTurnLife = 0;

	hidingTurn = false;
	hideTurnLife = 0;

	increasingAttack = false;
	incAttackLife = 0;

	decreasingAttack = false;
	decAttackLife = 0;
}

GenericCharacter::~GenericCharacter() {
	myClass = NULL;
	delete myClass;
}




Player::Player(string _name) : GenericCharacter(_name) {
	type = CharacterType::PLAYER;
	icon = '+';
}

Player::~Player() {

}

void Player::ChooseClass() {
	int code = 0;

	std::cout << "Debug.Log: Player::ChooseClass(" << code << ") \n\n";

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
				std::cout << "Debug.Log: Player::ChooseClass(" << ++code << ") || 'case 'Bard' selected \n\n";
				myClass = new Bard();
				std::cout << "Debug.Log: Player::ChooseClass(" << ++code << ") || Bard() Successful\n\n";
				std::cout << name << " is a Bard: " << myClass->description << ".\n";
				std::cout << std::endl;
				break;
			}
			case 2: {
				std::cout << "Debug.Log: Player::ChooseClass(" << ++code << ") || 'case 'Cleric' selected \n\n";
				myClass = new Cleric();
				std::cout << "Debug.Log: Player::ChooseClass(" << ++code << ") || Cleric() Successful\n\n";
				std::cout << name << " is a Cleric: " << myClass->description << ".\n";
				std::cout << std::endl;
				break;
			}
			case 3: {
				std::cout << "Debug.Log: Player::ChooseClass(" << ++code << ") || 'case 'Fighter' selected \n\n";
				myClass = new Fighter();
				std::cout << "Debug.Log: Player::ChooseClass(" << ++code << ") || Fighter() Successful\n\n";
				std::cout << name << " is a Fighter: " << myClass->description << ".\n";
				std::cout << std::endl;
				break;
			}
			case 4: {
				std::cout << "Debug.Log: Player::ChooseClass(" << ++code << ") || 'case 'Ranger' selected \n\n";
				myClass = new Ranger();
				std::cout << "Debug.Log: Player::ChooseClass(" << ++code << ") || Ranger() Successful\n\n";
				std::cout << name << " is a Ranger: " << myClass->description << ".\n";
				std::cout << std::endl;
				break;
			}
			case 5: {
				std::cout << "Debug.Log: Player::ChooseClass(" << ++code << ") || 'case 'Rogue' selected \n\n";
				myClass = new Rogue();
				std::cout << name << " is a Rogue: " << myClass->description << ".\n";
				std::cout << std::endl;
				break;
			}
			case 6: {
				std::cout << "Debug.Log: Player::ChooseClass(" << ++code << ") || 'case 'Wizard' selected \n\n";
				myClass = new Wizard();
				std::cout << "Debug.Log: Player::ChooseClass(" << ++code << ") || Wizard() Successful\n\n";
				std::cout << name << " is a Wizard: " << myClass->description << ".\n";
				std::cout << std::endl;
				break;
			}

			default: {
				std::cout << "Debug.Log: Player::ChooseClass(" << ++code << ") || 'case " << selection << "'Bard' selected \n\n";
				std::cout << "Invalid selection, enter a valid choice between 1 and 6. ";
				std::cout << std::endl;
				break;
			}
		}//end switch statement
	}
	std::cout << std::endl;

	std::cout << "Debug.Log: Player::ChooseClass(" << ++code << ") || Class Selected \n\n";

	// After the class is picked...
	ChooseAbilities();
	std::cout << "Debug.Log: Player::ChooseClass(" << ++code << ") || ChooseAbilities() Successfull \n\n";
}

void Player::Reset() {

}


void Player::ChooseAbilities() {
	int code = 0;

	std::cout << "Debug.Log: Player::ChooseAbilitie\s(" << code << ") \n\n";

	int ability1 = 0, ability2 = 0;

	std::cout << myClass->name << " class has the following abilities: \n";
	vector<AbstractAbility*>::iterator classAbilities = myClass->GetAbilityList().begin();
	int abilityIndex = 1;

	while (classAbilities != myClass->GetAbilityList().end()) {
		std::cout << abilityIndex++ << (*classAbilities)->name << ": " << (*classAbilities)->description;
		std::cout << std::endl;
	}

	// Ask the player to choose 2 abilities

	// First Ability 
	while (ability1 < 1 && ability1 > myClass->GetAbilityList().capacity()) {
		std::cout << "What will their first ability be? \t";
		std::cin >> ability1;
		std::cout << std::endl;

		if (ability1 < 1 || ability1 > myClass->GetAbilityList().capacity()) {
			std::cout << "Invalid selection, enter a valid ability option. \t";
		}
	}
	std::cout << std::endl;

	myAbilities.push_back(myClass->GetAbilityList()[ability1]);
	std::cout << name << " has " << myClass->GetAbilityList()[ability1]->name << "\n";
	std::cout << std::endl;

	// Second Ability 
	while ((ability2 < 1 && ability2 > myClass->GetAbilityList().capacity()) && ability2 != ability1 ) {
		std::cout << "What will their second ability be? \t";
		std::cin >> ability2;
		std::cout << std::endl;

		if (ability2 < 1 || ability2 > myClass->GetAbilityList().capacity()) {
			std::cout << "Invalid selection, enter a valid ability option. \t";
		}

		if (ability2 == ability1) {
			std::cout << "Invalid selection, choose a different ability \t";
		}
	}
	std::cout << std::endl;

	myAbilities.push_back(myClass->GetAbilityList()[ability2]);
	std::cout << name << " has " << myClass->GetAbilityList()[ability2]->name << "\n";
	std::cout << std::endl;
}




void Enemy::Reset() {

}

