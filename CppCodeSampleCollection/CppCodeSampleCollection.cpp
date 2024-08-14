// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <string>

using std::cout;
using std::cin;

// Guess My Number: Computer Guesses
int main()
{    
    char playAgain;

    do {

//#define GAME_LOOP
#ifndef GAME_LOOP
        //Game Loop
        srand(static_cast<unsigned int>(time(0))); //seed random number generator

        int secretNumber;
        int tries = 0;
        int guess;
        int const UPPER_LIMIT = 100;
        int const LOWER_LIMIT = 1;

        //Populate memory with valid choices
        std::list<int> memory;

        for (int i = 1; i < UPPER_LIMIT + 1; i++) {
            memory.push_back(i);
        }

        cout << "\tWelcome to Guess My Number!\n\n";

        //Get player's number
        do {
            cout << "Enter a number for the computer to guess between " << LOWER_LIMIT << " and " << UPPER_LIMIT << ": ";
            cin >> secretNumber;
        }

        while (secretNumber < LOWER_LIMIT || secretNumber > UPPER_LIMIT);

        //Computer will guess player's number
        do {
            cout << "\nYou ask the computer to guess your number: ";

            //Find a random index up to the size of memory
            int index = rand() % memory.size();
            //Iterate to the specified memory location
            std::list<int>::iterator itr = memory.begin();
            for (int i = 0; i < index; i++) {
                ++itr;
            }
            //The guess is the value at the iterator
            guess = *itr;

            ++tries;

            //evaluate guess
            cout << "\nThe computer guesses " << guess << ". ";

            if (guess > secretNumber) {
                cout << "The guess is too high!\n\n";

                //Remove the guess and higher values from the memory list so they cannot be chosen again

                for (int i = memory.size() - 1; i >= index; i--) {
                    //cout << "***** Removed: " << memory.back() << "\n";
                    memory.remove(memory.back());
                }
            }
            else if (guess < secretNumber) {
                cout << "The guess is too low!\n\n";

                //Remove the guess and lower values from the memory list so they cannot be chosen again

                for (int i = 0; i <= index; i++) {
                    //cout << "***** Removed: " << memory.front() << "\n";
                    memory.remove(memory.front());
                }
            }
            else {
                cout << "\n\nThat's it! The computer got it in " << tries << " guesses!\n";
            }

        }

        while (guess != secretNumber);
#endif GAME_LOOP


        //Play Again?
        int invalidEntries = -1;
        playAgain = ' ';
        std::string input;

        do {
            invalidEntries++;
            cout << "\n\nWant to play again? (y/n): ";
            std::getline(std::cin, input);

            if (input.length() == 1 && (input[0] == 'y' || input[0] == 'n')) {
                playAgain = input[0];
            }
            else {
                cout << "\nInvalid input. Please enter 'y' or 'n'.";
                playAgain = ' ';  // Reset to ensure loop continues
            }

            if (invalidEntries >= 6) {
                cout << "\nToo many invalid entries.";
                playAgain = 'n';
                break;
            }
        }

        while (playAgain != 'y' && playAgain != 'n');

        cout << "\n\n\n";

    }

    while (playAgain == 'y');

    cout << "\tGood-bye!\n\n\n";

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