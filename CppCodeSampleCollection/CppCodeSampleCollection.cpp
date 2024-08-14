// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Hero's Inventory
const int MAX_ITEMS = 10;
string inventory[MAX_ITEMS];
int numItems = 0;


void DisplayItems() {
    cout << "\nYour items:\n";
    for (int i = 0; i < numItems; ++i) {
        cout << inventory[i] << endl;
    }
}//end display items 

void AddItem(string itemName) {
    if (numItems < MAX_ITEMS) {
        inventory[numItems++] = itemName;
    }
    else {
        cout << "\nYou have too many items and can't carry another.";
    }
}//end add item


int main() {    
    inventory[numItems++] = "sword";
    inventory[numItems++] = "armor";
    inventory[numItems++] = "shield";

    DisplayItems();

    cout << "\nYou trade your sword for a battleaxe.";
    inventory[0] = "battleaxe";

    DisplayItems();

    cout << "\nThe item name '" << inventory[0] << "' has ";
    cout << inventory[0].size() << " letters in it.\n";

    cout << "You find a healing potion.";
    AddItem("healing potion");

    DisplayItems();

    cout << endl;

    return 0;
}
