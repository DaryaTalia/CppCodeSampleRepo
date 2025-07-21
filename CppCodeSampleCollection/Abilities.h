#include <string>
#include <vector>

using namespace std;

#ifndef ABILITIES_H
#define ABILITIES_H

class Round;
class GenericCharacter;

using std::vector;

class AbstractAbility {
public:
	virtual void Activate(Round& _round) = 0;

	unsigned int abilityTimer = 0;
	unsigned int maxTimer = 0;
	std::string name;
	std::string description;
	std::vector<GenericCharacter*> targets;
};

class iHealth : virtual public AbstractAbility {
public:
	virtual void IncreaseHealth(Round& _round) = 0;
	virtual void DecreaseHealth(Round& _round) = 0;
	virtual void FreezeHealth(Round& _round) = 0;

private:
	unsigned int _healingAmount;
	unsigned int _bonusHealth;
};

class iTurn : virtual public AbstractAbility {
public:
	virtual void SkipTurn(Round& _round) = 0;
	virtual void HideTurn(Round& _round) = 0;

private:
	unsigned int _maxTurns;
	unsigned int _turns;
};

class iAttack : virtual public AbstractAbility {
public:
	virtual void IncreaseAttack(Round& _round) = 0;
	virtual void DecreaseAttack(Round& _round) = 0;

private:
	unsigned int _attackDamage;
	unsigned int _bonusDamage;
};

class CounterSong : public iAttack {
public:
	CounterSong();
	~CounterSong();

	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round);
	virtual void DecreaseAttack(Round& _round) {}; // Invalid

};

class ForeverPoem : public iHealth {
public:
	ForeverPoem();
	~ForeverPoem();

	virtual void Activate(Round& _round);
	virtual void FreezeHealth(Round& _round);
	virtual void IncreaseHealth(Round& _round) {}; // Invalid
	virtual void DecreaseHealth(Round& _round) {}; // Invalid

};

class SisterLullaby : public iHealth {
public:
	SisterLullaby();
	~SisterLullaby();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {}; // Invalid
	virtual void DecreaseHealth(Round& _round) {}; // Invalid
	virtual void FreezeHealth(Round& _round);

};

class WorldLastRhapsody : public iHealth {
public:
	WorldLastRhapsody();
	~WorldLastRhapsody();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round);
	virtual void DecreaseHealth(Round& _round) {}; // Invalid
	virtual void FreezeHealth(Round& _round) {}; // Invalid

};

class Crossbow : public iHealth {
public:
	Crossbow();
	~Crossbow();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};

};

class PeakPerformance : public iAttack, public iTurn {
public:
	PeakPerformance();
	~PeakPerformance();

	virtual void Activate(Round& _round);
	virtual void SkipTurn(Round& _round) {}; // Invalid
	virtual void HideTurn(Round& _round);
	virtual void IncreaseAttack(Round& _round);
	virtual void DecreaseAttack(Round& _round) {}; // Invalid

};

class FriendshipShield : public iHealth {
public:
	FriendshipShield();
	~FriendshipShield();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round);
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round) {};

};

class HoneySpell : public iHealth {
public:
	HoneySpell();
	~HoneySpell();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round);
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round) {};

};

class GuidingLight : public iHealth, public iAttack {
public:
	GuidingLight();
	~GuidingLight();

	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round);
	virtual void DecreaseAttack(Round& _round) {};
	virtual void IncreaseHealth(Round& _round);
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round) {};

};

class Madness : public iTurn {
public:
	Madness();
	~Madness();

	virtual void Activate(Round& _round);
	virtual void SkipTurn(Round& _round);
	virtual void HideTurn(Round& _round) {};

};

class Protection : public iTurn {
public:
	Protection();
	~Protection();

	virtual void Activate(Round& _round);
	virtual void HideTurn(Round& _round);
	virtual void SkipTurn(Round& _round) {};

};

class LoveBane : public iAttack {
public:
	LoveBane();
	~LoveBane();

	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round) {};
	virtual void DecreaseAttack(Round& _round);

};

class Scimitar : public iHealth {
public:
	Scimitar();
	~Scimitar();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};

};

class Warhammer : public iHealth {
public:
	Warhammer();
	~Warhammer();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};

};

class Longbow : public iHealth {
public:
	Longbow();
	~Longbow();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};

};

class IronDefense : public iHealth {
public:
	IronDefense();
	~IronDefense();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round);

};

class Olympian : public iAttack {
public:
	Olympian();
	~Olympian();

	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round);
	virtual void DecreaseAttack(Round& _round) {};

};

class Revenger : public iAttack {
public:
	Revenger();
	~Revenger();

	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round) {};
	virtual void DecreaseAttack(Round& _round);

};

class Shortsword : public iHealth {
public:
	Shortsword();
	~Shortsword();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};

};

class BefriendBear : public iAttack {
public:
	BefriendBear();
	~BefriendBear();

	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round);
	virtual void DecreaseAttack(Round& _round) {};

};

class ExploreSurroundings : public iHealth, public iAttack {
public:
	ExploreSurroundings();
	~ExploreSurroundings();

	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round);
	virtual void DecreaseAttack(Round& _round) {};
	virtual void IncreaseHealth(Round& _round);
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round) {};

};

class PoisonedBerries : public iAttack {
public:
	PoisonedBerries();
	~PoisonedBerries();

	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round) {};
	virtual void DecreaseAttack(Round& _round);

};

class SolarEclipse : public iAttack {
public:
	SolarEclipse();
	~SolarEclipse();

	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round) {};
	virtual void DecreaseAttack(Round& _round);

};

class Pickpocket : public iHealth {
public:
	Pickpocket();
	~Pickpocket();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round);
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round) {};

};

class Riposte : public iAttack {
public:
	Riposte();
	~Riposte();

	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round);
	virtual void DecreaseAttack(Round& _round) {};

};

class Sneak : public iTurn {
public:
	Sneak();
	~Sneak();

	virtual void Activate(Round& _round);
	virtual void SkipTurn(Round& _round) {};
	virtual void HideTurn(Round& _round);

};

class ChangeClothes : public iTurn {
public:
	ChangeClothes();
	~ChangeClothes();

	virtual void Activate(Round& _round);
	virtual void SkipTurn(Round& _round) {};
	virtual void HideTurn(Round& _round);

};

class WaterBlast : public iHealth {
public:
	WaterBlast();
	~WaterBlast();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};

};

class AcidSkin : public iHealth, public iAttack {
public:
	AcidSkin();
	~AcidSkin();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};
	virtual void IncreaseAttack(Round& _round) {};
	virtual void DecreaseAttack(Round& _round);

};

class ConjureSword : public iHealth {
public:
	ConjureSword();
	~ConjureSword();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};

};

class SummonCat : public iHealth {
public:
	SummonCat();
	~SummonCat();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round);
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round) {};

};

class BrokenClock : public iHealth {
public:
	BrokenClock();
	~BrokenClock();

	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round);

};

class VineBound : public iTurn {
public:
	VineBound();
	~VineBound();

	virtual void Activate(Round& _round);
	virtual void SkipTurn(Round& _round);
	virtual void HideTurn(Round& _round) {};

};

#endif