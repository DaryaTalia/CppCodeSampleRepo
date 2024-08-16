// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include "Player.h"

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


//#define HUD
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
    //wellnessList += to_string(GetHealth());
    wellnessList += "\n";
    wellnessList += "Stamina: ";
    //wellnessList += to_string(GetStamina());
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
