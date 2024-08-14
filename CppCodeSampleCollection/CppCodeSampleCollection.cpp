// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Guess My Number
int main()
{    
    srand(static_cast<unsigned int>(time(0))); //seed random number generator

    int secretNumber = rand() % 100 + 1;
    int tries = 0;
    int guess;

    cout << "\tWelcome to Guess My Number!\n\n";

    do {
        cout << "Enter a guess: ";
        cin >> guess;
        ++tries;

        if (guess > secretNumber) {
            cout << "Too high!\n\n";
        }
        else if (guess < secretNumber) {
            cout << "Too low!\n\n";
        }
        else {
            cout << "\nThat's it! You got it in " << tries << " guesses!\n";
        }
    }

    while (guess != secretNumber);

    return 0;
}

/*
Game Loop Fundamentals
-----------------------

Setup - Accept initial settings, load game assets, present player initial exposition

Get Player Input - Capture keyboard, mouse, joystick, trackball, or other device data from the player

Update Game Internals - Apply game logic, rules, and player input to the game world (physics, AI, etc.)

Update the Display - MOST TAXING!! Drawing graphics, or just text

Check Game State - If the game is over, end. If not, get player input again.

Shut Down - The game is over. Provide player final information, free resources if necessary, and exit.

*/