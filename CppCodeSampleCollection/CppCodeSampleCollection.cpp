// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// Hangman and Psuedocode

int main() { 
    // Psuedocode
    
    // Generate a vector list of words, <string>
    // Generate a new seed of random numbers using current time
    // Randomly select a word from the vector and save as the secret word
    // 
    // Initialize an empty vector list for letters used, <char>
    // 
    // Initialize a vector list of characters equal to the size of the random word where each <character> is '-' for the guessed word
    // 
    // Initialize a constant int called MAX_GUESSES and declare to 8
    // Initialize an int called guesses and declare to 0
    // 
    // Declare correctGuess as a bool
    // 
    // Welcome the player
    // Tell the player how many incorrect guesses they have left (MAX_GUESSS - guesses)
    // 
    // 
    // While guesses is less than MAX_GUESSES or the guessed word is not equal to the secret word:
    // 
    //      Print letters already used (none at start)
    //      Print the guessed word ('-'s at start)
    // 
    //      Ask the player to enter one letter as a guess that is not already in the list of guessed characters and is between a to z
    //      Initialize correctGuess to false
    // 
    //      Search the entire secret word for the guessed character:
    //          If the character is found:
    //              Replace the matching index of the guessed word with the character
    //              If correctGuess is false:
    //                  Add the character to the end of the list of guessed characters
    //                  Mark correctGuess true
    // 
    //      If correctGuess is equal to false, increment guesses by 1
    //          Tell the player they guessed incorrectly
    //      Otherwise
    //          Tell the player they guessed correctly
    // 
    //      Tell the player how many incorrect guesses they have left (MAX_GUESSS - guesses)
    // 
    // 
    // While loop ends when the secret word is fully found or when guesses is equal to or greater than max guesses
    // 
    // Tell the player what the secret word was
    // 
    // Congratulate the player if they won or 
    // tell the player if they lost
    // 
    // 

    return 0;
}
