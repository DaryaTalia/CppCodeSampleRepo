
#include "Player.h"

#include <cstdlib>
#include <string>

using std::string;
using std::stoi;
using std::stof;
using std::to_string; 

Player::Player() {
    primaryInventory = new Inventory();
    DetermineCamoStatus();
}

Player::~Player() {

}

#define HEALTH
#ifdef HEALTH
float Player::GetHealth() {
    return _health;
}//end get health

bool Player::SetHealth(float newHealth) {
    _health = newHealth;

    if (_health > 0) {
        if (_health > MAX_HEALTH) {
            _health = MAX_HEALTH;
        }
        return true;
    }

    _health = 0;
    return false;
}//end set health

bool Player::HealHealth(float amount) {
    if (GetHealth() != MAX_HEALTH) {
        return SetHealth(_health + amount);
    }
    return false;
}//end heal health

bool Player::DamageHealth(float amount) {
    bool status = SetHealth(_health - amount);
    if (status) {
        //cout << "Still breathing...\n";
        return true;
    }
    string extendedE(5, 'e');
    //cout << codename3 << "? " << codename3 << "??? " << codename3 << extendedE << "!!!!!!\n";
    return true;
}//end damage health
#endif

#define STAMINA
#ifdef STAMINA
float Player::GetStamina() {
    return _stamina;
}//end get stamina

bool Player::SetStamina(float newStamina) {
    _stamina = newStamina;

    if (_stamina > 0) {
        if (_stamina > MAX_STAMINA) {
            _stamina = MAX_STAMINA;
        }
        return true;
    }

    _stamina = 0;
    return false;
}//end set stamina

bool Player::HealStamina(float amount) {
    if (GetStamina() != MAX_STAMINA) {
        return SetStamina(_stamina + amount);
    }
    return false;
}//end heal stamina

bool Player::DamageStamina(float amount) {
    bool status = SetStamina(_stamina - amount);
    if (status) {
        //cout << "Still breathing...\n";
        return true;
    }
    string extendedE(5, 'e');
    //cout << codename3 << "? " << codename3 << "??? " << codename3 << extendedE << "!!!!!!\n";
    return true;
}//end damage stamina
#endif

#define STEALTH
#ifdef STEALTH
void Player::DetermineCamoStatus() {
    if (_camoIndex == Camo_Status::Invisible) {
        _camoStatus = Camo_Status::Invisible;
    }
    else if (_camoIndex < Camo_Status::Invisible && _camoIndex >= Camo_Status::Hidden) {
        _camoStatus = Camo_Status::Hidden;
    }
    else if (_camoIndex < Camo_Status::Hidden && _camoIndex >= Camo_Status::Semihidden) {
        _camoStatus = Camo_Status::Semihidden;
    }
    else if (_camoIndex < Camo_Status::Semihidden && _camoIndex >= Camo_Status::Unhidden) {
        _camoStatus = Camo_Status::Unhidden;
    }
}//end DetermineCamoStatus

int Player::GetCamoIndex() {
    return _camoIndex;
}//end GetCamoIndex

void Player::SetCamoIndex(int value) {
    _camoIndex = value;
    if (GetCamoIndex() > MAX_CAMO_INDEX) {
        SetCamoIndex(MAX_CAMO_INDEX);
    }
    else if (GetCamoIndex() < MIN_CAMO_INDEX) {
        SetCamoIndex(MIN_CAMO_INDEX);
    }
}//end setcamoindex

bool Player::IncrementCamoIndex(int value) {
    if (GetCamoIndex() < MAX_CAMO_INDEX) {
        SetCamoIndex(GetCamoIndex() + value);
        return true;
    }
    return false;
}//end IncrementCamoIndex

bool Player::DecrementCamoIndex(int value) {
    if (GetCamoIndex() > MIN_CAMO_INDEX) {
        SetCamoIndex(GetCamoIndex() - value);
        return true;
    }
    return false;
}//end DecrementCamoIndex
#endif
