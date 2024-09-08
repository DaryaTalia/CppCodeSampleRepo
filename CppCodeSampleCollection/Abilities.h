#pragma once
#include <string>
#include <vector>
#include "Game.h"
#include "Characters.h"

using std::string;
using std::vector;

class AbstractAbility {
public:
	virtual void Activate(Round& _round) = 0;

	unsigned int abilityTimer = 0;
	unsigned int maxTimer = 0;
	string description;
	vector<GenericCharacter*> targets;
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
	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round);
	virtual void DecreaseAttack(Round& _round) {}; // Invalid

};

class ForeverPoem : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void FreezeHealth(Round& _round);
	virtual void IncreaseHealth(Round& _round) {}; // Invalid
	virtual void DecreaseHealth(Round& _round) {}; // Invalid

};

class SisterLullaby : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {}; // Invalid
	virtual void DecreaseHealth(Round& _round) {}; // Invalid
	virtual void FreezeHealth(Round& _round);

};

class WorldLastRhapsody : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round);
	virtual void DecreaseHealth(Round& _round) {}; // Invalid
	virtual void FreezeHealth(Round& _round) {}; // Invalid

};

class Crossbow : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};

};

class PeakPerformance : public iAttack, public iTurn {
public:
	virtual void Activate(Round& _round);
	virtual void SkipTurn(Round& _round) {}; // Invalid
	virtual void HideTurn(Round& _round);
	virtual void IncreaseAttack(Round& _round);
	virtual void DecreaseAttack(Round& _round) {}; // Invalid

};

class FriendshipShield : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round);
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round) {};

};

class HoneySpell : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round);
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round) {};

};

class GuidingLight : public iHealth, public iAttack {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round);
	virtual void DecreaseAttack(Round& _round) {};
	virtual void IncreaseHealth(Round& _round);
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round) {};

};

class Madness : public iTurn {
public:
	virtual void Activate(Round& _round);
	virtual void SkipTurn(Round& _round);
	virtual void HideTurn(Round& _round) {};

};

class Protection : public iTurn {
public:
	virtual void Activate(Round& _round);
	virtual void HideTurn(Round& _round);
	virtual void SkipTurn(Round& _round) {};

};

class LoveBane : public iAttack {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round) {};
	virtual void DecreaseAttack(Round& _round);

};

class Scimitar : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};

};

class Warhammer : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};

};

class Longbow : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};

};

class IronDefense : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round);

};

class Olympian : public iAttack {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round);
	virtual void DecreaseAttack(Round& _round) {};

};

class Revenger : public iAttack {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round) {};
	virtual void DecreaseAttack(Round& _round);

};

class Shortsword : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};

};

class BefriendBear : public iAttack {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round);
	virtual void DecreaseAttack(Round& _round) {};

};

class ExploreSurroundings : public iHealth, public iAttack {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round);
	virtual void DecreaseAttack(Round& _round) {};
	virtual void IncreaseHealth(Round& _round);
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round) {};

};

class PoisonedBerries : public iAttack {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round) {};
	virtual void DecreaseAttack(Round& _round);

};

class SolarEclipse : public iAttack {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round) {};
	virtual void DecreaseAttack(Round& _round);

};

class Pickpocket : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round);
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round) {};

};

class Riposte : public iAttack {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseAttack(Round& _round);
	virtual void DecreaseAttack(Round& _round) {};

};

class Sneak : public iTurn {
public:
	virtual void Activate(Round& _round);
	virtual void SkipTurn(Round& _round) {};
	virtual void HideTurn(Round& _round);

};

class ChangeClothes : public iTurn {
public:
	virtual void Activate(Round& _round);
	virtual void SkipTurn(Round& _round) {};
	virtual void HideTurn(Round& _round);

};

class WaterBlast : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};

};

class AcidSkin : public iHealth, public iAttack {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};
	virtual void IncreaseAttack(Round& _round) {};
	virtual void DecreaseAttack(Round& _round);

};

class ConjureSword : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round);
	virtual void FreezeHealth(Round& _round) {};

};

class SummonCat : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round);
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round) {};

};

class BrokenClock : public iHealth {
public:
	virtual void Activate(Round& _round);
	virtual void IncreaseHealth(Round& _round) {};
	virtual void DecreaseHealth(Round& _round) {};
	virtual void FreezeHealth(Round& _round);

};

class VineBound : public iTurn {
public:
	virtual void Activate(Round& _round);
	virtual void SkipTurn(Round& _round);
	virtual void HideTurn(Round& _round) {};

};
