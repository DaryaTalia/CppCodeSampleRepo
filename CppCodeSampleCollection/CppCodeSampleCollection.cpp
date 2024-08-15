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

// World Jumble 2.0
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

    // Scoring System
    int points = 0;
    const int hintDeduction = 3;
    int game_order[NUM_WORDS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Scramble Word Order
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < NUM_WORDS; ++i) {
        int index1 = (rand() % NUM_WORDS);
        int index2 = (rand() % NUM_WORDS);
        char temp = game_order[index1];
        game_order[index1] = game_order[index2];
        game_order[index2] = temp;
    }

    // Enter the Game Loop
    char again = 'y';

    // Welcome the Player
    cout << "\t\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "You'll gain 1 point for each character in the word.\n";
    cout << "You'll lose 1 point for each incorrect guess.\n";
    cout << "Enter '-hint' or '-h' for a hint.\n";
    cout << "If you ask for a '-hint', you'll lose " << hintDeduction << " points.\n";
    cout << "Enter '-quit' r '-q' to quit the game.\n\n";

    while (again == 'y') {
        for (int i = 0; i < NUM_WORDS; i++) {
            cout << "\nRound " << i + 1 << "\n";

            string theWord = WORDS[game_order[i]][WORD];
            string theHint = WORDS[game_order[i]][HINT];

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

            cout << "The jumble is: " << jumble;

            string guess;
            cout << "\n\nYour guess: ";
            cin >> guess;
            while ((guess != theWord) && (guess != "-quit") && (guess != "-q")) {
                if (guess == "-hint" || guess == "-h") {
                    cout << theHint; 
                    points -= hintDeduction;
                }
                else {
                    cout << "\nSorry, that's not it.";
                    points--;
                }

                cout << "\n\nYour guess: ";

                cin >> guess;
            }

            // Give Congrats
            if (guess == theWord) {
                cout << "\nThat's it! You guessed it!\n";
            }

            // Give Points
            points += theWord.size();
        }

        //Final Points
        cout << "\n\nYou made " << points << " points!";

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
