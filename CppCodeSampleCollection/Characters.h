#pragma once
#include <cstdlib>
#include <ctime>
#include <string>
#include "Classes.h"

using std::string;
using std::rand;
using std::srand;
using std::time;

enum class CharacterType { UNKNOWN, PLAYER, ENEMY };

class GenericCharacter {
public:
	string name;
	CharacterType type;
	char icon;
	AbstractClass myClass;

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

	bool increasingHealth;
	unsigned int incHealthLife;

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

	GenericCharacter(string _name) : name(_name) {
		type = CharacterType::UNKNOWN;
		icon = '/';

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
	~GenericCharacter() {}

	virtual void Reset() = 0;

	virtual void ChooseClass() = 0;

	virtual void ChooseAbilities() = 0;

private:
	vector<AbstractAbility*> _myAbilities;
};

class Player : GenericCharacter {
public:
	Player(string _name) : GenericCharacter(_name) {
		type = CharacterType::PLAYER;
		icon = '+';
	}

	~Player() {}

	void ChooseClass() {
		// Ask player to pick the class

		// After the class is picked...
		ChooseAbilities();
	}

	virtual void Reset();

private:
	void ChooseAbilities() {
		// Ask the player to choose 2 abilities
		
		// Add the first ability in the class list to myAbilities first
	}
};

class Enemy : GenericCharacter {
public:
	unsigned int _minHealth;

	Enemy(string _name) : GenericCharacter(_name) {
		type = CharacterType::ENEMY;
		icon = '-';

		_minHealth = 20;

		srand(time(nullptr));
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