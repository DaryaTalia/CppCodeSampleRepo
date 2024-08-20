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

// Inventory Displayer

// Constant reference, restricted reference
// Efficient, protects the original variable
void display(const vector<string>& inventory);

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

//  If you need to assign a constant value to a reference, you have to assign the reference to a constant reference.