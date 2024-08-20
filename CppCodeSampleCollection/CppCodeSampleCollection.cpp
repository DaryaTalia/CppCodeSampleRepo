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

// Inventory Referencer

// Constant reference, restricted reference
// Efficient, protects the original variable
void display(const vector<string>& inventory);
// Returning a reference, or "nickname" to another object
string& refToElement(vector<string>& inventory, int i);

int main() { 
    bool playAgain = true;
    char play;

    int myScore = 150;
    int yourScore = 1000;

    while (playAgain) {
        // App
        vector<string> inventory;
        inventory.push_back("switch");
        inventory.push_back("mario kart");
        inventory.push_back("breath of the wild");

        cout << "Sending the returned reference to cout:\n";
        cout << refToElement(inventory, 0) << "\n\n";

        cout << "Assigning the returned reference to another reference.\n";
        string& rStr = refToElement(inventory, 1);
        cout << "Sending the new reference to cout:\n";
        cout << rStr << "\n\n";

        cout << "Assigning the returned reference to a string object.\n";
        // Copies inventory[2] to the string object str using the returned reference
        string str = refToElement(inventory, 2);
        cout << "Sending the new reference to cout:\n";
        cout << str << "\n\n";

        cout << "Altering an object through a returned reference.\n";
        rStr = "sonic unleashed";
        cout << "Sending the altered object to cout: \n";
        cout << inventory[1] << endl;

        cout << endl;

        display(inventory);

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

void display(const vector<string>& vec) {
    cout << "Your items:\n";
    for (vector<string>::const_iterator iter = vec.begin(); iter != vec.end(); iter++) {
        cout << *iter << endl;
    }
    cout << endl;
}

// Never return a reference to a local variable, out-of-scope objects
string& refToElement(vector<string>& vec, int i) {
    return vec[i];
}