// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Swap

void badSwap(int x, int y);
void goodSwap(int& x, int& y);

int main() { 
    bool playAgain = true;
    char play;

    int myScore = 150;
    int yourScore = 1000;

    while (playAgain) {
        // App
        cout << "Original values\n";
        cout << "myScore is: " << myScore << endl;
        cout << "yourScore is: " << yourScore << endl << endl;

        cout << "Calling badSwap()\n";
        badSwap(myScore, yourScore);
        cout << "myScore is: " << myScore << endl;
        cout << "yourScore is: " << yourScore << endl << endl;

        cout << "Calling goodSwap()\n";
        goodSwap(myScore, yourScore);
        cout << "myScore is: " << myScore << endl;
        cout << "yourScore is: " << yourScore << endl << endl;

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

// Pass by value
// Copies values only
void badSwap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// Pass by reference
// The parameters act as new references
// Access to original object
void goodSwap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
