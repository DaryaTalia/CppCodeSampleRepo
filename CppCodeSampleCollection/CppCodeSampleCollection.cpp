// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// Hero's Inventory 2.0

int main() { 
    vector<string> inventory;
    inventory.push_back("staff");
    inventory.push_back("robe");
    inventory.push_back("amulet");

    cout << "You have " << inventory.size() << " items.\n";

    cout << "\nYour items:\n";
    for (unsigned int i = 0; i < inventory.size(); i++) {
        cout << inventory[i] << endl;
    }

    cout << "\nYou trade your staff for a wand. \n";
    inventory[0] = "wand";
    cout << "\nYour items:\n";
    for (unsigned int i = 0; i < inventory.size(); i++) {
        cout << inventory[i] << endl;
    }

    cout << "\nThe item name '" << inventory[0] << "' has ";
    cout << inventory[0].size() << " letters in it.\n";

    cout << "\nYour amulet is destroyed in a fierce battle. \n";
    inventory.pop_back();
    cout << "\nYour items:\n";
    for (unsigned int i = 0; i < inventory.size(); i++) {
        cout << inventory[i] << endl;
    }

    cout << "\nYou were robbed of all of your possesions by a thief. \n";
    inventory.clear();
    cout << "\nYour items:";
    if (inventory.empty()) {
        cout << "\nYou have nothing.\n";
    }
    else {
        cout << "\nYou have at least one item.\n";
    }

    cout << endl;

    return 0;
}
