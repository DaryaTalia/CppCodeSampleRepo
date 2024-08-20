// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Swap Pointer

void badSwap(int x, int y);
// pX and pY are constant pointers that accept memory addresses (&)
void goodSwap(int* const pX, int* const pY);

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
        // to pass a pointer, pass the address of the object
        goodSwap(&myScore, &yourScore);
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
        // pX and pY store addresses of the passed objects
        // the addresses can be used to manipulate the values stored there
        void goodSwap(int* const pX, int* const pY) {
            int temp = *pX;
            *pX = *pY;
            *pY = temp;
        }