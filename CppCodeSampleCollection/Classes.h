#include <string>
#include <vector>

#include "Abilities.h"

using namespace std;

#ifndef CLASSES_H
#define CLASSES_H

using std::vector;

class AbstractClass {
public:
	string name;
	string description;

	AbstractClass();
	~AbstractClass();

	vector<AbstractAbility*>* GetAbilityList();

private:
	vector<AbstractAbility*> _abilityList;
};

class Bard : public AbstractClass {
public:
	Bard();
	~Bard();
};

class Cleric : public AbstractClass {
public:
	Cleric();
	~Cleric();
};

class Fighter : public AbstractClass {
public:
	Fighter();
	~Fighter();
};

class Ranger : public AbstractClass {
public:
	Ranger();
	~Ranger();
};

class Rogue : public AbstractClass {
public:
	Rogue();
	~Rogue();
};

class Wizard : public AbstractClass {
public:
	Wizard();
	~Wizard();
};

#endif