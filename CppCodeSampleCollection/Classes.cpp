#include "Classes.h"
#include <vector>
#include <iostream>

using namespace std;

using std::vector;


AbstractClass::AbstractClass() {
	this->name = "";
	this->_abilityList = {};
}

AbstractClass::~AbstractClass() {
	vector<AbstractAbility*>::iterator abilities = _abilityList.begin();
	while (abilities != _abilityList.end()) {
		*abilities = NULL;
		delete* abilities;
		++abilities;
	}
	_abilityList.clear();
}

vector<AbstractAbility*>* AbstractClass::GetAbilityList() {
	return &_abilityList;
}


Bard::Bard() {
	this->name = "Bard";
	this->description = "Poetic and Musical Magic";

	GetAbilityList()->emplace_back(new CounterSong());
	std::cout << "Bard(): Added CounterSong to Ability List: " << GetAbilityList()->at(0)->name << endl;
	GetAbilityList()->emplace_back(new ForeverPoem());
	GetAbilityList()->emplace_back(new SisterLullaby());
	GetAbilityList()->emplace_back(new WorldLastRhapsody());
	GetAbilityList()->emplace_back(new Crossbow());
	GetAbilityList()->emplace_back(new PeakPerformance());
}

Bard::~Bard() {
	GetAbilityList()->clear();
}



Cleric::Cleric() {
	name = "Cleric";
	description = "Chosen Mages of Deities";

	GetAbilityList()->emplace_back(new FriendshipShield());
	GetAbilityList()->emplace_back(new HoneySpell());
	GetAbilityList()->emplace_back(new GuidingLight());
	GetAbilityList()->emplace_back(new Madness());
	GetAbilityList()->emplace_back(new Protection());
	GetAbilityList()->emplace_back(new LoveBane());
}

Cleric::~Cleric() {
	GetAbilityList()->clear();
}


Fighter::Fighter() {
	name = "Fighter";
	description = "Masters of Combat";

	GetAbilityList()->emplace_back(new Scimitar());
	GetAbilityList()->emplace_back(new Warhammer());
	GetAbilityList()->emplace_back(new Longbow());
	GetAbilityList()->emplace_back(new IronDefense());
	GetAbilityList()->emplace_back(new Olympian());
	GetAbilityList()->emplace_back(new Revenger());
}

Fighter::~Fighter() {
	GetAbilityList()->clear();
}


Ranger::Ranger() {
	name = "Ranger";
	description = "Watchers of Dense Nature";

	GetAbilityList()->emplace_back(new Longbow());
	GetAbilityList()->emplace_back(new Shortsword());
	GetAbilityList()->emplace_back(new BefriendBear());
	GetAbilityList()->emplace_back(new ExploreSurroundings());
	GetAbilityList()->emplace_back(new PoisonedBerries());
	GetAbilityList()->emplace_back(new SolarEclipse());
}
Ranger::~Ranger() {
	GetAbilityList()->clear();
}


Rogue::Rogue() {
	name = "Rogue";
	description = "Manipulators of Stealth and Vulnerabilities";

	GetAbilityList()->emplace_back(new Shortsword());
	GetAbilityList()->emplace_back(new Pickpocket());
	GetAbilityList()->emplace_back(new Riposte());
	GetAbilityList()->emplace_back(new Sneak());
	GetAbilityList()->emplace_back(new Crossbow());
	GetAbilityList()->emplace_back(new ChangeClothes());
}

Rogue::~Rogue() {
	GetAbilityList()->clear();
}


Wizard::Wizard() {
	name = "Wizard";
	description = "Masters of Magic";

	GetAbilityList()->emplace_back(new WaterBlast());
	GetAbilityList()->emplace_back(new AcidSkin());
	GetAbilityList()->emplace_back(new ConjureSword());
	GetAbilityList()->emplace_back(new SummonCat());
	GetAbilityList()->emplace_back(new BrokenClock());
	GetAbilityList()->emplace_back(new VineBound());
}
Wizard::~Wizard() {
	GetAbilityList()->clear();
}

