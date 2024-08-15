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
using std::stoi;
using std::stof;
using std::to_string;

// Metal Gear Solid 3 as C++ Objects

//////////////////
// Data Members

#define NAME
#ifdef NAME
const string name = "Jack";
const string codename1 = "Naked Snake";
const string codename2 = "Big Boss";
const string codename3 = "Snake";
#endif 

#define INVENTORY
#ifdef INVENTORY
enum Inventory_Properties { item_name, item_quantity, item_description };
const int MAX_ITEMS = 10;
int totalItems = 0;
string inventory[MAX_ITEMS][3];
#endif 

#define CURING
#ifdef CURING

#define HEALTH
#ifdef HEALTH
const float MAX_HEALTH = 100.0;
float _health = 100.0;
#endif 

#define STAMINA
#ifdef STAMINA
const float MAX_STAMINA = 100.0;
float _stamina = 100.0;
#endif 
#define INJURY
#ifdef INJURY
enum Injury_Types { arrow_bolt, broken_bone, burn, cut, gunshot_wound, hypodermic_needle, leech, no_injury }; //rows
enum Injury_Tools { survival_knife, cigar, ointment, disinfectant, styptic, plint, bandage, suture_kit }; // columns

const bool injury_chart[7][8] = 
{// survival_knife, cigar, ointment, disinfectant, styptic, plint, bandage, suture_kit
    { {true}, {false}, {false}, {false}, {false}, {false}, {true}, {false} }, // arrow_bolt
    { {false}, {false}, {false}, {false}, {false}, {true}, {true}, {false} }, // broken_bone
    { {false}, {false}, {true}, {false}, {false}, {false}, {true}, {false} }, // burn
    { {false}, {false}, {false}, {true}, {true}, {false}, {true}, {true} }, // cut
    { {true}, {false}, {false}, {true}, {true}, {false}, {true}, {false} }, // gunshot_wound
    { {true}, {false}, {false}, {false}, {false}, {false}, {false}, {false} }, // hypodermic_needle
    { {false}, {true}, {false}, {false}, {false}, {false}, {false}, {false} }  // leech
};
#endif INJURY

#define AILMENT
#ifdef AILMENT
enum Ailment_Types { cold, food_poisoning, stomach_sickness, venom_poisoning, no_ailment }; //rows
enum Ailment_Tools { serum, cold_medicine, antidote, digestive_medicine }; // columns

const Ailment_Tools ailment_chart[4] =
{
    // cold, food_poisoning, stomach_sickness, venom_poisoning
    {cold_medicine}, {antidote}, {digestive_medicine}, {serum}
};
#endif AILMENT

#endif 

#define STEALTH
#ifdef STEALTH
const int MAX_CAMO_INDEX = 100;
const int MIN_CAMO_INDEX = 0;
int _camoIndex = 30;

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
#endif 

//////////////////////
// Member Functions

#ifdef INVENTORY
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

bool SetInventoryQuantity(string itemName, int newQuantity) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i][item_name] == itemName) {
            inventory[i][item_quantity] = to_string(newQuantity);
            return true;
        }
    }
    return false;
}//end SetInventoryQuantity

bool IncrementInventoryQuantity(string itemName, int value) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i][item_name] == itemName) {
            int _itemQuantity = stoi(inventory[i][item_quantity]);
            _itemQuantity += value;
            inventory[i][item_quantity] = to_string(_itemQuantity);
            return true;
        }
    }
    return false;
}//end IncrementInventoryQuantity

bool DecrementInventoryQuantity(string itemName, int value) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i][item_name] == itemName) {
            int _itemQuantity = stoi(inventory[i][item_quantity]);
            _itemQuantity -= value;
            inventory[i][item_quantity] = to_string(_itemQuantity);
            return true;
        }
    }
    return false;
}//end DecrementInventoryQuantity

string GetInventoryQuantity(string itemName, string newQuantity) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (inventory[i][item_name] == itemName) {
            return inventory[i][item_quantity];
        }
    }
    return "\nNot Item Quantity Found\n";
}//end GetInventoryQuantity
#endif 

#ifdef HEALTH
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
#endif

#ifdef STAMINA
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
#endif

#ifdef STEALTH
void DetermineCamoStatus() {
    if (_camoIndex == Invisible) {
        camoStatus = Invisible;
    } else if (_camoIndex < Invisible && _camoIndex >= Hidden) {
        camoStatus = Hidden;
    }
    else if (_camoIndex < Hidden && _camoIndex >= Semihidden) {
        camoStatus = Semihidden;
    }
    else if (_camoIndex < Semihidden && _camoIndex >= Unhidden) {
        camoStatus = Unhidden;
    }
}//end DetermineCamoStatus

int GetCamoIndex() {
    return _camoIndex;
}//end GetCamoIndex

void SetCamoIndex(int value) {
    _camoIndex = value;
    if (GetCamoIndex() > MAX_CAMO_INDEX) {
        SetCamoIndex(MAX_CAMO_INDEX);
    } 
    else if (GetCamoIndex() < MIN_CAMO_INDEX) {
        SetCamoIndex(MIN_CAMO_INDEX);
    }
}//end setcamoindex

bool IncrementCamoIndex(int value) {
    if (GetCamoIndex() < MAX_CAMO_INDEX) {
        SetCamoIndex(GetCamoIndex() + value);
        return true;
    }
    return false;
}//end IncrementCamoIndex

bool DecrementCamoIndex(int value) {
    if (GetCamoIndex() > MIN_CAMO_INDEX) {
        SetCamoIndex(GetCamoIndex() - value);
        return true;
    }
    return false;
}//end DecrementCamoIndex
#endif

#define HUD
#ifdef HUD
void PrintInventory() {
    string inventoryList = "";

    inventoryList += "\nCurrent Inventory\n";
    inventoryList += "\n--------------------\n";
    if (totalItems > 0) {
        inventoryList += "\n";
        for (int i = 0; i < totalItems; i++) {
            inventoryList += inventory[i][0];
            inventoryList += ". Quantity: ";
            inventoryList += inventory[i][1];
            inventoryList += ". Description: ";
            inventoryList += inventory[i][2];
            inventoryList += "\n";
        }
        inventoryList += "\n--------------------\n\n";
    }
    else {
        inventoryList += "\nNo items in inventory.\n";
        inventoryList += "\n--------------------\n\n";
    }

    cout << inventoryList;
}//end PrintInventory

void PrintWellness() {
    string wellnessList = "";

    wellnessList += "\nCurrent Wellness\n";
    wellnessList += "\n--------------------\n\n";
    wellnessList += "Health: ";
    wellnessList += to_string(GetHealth());
    wellnessList += "\n";
    wellnessList += "Stamina: ";
    wellnessList += to_string(GetStamina());
    wellnessList += "\n";
    wellnessList += "\n--------------------\n\n";

    cout << wellnessList;
}//end PrintWellness

#endif

  ///////////////////////////////////////////////////////////////
 ///////////////////////     MAIN()     ////////////////////////
///////////////////////////////////////////////////////////////

#ifdef HEALTH
int main() { 
    PrintInventory();

    AddInventoryItem("Vine Melon");
    AddInventoryDescription("Vine Melon", "Vegetable. Fairly Tasty. Moderate Stamina Recovery.");
    SetInventoryQuantity("Vine Melon", 3);

    PrintInventory();

    PrintWellness();

    DamageHealth(1000);

    PrintWellness();

    cout << endl;

    return 0;
}
#endif
