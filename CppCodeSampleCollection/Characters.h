#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

#include "Classes.h"
#include "Abilities.h"

using namespace std;

#ifndef CHARACTERS_H
#define CHARACTERS_H

using std::vector;

enum class CharacterType { UNKNOWN, PLAYER, ENEMY };

class GenericCharacter {
public:
	std::string name;
	CharacterType type;
	char icon;
	AbstractClass *myClass;

	// Health Range
	unsigned int _currHealth;
	unsigned int _maxHealth;

	// Attack damage range
	unsigned int _lowAttackDamage;
	unsigned int _highAttackDamage;

	// Active Effects
	bool increasingHealth;
	unsigned int incHealthLife;

	bool decreasingHealth;
	unsigned int decHealthLife;

	bool freezingHealth;
	unsigned int frzHealthLife;

	bool skippingTurn;
	unsigned int skipTurnLife;

	bool hidingTurn;
	unsigned int hideTurnLife;

	bool increasingAttack;
	unsigned int incAttackLife;

	bool decreasingAttack;
	unsigned int decAttackLife;

	vector<AbstractAbility*> myAbilities;

	GenericCharacter(std::string _name);

	~GenericCharacter();

	virtual void Reset() = 0;

	virtual void ChooseClass() = 0;

	virtual void ChooseAbilities() = 0;

private:
};

class Player : public GenericCharacter {
public:
	Player(string _name);

	~Player();

	void ChooseClass();

	virtual void Reset();

private:
	void ChooseAbilities();
};

class Enemy : public GenericCharacter {
public:
	unsigned int _minHealth;

	Enemy(string _name) : GenericCharacter(_name) {
		type = CharacterType::ENEMY;
		icon = '-';

		_minHealth = 20;

		// srand(time(nullptr));
		// int random = rand();
	}

	~Enemy() {}

	void ChooseClass() {
		// Randomly select a class for the enemy

		// After the class is picked...
		ChooseAbilities();
	}

	virtual void Reset();

private:
	void ChooseAbilities() {
		// Randomly select 2 abilities from the character's class

		// Add the first ability in the class list to myAbilities first
	}
};

#endif