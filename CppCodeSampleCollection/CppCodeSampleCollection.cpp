// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// Hangman 2.0

char getGuess(vector<char> *lettersUsed);
bool evaluateGuess(string secret, string* guessedWord, char guessedChar, vector<char> *lettersUsed);
int score;
const int AWARD = 10;
const int DEDUCT = 5;

int main() { 
    bool playAgain = true;
    char play;
    vector<string> words = { "hamilton", "mathematics", "medieval", "game", "mug", "juice" };

    const int MAX_GUESSES = 8;

    int roundsPlayed = 1;
    int highScore = 0;

    while (playAgain) {
        score = 0;
        int guesses = 0;
        srand(static_cast<unsigned int>(time(0)));
        string secretWord = words[(rand() % words.size())];
        const int MAX_SCORE = secretWord.size() * 10;
        vector<char> *lettersUsed = new vector<char>(MAX_GUESSES + secretWord.size());
        string* guessedWord = new string(secretWord.size(), '-');
        bool correctGuess;
        vector<char>::const_iterator iter;


        cout << "Welcome to Hangman.\n\n";
        cout << "Correct guesses award " << AWARD << " points per letter.\n";
        cout << "Incorrect guesses deduct " << DEDUCT << " points.\n";
        cout << "Total possible points this round: " << MAX_SCORE << "\n\n";

        while (guesses < MAX_GUESSES && *guessedWord != secretWord) {
            cout << "You have " << (MAX_GUESSES - guesses) << " guesses left." << endl;

            cout << "You have already guessed: ";
            for (iter = (*lettersUsed).begin(); iter != (*lettersUsed).end(); iter++) {
                cout << *iter << " ";
            }

            cout << endl << endl;

            for (unsigned int i = 0; i < (*guessedWord).size(); i++) {
                cout << (*guessedWord)[i];
            }

            cout << endl << endl;

            char guess = getGuess(lettersUsed);

            correctGuess = evaluateGuess(secretWord, guessedWord, guess, lettersUsed);

            if (correctGuess) {
                cout << "Your guess is right!\n";
            }
            else {
                cout << "Your guess is wrong.\n";
                score -= DEDUCT;
                guesses++;
            }

            cout << endl;
        }

        cout << "The secret word was: " << secretWord << endl;

        cout << endl;

        if (secretWord == *guessedWord) {
            cout << "Congratulations!\n";
        }
        else {
            cout << "Better luck next time.\n";
        }

        cout << "\nYour final score is: " << score << "/" << MAX_SCORE << endl;

        cout << endl;

        // Play Again?
        play = ' ';

        while (play != 'y' && play != 'n') {
            cout << "Play Again? (y/n): ";
            cin >> play;
        }

        if (score > highScore) {
            highScore = score;
        }

        if (play == 'n') {
            playAgain = false;
            cout << "\nYour highest score is: " << highScore << endl;
            cout << "\nYou played " << roundsPlayed << " rounds." << endl;
        }
        else {
            roundsPlayed++;
        }

        cout << endl;
    }

    cout << endl;

    return 0;
}

char getGuess(vector<char> *lettersUsed) {
    char guess = ' ';
    while (guess < 'a' || guess > 'z') {
        cout << "Guess a letter: ";
        cin >> guess;
        cout << endl;

        if (find((*lettersUsed).begin(), (*lettersUsed).end(), guess) != (*lettersUsed).end()) {
            guess = ' ';
        }
    }
    return guess;
}

bool evaluateGuess(string secret, string* guessedWord, char guessedChar, vector<char> *lettersUsed) {
    bool result = false;
    for (unsigned int i = 0; i < secret.size(); i++) {
        if (guessedChar == secret[i]) {
            (*guessedWord)[i] = guessedChar;
            score += AWARD;
            result = true;
        }

        if (find((*lettersUsed).begin(), (*lettersUsed).end(), guessedChar) == (*lettersUsed).end()) {
            (*lettersUsed).push_back(guessedChar);
        }
    }
    return result;
}
