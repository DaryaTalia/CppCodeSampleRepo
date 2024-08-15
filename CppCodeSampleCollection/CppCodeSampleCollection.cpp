// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Metal Gear Solid 3 as C++ Objects

//////////////////
// Data Members

const string name = "Jack";
const string codename1 = "Naked Snake";
const string codename2 = "Big Boss";
const string codename3 = "Snake";

// Inventory

enum Inventory_Properties { item_name, item_quantity, item_description };
const int MAX_ITEMS = 10;
int totalItems = 0;
string inventory[MAX_ITEMS][3];

// Health & Stamina

const float MAX_HEALTH = 100.0;
float _health = 100.0;
const float MAX_STAMINA = 100.0;
float _stamina = 100.0;

// Camoflouge

const int MAX_CAMO_INDEX = 100;
const int MIN_CAMO_INDEX = 0;
int camoIndex = 30;

enum Camo_Status { Unhidden = 20, Semihidden = 50, Hidden = 80, Invisible = 100 };
Camo_Status camoStatus = Unhidden;

enum Camoflouge_Properties { camo_name, camo_type, camo_description, camo_status };
const int MAX_CAMO_ITEMS = 88;
string camoTypes[5] = {"Boss Camoflouge", "Uniforms", "Disguise", "Face Paint", "Special"};
string camoStatuses[2] = {"Not Collected", "Collected"};
string camoInventory[MAX_CAMO_ITEMS][4] =
{
    // Boss Camos
    { { "Animal" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },
    { { "Spirit" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },
    { { "Moss" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },
    { { "Spider" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },
    { { "Hornet Stripe" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },
    { { "Fire" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },
    { { "Cold War" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },
    { { "Snake" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },

    //Uniforms
    { { "Naked" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Tiger Stripe Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Olive Drab" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Leaf Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Tree Bark Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Squares Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Black Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Raindrop Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Chocolate Chip Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Splitter Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Snow Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Fly Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "GA-KO" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Water" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Sneaking Suit" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Banana Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Tuxedo" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Fruits" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Grenade" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Mummy" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Yodobashi" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Santa" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "New Years" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "St.Valentines" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Former West Germany" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Former East Germany" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "KLMK" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Urban Tiger" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Soviet Woodland" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "E-DEN" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Rainbow" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Anubis" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Rock" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Swamp" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Night Desert" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Watersnake" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Chameleon" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Barracuda" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Flower" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Festival" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Dododo" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Bonsai" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "USMX" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "DPM" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Desert Tiger" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Desert Auscam" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "WonderGOO" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Flecktarn" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Dododo" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Bonsai" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "USMX" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "DPM" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
    { { "Desert Tiger" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },

    //Disguises
    { { "Scientist" }, { camoTypes[2] }, { "Description" }, { camoStatuses[0] } },
    { { "Raikov's Uniform" }, { camoTypes[2] }, { "Description" }, { camoStatuses[0] } },
    { { "Maintenance" }, { camoTypes[2] }, { "Description" }, { camoStatuses[0] } },

    //Face Paints
    { { "No Paint" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Black" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Splitter" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Zombie" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Woodland" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Mask" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Infinite" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Kabuki" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Oyama" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Snow" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Desert" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Water" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Green" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Brown" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Soviet Union" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "United Kingdom" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "France" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Germany" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Italy" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Spain" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Sweden" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "Japan" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
    { { "USA" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },

    //Special
    { { "Stealth Camoflouge" }, { camoTypes[4] }, { "Description" }, { camoStatuses[0] } }
};
//"Boss Camoflouge"/"Uniforms"/"Disguise", "Face Paint", "Special"
string currentCamo[3] = {"", "", ""};


//////////////////////
// Member Functions

// Inventory

bool AddInventoryItem(string itemName) {
    if (totalItems < MAX_ITEMS) {
        inventory[totalItems++][item_name] = itemName;
        return true;
    }
    return false;
}//end AddInventoryItem

bool AddInventoryDescription(string itemName, string itemDescription) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i][item_name] == itemName) {
            inventory[i][item_description] = itemDescription;
            return true;
        }
    }
    return false;
}//end AddInventoryDescription

string GetInventoryDescription(string itemName, string itemDescription) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i][item_name] == itemName) {
            return inventory[i][item_description];
        }
    }
    return "\nNot Item Description Found\n";
}//end GetInventoryDescription

bool UpdateInventoryQuantity(string itemName, string newQuantity) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i][item_name] == itemName) {
            inventory[i][item_quantity] = newQuantity;
            return true;
        }
    }
    return false;
}//end UpdateInventoryQuantity

string GetInventoryQuantity(string itemName, string newQuantity) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i][item_name] == itemName) {
            return inventory[i][item_quantity];
        }
    }
    return "\nNot Item Quantity Found\n";
}//end GetInventoryQuantity

// Health

float GetHealth() {
    return _health;
}//end get health

bool SetHealth(float newHealth) {
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

bool HealHealth(float amount) {
    if (GetHealth() != MAX_HEALTH) {
        return SetHealth(_health + amount);
    }
    return false;
}//end heal health

bool DamageHealth(float amount) {
    bool status = SetHealth(_health - amount);
    if (status) {
        cout << "Still breathing...\n";
        return true;
    }
    string extendedE(5, 'e');
    cout << codename3 << "? " << codename3 << "??? " << codename3 << extendedE << "!!!!!!\n";
    return true;
}//end damage health

// Stamina

float GetStamina() {
    return _stamina;
}//end get stamina

bool SetStamina(float newStamina) {
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

bool HealStamina(float amount) {
    if (GetStamina() != MAX_STAMINA) {
        return SetStamina(_stamina + amount);
    }
    return false;
}//end heal stamina

bool DamageStamina(float amount) {
    bool status = SetStamina(_stamina - amount);
    if (status) {
        cout << "Still breathing...\n";
        return true;
    }
    string extendedE(5, 'e');
    cout << codename3 << "? " << codename3 << "??? " << codename3 << extendedE << "!!!!!!\n";
    return true;
}//end damage stamina

// Camoflouge

void DetermineCamoStatus() {
    if (camoIndex == Invisible) {
        camoStatus = Invisible;
    } else if (camoIndex < Invisible && camoIndex >= Hidden) {
        camoStatus = Hidden;
    }
    else if (camoIndex < Hidden && camoIndex >= Semihidden) {
        camoStatus = Semihidden;
    }
    else if (camoIndex < Semihidden && camoIndex >= Unhidden) {
        camoStatus = Unhidden;
    }
}//end DetermineCamoStatus


  ///////////////////////////////////////////////////////////////
 ///////////////////////     MAIN()     ////////////////////////
///////////////////////////////////////////////////////////////

int main() { 
    DamageHealth(1000);

    cout << endl;

    return 0;
}
