#include "Classes.h"
#include <vector>
#include <iostream>

using namespace std;

using std::vector;


AbstractClass::AbstractClass() {
	name = "";
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

vector<AbstractAbility*> AbstractClass::GetAbilityList() {
	return _abilityList;
}


Bard::Bard() {
	name = "Bard";
	description = "Poetic and Musical Magic";

	GetAbilityList().push_back(new CounterSong());
	std::cout << "Bard(): Added CounterSong to Ability List: " << GetAbilityList().at(0)->name;
	GetAbilityList().push_back(new ForeverPoem());
	GetAbilityList().push_back(new SisterLullaby());
	GetAbilityList().push_back(new WorldLastRhapsody());
	GetAbilityList().push_back(new Crossbow());
	GetAbilityList().push_back(new PeakPerformance());
}

Bard::~Bard() {
	GetAbilityList().clear();
}



Cleric::Cleric() {
	name = "Cleric";
	description = "Chosen Mages of Deities";

	GetAbilityList().push_back(new FriendshipShield());
	GetAbilityList().push_back(new HoneySpell());
	GetAbilityList().push_back(new GuidingLight());
	GetAbilityList().push_back(new Madness());
	GetAbilityList().push_back(new Protection());
	GetAbilityList().push_back(new LoveBane());
}

Cleric::~Cleric() {
	GetAbilityList().clear();
}


Fighter::Fighter() {
	name = "Fighter";
	description = "Masters of Combat";

	GetAbilityList().push_back(new Scimitar());
	GetAbilityList().push_back(new Warhammer());
	GetAbilityList().push_back(new Longbow());
	GetAbilityList().push_back(new IronDefense());
	GetAbilityList().push_back(new Olympian());
	GetAbilityList().push_back(new Revenger());
}

Fighter::~Fighter() {
	GetAbilityList().clear();
}


Ranger::Ranger() {
	name = "Ranger";
	description = "Watchers of Dense Nature";

	GetAbilityList().push_back(new Longbow());
	GetAbilityList().push_back(new Shortsword());
	GetAbilityList().push_back(new BefriendBear());
	GetAbilityList().push_back(new ExploreSurroundings());
	GetAbilityList().push_back(new PoisonedBerries());
	GetAbilityList().push_back(new SolarEclipse());
}
Ranger::~Ranger() {
	GetAbilityList().clear();
}


Rogue::Rogue() {
	name = "Rogue";
	description = "Manipulators of Stealth and Vulnerabilities";

	GetAbilityList().push_back(new Shortsword());
	GetAbilityList().push_back(new Pickpocket());
	GetAbilityList().push_back(new Riposte());
	GetAbilityList().push_back(new Sneak());
	GetAbilityList().push_back(new Crossbow());
	GetAbilityList().push_back(new ChangeClothes());
}

Rogue::~Rogue() {
	GetAbilityList().clear();
}


Wizard::Wizard() {
	name = "Wizard";
	description = "Masters of Magic";

	GetAbilityList().push_back(new WaterBlast());
	GetAbilityList().push_back(new AcidSkin());
	GetAbilityList().push_back(new ConjureSword());
	GetAbilityList().push_back(new SummonCat());
	GetAbilityList().push_back(new BrokenClock());
	GetAbilityList().push_back(new VineBound());
}
Wizard::~Wizard() {
	GetAbilityList().clear();
}

