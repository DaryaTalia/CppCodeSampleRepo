#pragma once

#include <string>
#include "Abilities.h"
#include <vector>

using std::string;
using std::vector;

class AbstractClass {
public:
	string name;
	vector<AbstractAbility*> GetAbilityList() {
		return _abilityList;
	}

private:
	vector<AbstractAbility*> _abilityList;
};

class Bard : public AbstractClass {
	Bard() {
		GetAbilityList().push_back(new CounterSong());
		GetAbilityList().push_back(new ForeverPoem());
		GetAbilityList().push_back(new SisterLullaby());
		GetAbilityList().push_back(new WorldLastRhapsody());
		GetAbilityList().push_back(new Crossbow());
		GetAbilityList().push_back(new PeakPerformance());
	}
	~Bard() {
		GetAbilityList().clear();
	}
};

class Cleric : public AbstractClass {
	Cleric() {
		GetAbilityList().push_back(new FriendshipShield());
		GetAbilityList().push_back(new HoneySpell());
		GetAbilityList().push_back(new GuidingLight());
		GetAbilityList().push_back(new Madness());
		GetAbilityList().push_back(new Protection());
		GetAbilityList().push_back(new LoveBane());
	}
	~Cleric() {
		GetAbilityList().clear();
	}

};

class Fighter : public AbstractClass {
	Fighter() {
		GetAbilityList().push_back(new Scimitar());
		GetAbilityList().push_back(new Warhammer());
		GetAbilityList().push_back(new Longbow());
		GetAbilityList().push_back(new IronDefense());
		GetAbilityList().push_back(new Olympian());
		GetAbilityList().push_back(new Revenger());
	}
	~Fighter() {
		GetAbilityList().clear();
	}

};

class Ranger : public AbstractClass {
	Ranger() {
		GetAbilityList().push_back(new Longbow());
		GetAbilityList().push_back(new Shortsword());
		GetAbilityList().push_back(new BefriendBear());
		GetAbilityList().push_back(new ExploreSurroundings());
		GetAbilityList().push_back(new PoisonedBerries());
		GetAbilityList().push_back(new SolarEclipse());
	}
	~Ranger() {
		GetAbilityList().clear();
	}

};

class Rogue : public AbstractClass {
	Rogue() {
		GetAbilityList().push_back(new Shortsword());
		GetAbilityList().push_back(new Pickpocket());
		GetAbilityList().push_back(new Riposte());
		GetAbilityList().push_back(new Sneak());
		GetAbilityList().push_back(new Crossbow());
		GetAbilityList().push_back(new ChangeClothes());
	}
	~Rogue() {
		GetAbilityList().clear();
	}

};

class Wizard : public AbstractClass {
	Wizard() {
		GetAbilityList().push_back(new WaterBlast());
		GetAbilityList().push_back(new AcidSkin());
		GetAbilityList().push_back(new ConjureSword());
		GetAbilityList().push_back(new SummonCat());
		GetAbilityList().push_back(new BrokenClock());
		GetAbilityList().push_back(new VineBound());
	}
	~Wizard() {
		GetAbilityList().clear();
	}

};