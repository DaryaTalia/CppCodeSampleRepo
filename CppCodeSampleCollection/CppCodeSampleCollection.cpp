// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Guess My Number: Computer Guesses
int main()
{    
    srand(static_cast<unsigned int>(time(0))); //seed random number generator

    int secretNumber;
    int tries = 0;
    int guess;
    int upperLimit = 100;
    int lowerLimit = 1;

    int memory[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    cout << "\tWelcome to Guess My Number!\n\n";

    //Get player's number
    do {
        cout << "Enter a number for the computer to guess between "<< lowerLimit << " and " << upperLimit << ": ";
        cin >> secretNumber;
    }

    while (secretNumber < lowerLimit || secretNumber > upperLimit);

    do {
        //Computer will guess player's number
        cout << "\nYou ask the computer to guess your number: ";

        guess = rand() % upperLimit + lowerLimit;

        ++tries;

        //Add memory within a range of 10
        if (upperLimit - lowerLimit < 10) {
            bool inMemory = false;

            //Check memory for duplicate
            for (int i = 0; i < 10; i++) {
                if (memory[i] == guess) {
                    inMemory = true;
                    cout << "***** inMemory";
                    cout << "***** guess";
                    break;
                }
            }

            //Find a new number if in memory
            if (inMemory) {
                do {
                    guess = rand() % upperLimit + lowerLimit;
                    ++tries;

                    inMemory = false;

                    //Check memory for duplicate
                    for (int i = 0; i < 10; i++) {
                        if (memory[i] == guess) {
                            inMemory = true;
                            cout << "***** inMemory";
                            cout << "***** guess";
                            break;
                        }
                    }
                } 
                
                while (inMemory);
            }
        }//end memory search

        //Add Clamping
        if (guess > upperLimit) {
            cout << "\n***** guess > upperLimit";
            if (guess - lowerLimit < upperLimit && guess - lowerLimit > lowerLimit) {
                guess -= lowerLimit;
                cout << "\n***** guess - lowerLimit < upperLimit && guess - lowerLimit > lowerLimit";

                //Add memory within a range of 10
                if (upperLimit - lowerLimit < 10) {
                    bool inMemory = false;

                    //Check memory for duplicate
                    for (int i = 0; i < 10; i++) {
                        if (memory[i] == guess) {
                            inMemory = true;
                            cout << "***** inMemory";
                            cout << "***** guess";
                            break;
                        }
                    }

                    //Find a new number if in memory
                    if (inMemory) {
                        do {
                            guess = rand() % upperLimit;
                            ++tries;

                            inMemory = false;

                            //Check memory for duplicate
                            for (int i = 0; i < 10; i++) {
                                if (memory[i] == guess) {
                                    inMemory = true;
                                    cout << "***** inMemory";
                                    cout << "***** guess";
                                    break;
                                }
                            }
                        }

                        while (inMemory);
                    }
                }//end memory search
            }
            else {
                //Add memory within a range of 10
                if (upperLimit - lowerLimit < 10) {
                    bool inMemory = false;

                    //Check memory for duplicate
                    for (int i = 0; i < 10; i++) {
                        if (memory[i] == guess) {
                            inMemory = true;
                            cout << "***** inMemory";
                            cout << "***** guess";
                            break;
                        }
                    }

                    //Find a new number if in memory
                    if (inMemory) {
                        do {
                            guess = rand() % upperLimit + lowerLimit;
                            ++tries;

                            inMemory = false;

                            //Check memory for duplicate
                            for (int i = 0; i < 10; i++) {
                                if (memory[i] == guess) {
                                    inMemory = true;
                                    cout << "***** inMemory";
                                    cout << "***** guess " << guess;
                                    break;
                                }
                            }
                        }

                        while (!inMemory);
                    }
                    else {
                        guess = upperLimit;
                        cout << "\n***** guess = upperLimit";
                    }
                }//end memory search
            }
        }

        cout << "\n***** lowerLimit: " << lowerLimit << ", upperLimit: " << upperLimit << "\n";

        //Add memory within a range of 10
        if (upperLimit - lowerLimit < 10) {
            bool inMemory = false;

            //Check memory for duplicate
            for (int i = 0; i < 10; i++) {
                if (memory[i] == guess) {
                    inMemory = true;
                    cout << "***** inMemory";
                    cout << "***** guess " << guess;
                    break;
                }
            }

            if (!inMemory) {
                //Add to memory
                for (int i = 0; i < 10; i++) {

                    if (memory[i] == 0) {
                        memory[i] = guess;
                        cout << "***** memory[" << i << "] = " << guess;
                        break;
                    }
                }
            }
        }//end memory search

        //evaluate guess
        cout << "\nThe computer guesses " << guess << ". ";

        if (guess > secretNumber) {
            cout << "The guess is too high!\n\n";
        }
        else if (guess < secretNumber) {
            cout << "The guess is too low!\n\n";
        }
        else {
            cout << "\nThat's it! The computer got it in " << tries << " guesses!\n";
        }

        //re-adjust searching bounds
        if (guess < upperLimit && guess > secretNumber) {
            upperLimit = guess;
        } 
        else if (guess > lowerLimit && guess < secretNumber) {
            lowerLimit = guess;
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