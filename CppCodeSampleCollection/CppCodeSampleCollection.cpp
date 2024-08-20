// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl; 
using std::string;
using std::vector;

// Tic Tac Toe and Psuedocode

int main() { 
    bool playAgain = true;
    char play;

    while (playAgain) {
        // App

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

// Print a blank tic tac toe board
// 
// Repeat until the player or the computer has one, or until there are no more available spaces:
// 
//      If it's the player's turn:
//          Get the player's desired position
//          If valid, place the player's piece on the tic tac toe board
//          Check to see if the values on the board have formed a winning combiination from the player
//          If so, the player won
//          Otherwise, check to see if there are available spaces left
//              If so, the computer's turn is next (switch turns)
//              Otherwise, the game ends in a stalemate
// 
//      If it's the computer's turn:
//          Get the computer's position from random row and column values
//          If valid, place the computer's piece on the tic tac toe board
//          Check to see if the values on the board have formed a winning combiination from the computer
//          If so, the computer won
//          Otherwise, check to see if there are available spaces left
//              If so, the player's turn is next (switch turns)
//              Otherwise, the game ends in a stalemate
// 
//      Print the current tic tac toe board
// 
// When the game ends by the player, computer, or stalemate, announce the final outcome
// 
