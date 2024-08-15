// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// World Jumble
int main() { 
    // Word List
    enum fields { WORD, HINT, NUM_FIELDS };
    const int NUM_WORDS = 10;
    const string WORDS[NUM_WORDS][NUM_FIELDS] = 
    {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."},

        {"launcher", "Interface that lists and runs games from a shared library."},
        {"family", "People related to you closely."},
        {"pattern", "Recognizable sequence."},
        {"batman", "The Dark Knight"},
        {"independence", "Similar to Liberation"}
    };

    // Enter the Game Loop
    char again = 'y';

    while (again == 'y') {
        // Random Word
        srand(static_cast<unsigned int>(time(0)));
        int choice = (rand() % NUM_WORDS);
        string theWord = WORDS[choice][WORD];
        string theHint = WORDS[choice][HINT];

        // Jumble Word
        string jumble = theWord;
        int length = jumble.size();
        for (int i = 0; i < length; ++i) {
            int index1 = (rand() % length);
            int index2 = (rand() % length);
            char temp = jumble[index1];
            jumble[index1] = jumble[index2];
            jumble[index2] = temp;
        }

        // Welcome the Player
        cout << "\t\tWelcome to Word Jumble!\n\n";
        cout << "Unscramble the letters to make a word.\n";
        cout << "Enter 'hint' for a hint.\n";
        cout << "Enter 'quit' to quit the game.\n\n";
        cout << "The jumble is: " << jumble;

        string guess;
        cout << "\n\nYour guess: ";
        cin >> guess;
            while ((guess != theWord) && (guess != "quit")) {
                if (guess == "hint") {
                    cout << theHint;
                }
                else {
                    cout << "Sorry, that's not it.";
                }

                cout << "\n\nYour guess: ";

                cin >> guess;
            }

        // Give Congrats
        if (guess == theWord) {
            cout << "\nThat's it! You guessed it!\n";
        }

        // Play Again
        again = ' ';

        while (again != 'y' && again != 'n') {
            cout << "\n\nDo you want to play again? (y/n): ";
            cin >> again;
        }

        if (again == 'y') {
            cout << "\n\n";
        }
    }

    // Say Goodbye
    cout << "\nThanks for playing!\n";

    cout << endl;

    return 0;
}
