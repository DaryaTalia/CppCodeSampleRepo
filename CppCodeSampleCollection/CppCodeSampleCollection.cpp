// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

// Hangman

int main() { 
    bool playAgain = true;
    char play;

    // Initialize a constant int called MAX_GUESSES and declare to 8
    const int MAX_GUESSES = 8;

    while (playAgain) {
        // Game// Initialize an int called guesses and declare to 0
        int guesses = 0;
        // Generate a list of words, <string>
        vector<string> words = { "marble", "cherry", "banana", "random", "everything", "karma" };
        // Generate a new seed of random numbers using current time
        srand(static_cast<unsigned int>(time(0)));
        // Randomly select a word from the vector and save as the secret word
        string secretWord = words[(rand() % words.size())];
        // Initialize an empty vector list for letters used, <char>
        vector<char> lettersUsed(MAX_GUESSES + secretWord.size());
        // Initialize a vector list of characters equal to the size of the random word where each <character> is '-' for the guessed word
        string guessedWord = string(secretWord.size(), '-');
        // Declare correctGuess as a bool
        bool correctGuess;

        vector<char>::const_iterator iter;
        // Welcome the player
        cout << "Welcome to Hangman!" << endl << endl;

        while (guesses < MAX_GUESSES && guessedWord != secretWord) {
            // Tell the player how many incorrect guesses they have left (MAX_GUESSS - guesses)
            cout << "You have " << (MAX_GUESSES - guesses) << " guesses left." << endl;

            cout << "You have already guessed: ";
            //      Print letters already used (none at start)
            for (iter = lettersUsed.begin(); iter != lettersUsed.end(); iter++) {
                cout << *iter << " ";
            }

            cout << endl << endl;

            //      Print the guessed word ('-'s at start)
            for (int i = 0; i < guessedWord.size(); i++) {
                cout << guessedWord[i];
            }

            cout << endl << endl;

            //      Ask the player to enter one letter as a guess that is not already in the list of guessed characters and is between a to z
            char guess = ' ';
            while (guess < 'a' || guess > 'z') {
                cout << "Guess a letter: ";
                cin >> guess;
                cout << endl;

                if (find(lettersUsed.begin(), lettersUsed.end(), guess) != lettersUsed.end()) {
                    guess = ' ';
                }
            }
            //      Initialize correctGuess to false
            correctGuess = false;

            //      Search the entire secret word for the guessed character:
            //          If the character is found:
            //              Replace the matching index of the guessed word with the character
            //              If correctGuess is false:
            //                  Add the character to the end of the list of guessed characters
            //                  Mark correctGuess true

            for (int i = 0; i < secretWord.size(); i++) {
                if (guess == secretWord[i]) {
                    guessedWord[i] = guess;
                    correctGuess = true;
                }

                if (find(lettersUsed.begin(), lettersUsed.end(), guess) == lettersUsed.end()) {
                    lettersUsed.push_back(guess);
                }
            }

            //      If correctGuess is equal to false, increment guesses by 1
            //          Tell the player they guessed incorrectly
            //      Otherwise
            //          Tell the player they guessed correctly

            if (correctGuess) {
                cout << "Your guess is right!\n";
            }
            else {
                cout << "Your guess is wrong.\n";
                guesses++;
            }

            cout << endl;
        }

        // While guesses is less than MAX_GUESSES or the guessed word is not equal to the secret word:
        // 
        // While loop ends when the secret word is fully found or when guesses is equal to or greater than max guesses
        // 
        // Tell the player what the secret word was
        // 
        // Congratulate the player if they won or 
        // tell the player if they lost

        cout << "The secret word was: " << secretWord << endl;

        cout << endl;

        if (secretWord == guessedWord) {
            cout << "Congratulations!\n";
        }
        else {
            cout << "Better luck next time.\n";
        }

        cout << endl;

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

    return 0;

    cout << endl;
}
