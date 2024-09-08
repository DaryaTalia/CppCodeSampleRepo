#include "Abilities.h"

// TODO: Add a script for enemies to randomize player or enemy selections
// TODO: Differentiate between player turn and computer turn

// Counter Song

void CounterSong::Activate(Round& _round) {
	IncreaseAttack(_round);
}

void CounterSong::IncreaseAttack(Round& _round) {
	// Use IncreaseAttack() on an ally

	// Ask the player which ally they choose to increase their attack (not including active character)
	// Find that character 
	// Apply attack bonus to ally
	// Confirm ability
}

// Forever Poem

void ForeverPoem::Activate(Round& _round) {
	FreezeHealth(_round);
}

void ForeverPoem::FreezeHealth(Round& _round) {
	// Use FreezeHealth() on slef

	// Find the active character
	// Apply freeze health buff
	// Confirm ability
}

// Sister Lullaby

void SisterLullaby::Activate(Round& _round) {
	FreezeHealth(_round);
}

void SisterLullaby::FreezeHealth(Round& _round) {
	// Use Freeze Health() on any ally for set lifetime

	// Ask they player which ally they choose to freeze health (not including active character
	// Find that character
	// Apply the freeze health buff for set lifetime
	// Confirm ability
}

// World Last Rhapsody

void WorldLastRhapsody::Activate(Round& _round) {
	IncreaseHealth(_round);
}

void WorldLastRhapsody::IncreaseHealth(Round& _round) {
	// Use Increasehealth() on an ally

	// Ask the player which ally they choose to heal (not including active character)
	// Find that character 
	// Apply attack bonus to ally
	// Confirm ability
}

// Crossbow

void Crossbow::Activate(Round& _round) {
	DecreaseHealth(_round);
}

void Crossbow::DecreaseHealth(Round& _round) {
	// Use DecreaseHealth() on 1 enemy

	// Ask the player which enemy they choose to damage
	// Find that character 
	// Apply attack damage to enemy
	// Confirm ability
}

// Peak Performance

void PeakPerformance::Activate(Round& _round) {
	// Use HideTurn() and IncreaseAttack() on self

	HideTurn(_round);
	IncreaseAttack(_round);
}

void PeakPerformance::HideTurn(Round& _round) {
	// Apply HideTurn() to self
	// Confirm ability
}

void PeakPerformance::IncreaseAttack(Round& _round) {
	// Apply IncreaseAttack() to self
	// Confirm ability
}

// Friendship Shield

void FriendshipShield::Activate(Round& _round) {
	IncreaseHealth(_round);
}

void FriendshipShield::IncreaseHealth(Round& _round) {
	// Uses IncreaseHealth() on all allies

	// Appy healing amount to all allies (not including self)
	// Confirm ability
}

// Honey Spell

void HoneySpell::Activate(Round& _round) {
	IncreaseHealth(_round);
}

void HoneySpell::IncreaseHealth(Round& _round) {
	// Uses IncreaseHealth on any ally including self

	// Ask player which ally (including self) to heal
	// Find that player
	// Heal that player
	// Confirm ability
}

// Guiding Light

void GuidingLight::Activate(Round& _round) {
	// Ask player which ally (including self) they want to affect
	// Save to targets

	IncreaseAttack(_round);
	IncreaseHealth(_round);

	// Clear targets
}

void GuidingLight::IncreaseAttack(Round& _round) {
	// Increase attack of target
	// Confirm ability
}

void GuidingLight::IncreaseHealth(Round& _round) {
	// Increase health of target
	// Confirm ability
}

// Madness

void Madness::Activate(Round& _round) {
	SkipTurn(_round);
}

void Madness::SkipTurn(Round& _round) {
	// Uses SkipTurn() on any enemy for set lifetime

	// Ask player which enemy to affect
	// Apply SkipTurn trait and lifetime
	// Confirm ability
}

// Protection

void Protection::Activate(Round& _round) {
	HideTurn(_round);
}

void Protection::HideTurn(Round& _round) {
	// Uses HideTurn() on any ally for set lifetime

	// Ask player which ally (not including self) they want to affect
	// Apply HideTurn trait and lifetime on ally
	// Confirm ability
}

// LoveBane

void LoveBane::Activate(Round& _round) {
	DecreaseAttack(_round);
}

void LoveBane::DecreaseAttack(Round& _round) {
	// Uses DecreaseAttack() on all enemies for set lifetime

	// Apply DecreaseAttack on all enemies and add lifetimes for all
	// Confirm ability
}

// Scimitar

void Scimitar::Activate(Round& _round) {
	DecreaseHealth(_round);
}

void Scimitar::DecreaseHealth(Round& _round) {
	// Uses DecreaseHealth() on 1 enemy

	// Ask the player which enemy to decrease health on
	// Decrease the enemy's health
	// Confirm ability
}

// Warhammer

void Warhammer::Activate(Round& _round) {
	DecreaseHealth(_round);
}

void Warhammer::DecreaseHealth(Round& _round) {
	// Uses DecreaseHealth() on 1 enemy

	// Ask the player which enemy to decrease health on
	// Decrease the enemy's health
	// Confirm ability

}

// Longbow

void Longbow::Activate(Round& _round) {
	DecreaseHealth(_round);
}

void Longbow::DecreaseHealth(Round& _round) {
	// Uses DecreaseHealth() on 1 enemy

	// Ask the player which enemy to decrease health on
	// Decrease the enemy's health
	// Confirm ability

}

// Iron Defense

void IronDefense::Activate(Round& _round) {
	FreezeHealth(_round);
}

void IronDefense::FreezeHealth(Round& _round) {
	// Uses FreezeHealth() on self for set lifetime

	// Apply FreezeHealth to self and set lifetime
	// Confirm ability
}

// Olympian

void Olympian::Activate(Round& _round) {
	IncreaseAttack(_round);
}

void Olympian::IncreaseAttack(Round& _round) {
	// Uses IncreaseAttack() on self

	// Use IncreaseAttack on self
	// Confirm ability
}

// Revenger

void Revenger::Activate(Round& _round) {
	DecreaseAttack(_round);
}

void Revenger::DecreaseAttack(Round& _round) {
	// Uses DecreaseAttack() on 1 enemy

	// Ask the player which enemy to decrease health on
	// Decrease the enemy's health
	// Confirm ability

}

// Shortsword

void Shortsword::Activate(Round& _round) {
	DecreaseHealth(_round);
}

void Shortsword::DecreaseHealth(Round& _round) {
	// Uses DecreaseHealth() on 1 enemy

	// Ask the player which enemy to decrease health on
	// Decrease the enemy's health
	// Confirm ability

}

// Befriend Bear

void BefriendBear::Activate(Round& _round) {
	IncreaseAttack(_round);
}

void BefriendBear::IncreaseAttack(Round& _round) {
	// Uses IncreaseAttack() on self

	// Use IncreaseAttack on self
	// Confirm ability
}

// Explore Surroundings

void ExploreSurroundings::Activate(Round& _round) {
	// Ask player which ally (including self) they want to affect
	// Save to targets

	IncreaseAttack(_round);
	IncreaseHealth(_round);

	// Clear targets
}

void ExploreSurroundings::IncreaseAttack(Round& _round) {
	// Increase attack of target
	// Confirm ability
}

void ExploreSurroundings::IncreaseHealth(Round& _round) {
	// Increase health of target
	// Confirm ability
}

// Poisoned Berries

void PoisonedBerries::Activate(Round& _round) {
	DecreaseAttack(_round);
}

void PoisonedBerries::DecreaseAttack(Round& _round) {
	// Uses DecreaseAttack() on 1 enemy

	// Ask the player which enemy to decrease health on
	// Decrease the enemy's health
	// Confirm ability

}

// Solar Eclipse

void SolarEclipse::Activate(Round& _round) {
	DecreaseAttack(_round);
}

void SolarEclipse::DecreaseAttack(Round& _round) {
	// Uses DecreaseAttack() on all enemies for a set lifetime

	// Decrease all enemies' health and add lifetime to each
	// Confirm ability

}

// Pickpocket

void Pickpocket::Activate(Round& _round) {
	IncreaseHealth(_round);
}

void Pickpocket::IncreaseHealth(Round& _round) {
	// Uses IncreaseHealth on any ally including self

	// Ask player which ally (including self) to heal
	// Find that player
	// Heal that player
	// Confirm ability
}

// Riposte

void Riposte::Activate(Round& _round) {
	IncreaseAttack(_round);
}

void Riposte::IncreaseAttack(Round& _round) {
	// Uses IncreaseAttack() on self for set lifetime

	// Use IncreaseAttack on self and add lifetime
	// Confirm ability
}

// Sneak

void Sneak::Activate(Round& _round) {
	HideTurn(_round);
}

void Sneak::HideTurn(Round& _round) {
	// Uses HideTurn() on a self

	// Apply HideTurn trait
	// Confirm ability
}

// Change Clothes

void ChangeClothes::Activate(Round& _round) {
	HideTurn(_round);
}

void ChangeClothes::HideTurn(Round& _round) {
	// Uses HideTurn() on a self for set lifetime

	// Apply HideTurn trait and add lifetime
	// Confirm ability
}

// Water Blast

void WaterBlast::Activate(Round& _round) {
	DecreaseHealth(_round);
}

void WaterBlast::DecreaseHealth(Round& _round) {
	// Uses DecreaseHealth() on 1 enemy

	// Ask the player which enemy to decrease health on
	// Decrease the enemy's health
	// Confirm ability

}

// Acid Skin

void AcidSkin::Activate(Round& _round) {
	// Ask the player which enemy to decrease health and attack on
	// save to targets

	DecreaseHealth(_round);
	DecreaseAttack(_round);

	// clear targets
}

void AcidSkin::DecreaseHealth(Round& _round) {
	// Uses DecreaseHealth() on 1 enemy

	// Decrease the target's health
	// Confirm ability

}

void AcidSkin::DecreaseAttack(Round& _round) {
	// Uses DecreaseHealth() on 1 enemy

	// Decrease the target's health
	// Confirm ability

}


// Conjure Sword

void ConjureSword::Activate(Round& _round) {
	DecreaseHealth(_round);
}

void ConjureSword::DecreaseHealth(Round& _round) {
	// Uses DecreaseHealth() on 1 enemy

	// Ask the player which enemy to decrease health on
	// Decrease the enemy's health
	// Confirm ability

}

// Summon Cat

void SummonCat::Activate(Round& _round) {
	IncreaseHealth(_round);
}

void SummonCat::IncreaseHealth(Round& _round) {
	// Uses IncreaseHealth() on self

	// Increase health for active character
	// Confirm ability
}

// Broken Clock

void BrokenClock::Activate(Round& _round) {
	FreezeHealth(_round);
}

void BrokenClock::FreezeHealth(Round& _round) {
	// Uses FreezeHealth() on all allies over a set Lifetime

	// Freeze all allies and set lifetime
	// Confirm ability
}

// Vine Bound

void VineBound::Activate(Round& _round) {
	SkipTurn(_round);
}

void VineBound::SkipTurn(Round& _round) {
	// Uses SkipTurn() on 1 enemy over a set Lifetime

	// Ask the player which enemy to affect
	// Apply skip turn to that enemy
	// Confirm ability
}
