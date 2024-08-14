// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Tic-Tac-Toe Board 1.0
int main() {    
    const int ROWS = 3;
    const int COLUMNS = 3;
    char board[ROWS][COLUMNS] = 
    {
        {'O', 'X', 'O'},
        {' ', 'X', 'X'},
        {'X', 'O', 'O'}
    };

    cout << "Here's the tic-tac-toe board:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            cout << board[i][j];
        }

        cout << endl;
    }

    cout << "\n'X' moves to the empty location.\n\n";
    board[1][0] = 'X';

    cout << "Now the tic-tac-toe boardis:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            cout << board[i][j];
        }

        cout << endl;
    }

    cout << "\n'X' wins!";

    cout << endl;

    return 0;
}
