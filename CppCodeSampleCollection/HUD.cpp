#include "HUD.h"
#include "Inventory.h"
#include "Item.h"
#include "Player.h"

#include <cstdlib>
#include <string>

using std::string;
using std::stoi;
using std::stof;
using std::to_string;

string HUD::PrintInventory(Inventory accessInventory) {
    string inventoryList = "";

    inventoryList += "\nCurrent Inventory\n";
    inventoryList += "\n--------------------\n";
    if (accessInventory.GetTotalItems() > 0) {
        inventoryList += "\n";
        Item currentItem = accessInventory.GetHeadItem();

        while (!currentItem.CompareNullItem(currentItem)) {
            inventoryList += currentItem.GetItemName();
            inventoryList += ". Quantity: ";
            inventoryList += currentItem.GetItemQuantity();
            inventoryList += ". Description: ";
            inventoryList += currentItem.GetItemDescription();
            inventoryList += "\n";

            currentItem = currentItem.GetNextItem();
        }

        inventoryList += "\n--------------------\n\n";
    }
    else {
        inventoryList += "\nNo items in inventory.\n";
        inventoryList += "\n--------------------\n\n";
    }

    return inventoryList;
}//end PrintInventory

string HUD::PrintWellness(Player accessPlayer) {
    string wellnessList = "";

    wellnessList += "\nCurrent Wellness\n";
    wellnessList += "\n--------------------\n\n";
    wellnessList += "Health: "; 
    wellnessList += to_string(accessPlayer.GetHealth());
    wellnessList += "\n";
    wellnessList += "Stamina: ";
    wellnessList += to_string(accessPlayer.GetStamina());
    wellnessList += "\n";
    wellnessList += "\n--------------------\n\n";

    return wellnessList;
}//end PrintWellness