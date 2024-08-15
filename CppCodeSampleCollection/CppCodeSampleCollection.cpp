// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::copy;

// Tic-Tac-Toe Board 2.0
const int ROWS = 3;
const int COLUMNS = 3;
char gameboard[ROWS][COLUMNS];

const char PLAYER_PEICE = 'X';
const char COMPUTER_PEICE = 'O';

enum state { init, computer_turn, player_turn, computer_won, player_won, stalemate, game_over };
state currentState;

void PrintBoard() {
    cout << endl;

    cout << "--------------\n";
    for (int i = 0; i < ROWS; ++i) {
        cout << "| ";
        for (int j = 0; j < COLUMNS; ++j) {
            cout << gameboard[i][j];
            cout << " | ";
        }
        cout << endl;
    }
    cout << "--------------\n";
}//end print board

void InitBoard() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            gameboard[i][j] = ' ';
        }
    }

    PrintBoard();
}//end init board

bool IsValidIndex(int validRow, int validColumn) {
    if (gameboard[validRow][validColumn] == ' ') {
        return true;
    }
    else {
        return false;
    }
}//IsValidIndex

bool AreRemainingSpaces() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (gameboard[i][j] == ' ') {
                return true;
            }
        }
    }
    return false;
}//end AreRemainingSpaces

bool PlacePiece(char piece, int getRow, int getCol) {
    gameboard[getRow][getCol] = piece;
    return true;
}

state FindWinningCombo(char piece) {
    //cout << "**DEBUG**: FindWinningCombo('" << piece << "')\n";
    bool winFound = false;

    // Row 1: gameboard[0][0], gameboard[0][1], gameboard[0][2]
    if (gameboard[0][0] == piece && gameboard[0][1] == piece && gameboard[0][2] == piece)
    {
        //cout << "**DEBUG**: Row 1: gameboard[0][0], gameboard[0][1], gameboard[0][2]\n";
        winFound = true;
    }
    else

    // Row 2: gameboard[1][0], gameboard[1][1], gameboard[1][2]
    if (gameboard[1][0] == piece && gameboard[1][1] == piece && gameboard[1][2] == piece)
    {
        //cout << "**DEBUG**: Row 2: gameboard[1][0], gameboard[1][1], gameboard[1][2]\n";
        winFound = true;
    }
    else

    // Row 3: gameboard[2][0], gameboard[2][1], gameboard[2][2]
    if (gameboard[2][0] == piece && gameboard[2][1] == piece && gameboard[2][2] == piece)
    {
        //cout << "**DEBUG**: Row 3: gameboard[2][0], gameboard[2][1], gameboard[2][2]\n";
        winFound = true;
    }
    else

    // Column 1: gameboard[0][0], gameboard[1][0], gameboard[2][0]
    if (gameboard[0][0] == piece && gameboard[1][0] == piece && gameboard[2][0] == piece)
    {
        //cout << "**DEBUG**: Column 1: gameboard[0][0], gameboard[1][0], gameboard[2][0]\n";
        winFound = true;
    }
    else

    // Column 2: gameboard[0][1], gameboard[1][1], gameboard[1][2]
    if (gameboard[0][1] == piece && gameboard[1][1] == piece && gameboard[1][2] == piece)
    {
        //cout << "**DEBUG**: Column 2: gameboard[0][1], gameboard[1][1], gameboard[1][2]\n";
        winFound = true;
    }
    else

    // Column 3: gameboard[0][2], gameboard[1][2], gameboard[2][2]
    if (gameboard[0][2] == piece && gameboard[1][2] == piece && gameboard[2][2] == piece)
    {
        //cout << "**DEBUG**: Column 3: gameboard[0][2], gameboard[1][2], gameboard[2][2]\n";
        winFound = true;
    }
    else

    // Diagonal 1: gameboard[0][0], gameboard[1][1], gameboard[2][2]
    if (gameboard[0][0] == piece && gameboard[1][1] == piece && gameboard[2][2] == piece)
    {
        //cout << "**DEBUG**: Diagonal 1: gameboard[0][0], gameboard[1][1], gameboard[2][2]\n";
        winFound = true;
    }
    else

    // Diagonal 2: gameboard[2][0], gameboard[1][1], gameboard[0][2]
    if (gameboard[2][0] == piece && gameboard[1][1] == piece && gameboard[0][2] == piece)
    {
        //cout << "**DEBUG**: Diagonal 2: gameboard[2][0], gameboard[1][1], gameboard[0][2]\n";
        winFound = true;
    }

    cout << endl;

    // Determine next state
    if (winFound) {
        if (piece == COMPUTER_PEICE) {
            return computer_won;
        }
        else //if (piece == PLAYER_PEICE) 
        {
            return player_won;
        }
    }
    else {
        if (AreRemainingSpaces()) {
            if (piece == COMPUTER_PEICE) {
                return player_turn;
            }
            else //if (piece == PLAYER_PEICE) 
            {
                return computer_turn;
            }
        }
        else {
            return stalemate;
        }
    }
}//end find winning combo

state PlayerTurn() {
    bool validEntry = false;
    int getRow = -1;
    int getCol = -1;

    // Safety check for valid entry
    while (!validEntry) {
        // Get Valid Row Number: 1, 2, 3
        while (getRow != 1 && getRow != 2 && getRow != 3) {
            cout << "\nEnter the row (1, 2, or 3):\t";
            cin >> getRow;
        }

        // Get Valid Column Number: 1, 2, 3
        while (getCol != 1 && getCol != 2 && getCol != 3) {
            cout << "\nEnter the column (1, 2, or 3):\t";
            cin >> getCol;
        }

        // Is (Row, Column) a valid, unoccupied space on the gameboard?
        validEntry = IsValidIndex(getRow - 1, getCol - 1);

        if (!validEntry) {
            cout << "Hey! (" << getRow << ", " << getCol << ") is not a valid position. Please choose new row and column numbers.\n";
        }
    }
    
    // Place player's piece in gameboard space
    PlacePiece(PLAYER_PEICE, getRow - 1, getCol - 1);
    
    // Evaluate the gameboard to find a winning combo based on the player's piece and return the next state based on the results
    return FindWinningCombo(PLAYER_PEICE);
}//end player turn

state ComputerTurn() {
    bool validEntry = false;
    int getRow = -1;
    int getCol = -1;

    while (!validEntry) {
        // Get Valid Row Number: # % 3 -> 0, 1, 2    
        getRow = rand() % 3;

        // Get Valid Column Number: # % 3 -> 0, 1, 2
        getCol = rand() % 3;

        // Is (Row, Column) a valid, unoccupied space on the gameboard?
        validEntry = IsValidIndex(getRow, getCol);

        if (!validEntry) {
            //cout << "(" << getRow << ", " << getCol << ") is not a valid position. The computer will choose new row and column numbers.\n";
        }
    }

    // Place computer's piece in gameboard space
    PlacePiece(COMPUTER_PEICE, getRow, getCol);

    // Evaluate the gameboard to find a winning combo based on the computer's piece and return the next state based on the results
    return FindWinningCombo(COMPUTER_PEICE);
}//end computer turn

state EvaluateGameState(state result) {
    switch (result) {
    case init: {
        srand(static_cast<unsigned int>(time(0))); //seed random number generator
        InitBoard();
        result = player_turn;
        break;
    }
    case player_turn: {
        cout << "\nPlayers turn:\n";
        result = PlayerTurn();
        PrintBoard();
        break;
    }
    case computer_turn: {
        cout << "\nComputers turn:\n";
        result = ComputerTurn();
        PrintBoard();
        break;
    }
    case player_won: {
        result = game_over;
        cout << "\nPlayer wins! Congratulations!\n";
        break;
    }
    case computer_won: {
        result = game_over;
        cout << "\nComputer wins. Better luck next time.\n";
        break;
    }
    case stalemate: {
        result = game_over;
        cout << "\nStalemate! No winner.\n";
        break;
    }
    default: {
        break;
    }
    }//end switch 

    return result;
}

  ///////////////////////////////////////////////////////////////
 ///////////////////////     MAIN()     ////////////////////////
///////////////////////////////////////////////////////////////

int main() { 
    char again;

    do 
    {
        again = ' ';
        currentState = init;

        //Introduction
        cout << "\t\t Welcome to Tic-Tac-Toe!\n\n";

        cout << "The Player's piece is " << PLAYER_PEICE << ". \nThe Computer's piece is " << COMPUTER_PEICE << ".\n";
        cout << "\nPlayer, you will go first!\n";
         
        // Game Loop
        while (currentState != game_over) {
            currentState = EvaluateGameState(currentState);
        }

        cout << "\n\nGame Over. Thanks for playing!";

        //Replay Loop
        while (again != 'y' && again != 'n') {
            cout << "\n\nDo you want to play again? (y/n): ";
            cin >> again;
        }

        cout << endl;
    }
    while (again == 'y');

    cout << "\n\nGood-bye!";

    cout << endl;

    return 0;
}
