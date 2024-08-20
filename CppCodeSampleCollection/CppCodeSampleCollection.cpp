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

// Inventory Pointer

// Returning a <string> pointer
string* ptrToElement(vector<string>* const pVec, int i);

int main() {
    bool playAgain = true;
    char play;

    int myScore = 150;
    int yourScore = 1000;

    while (playAgain) {
        // App
        vector<string> inventory;
        inventory.push_back("cup");
        inventory.push_back("book");
        inventory.push_back("sweet roll");

        cout << "Sending the object pointed to by returned pointer:\n";
        cout << *(ptrToElement(&inventory, 0)) << "\n\n";

        cout << "Assigning the returned pointer to another pointer.\n";
        string* pStr = ptrToElement(&inventory, 1);
        cout << "Sending the object pointed to by new pointer to cout:\n";
        cout << *pStr << "\n\n";

        cout << "Assigning object pointed by pointer to a string object.\n";
        string str = *(ptrToElement(&inventory, 2));
        cout << "Sending the object pointed to by new pointer to cout:\n";
        cout << str << "\n\n";

        cout << "Altering an object through a returned pointer.\n";
        *pStr = "iron sword";
        cout << "Sending the altered object to cout:\n";
        cout << inventory[1] << endl;

        // Play Again?
        play = ' ';

        while (play != 'y' && play != 'n') {
            cout << "Play Again? (y/n): ";
            cin >> play;
        }

        if (play == 'n') {
            playAgain = false;
        }

        cout << endl;
    }

    cout << endl;

    return 0;
}

string* ptrToElement(vector<string>* const pVec, int i) {
    // return the address of the element in the value of pVec at [i]
    return &((*pVec)[i]);
}
