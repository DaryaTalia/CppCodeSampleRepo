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

// Hero's Inventory 3.0

int main() { 
    vector<string> inventory;
    inventory.push_back("staff");
    inventory.push_back("robe");
    inventory.push_back("amulet");

    vector<string>::iterator myIterator;
    vector<string>::const_iterator iter;

    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++) {
        cout << *iter << endl;
    }

    cout << "\nYou trade your staff for a wand. \n";
    myIterator = inventory.begin();
    *myIterator = "wand";
    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++) {
        cout << *iter << endl;
    }

    cout << "\nThe item name '" << *myIterator << "' has ";
    cout << (*myIterator).size() << " letters in it.\n";

    cout << "\nThe item name '" << *myIterator << "' has ";
    cout << myIterator->size() << " letters in it.\n";

    cout << "\nYou recover a spell book from a slain enemy. \n";
    inventory.insert(inventory.begin(), "spell book");
    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++) {
        cout << *iter << endl;
    }

    cout << "\nYour wand is destroyed in a fierce battle. \n";
    inventory.erase((inventory.begin() + 1));
    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++) {
        cout << *iter << endl;
    }

    cout << endl;

    return 0;
}
