// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Player.h"
#include "Inventory.h"
#include "HUD.h"

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

Player playerOne;
HUD gameplayHUD;

int main() { 
    playerOne = Player();
    gameplayHUD = HUD();

    gameplayHUD.PrintInventory(*playerOne.GetInventory());

    playerOne.GetInventory()->AddInventoryItem("Vine Melon", 1);
    Item* vineMelon = new Item();
    *vineMelon = playerOne.GetInventory()->GetItem("Vine Melon");

    playerOne.GetInventory()->AddInventoryDescription(vineMelon, "Vegetable. Fairly Tasty. Moderate Stamina Recovery.");
    playerOne.GetInventory()->SetInventoryQuantity(vineMelon, 3);

    gameplayHUD.PrintInventory(*playerOne.GetInventory());

    gameplayHUD.PrintWellness(playerOne);

    playerOne.DamageHealth(1000);

    gameplayHUD.PrintWellness(playerOne);

    cout << endl;

    return 0;
}
