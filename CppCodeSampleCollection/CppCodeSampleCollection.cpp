// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Referencing

int main() { 
    bool playAgain = true;
    char play;

    int myScore = 1000;
    // create a reference
    // MUST BE INITIALIZED
    // cannot be reassigned to another variable
    int& rMikesScore = myScore; 

    while (playAgain) {
        // App
        cout << "myScore is:" << myScore << endl;
        cout << "rMikesScore is:" << rMikesScore << endl << endl;

        cout << "Adding 500 to myScore \n";
        myScore += 500;

        cout << "myScore is: " << myScore << endl;
        cout << "rMikesScore is: " << rMikesScore << endl << endl;

        cout << "Adding 500 to mikesScore \n";
        rMikesScore += 500;

        cout << "myScore is: " << myScore << endl;
        cout << "rMikesScore is: " << rMikesScore << endl << endl;

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
