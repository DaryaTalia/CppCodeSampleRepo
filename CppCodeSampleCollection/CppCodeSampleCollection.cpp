#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::copy;

// Tic-Tac-Toe Board 3.0

///////////////////////////////////////////////////////////////
/////////////////     GLOBAL VARIABLES     ////////////////////
///////////////////////////////////////////////////////////////

struct Vector2
{
    int x;
    int y;

    Vector2(int _x, int _y) {
        x = _x;
        y = _y;
    };
};

const int ROWS = 3;
const int COLUMNS = 3;
char gameboard[ROWS][COLUMNS];
const Vector2 WINNING_ROWS[8][3] =
{
    { {Vector2(0,0)}, {Vector2(0,1)}, {Vector2(0,2)} },
    { {Vector2(1,0)}, {Vector2(1,1)}, {Vector2(1,2)} },
    { {Vector2(2,0)}, {Vector2(2,1)}, {Vector2(2,2)} },
    { {Vector2(0,0)}, {Vector2(1,0)}, {Vector2(2,0)} },
    { {Vector2(0,1)}, {Vector2(1,1)}, {Vector2(1,2)} },
    { {Vector2(0,2)}, {Vector2(1,2)}, {Vector2(2,2)} },
    { {Vector2(0,0)}, {Vector2(1,1)}, {Vector2(2,2)} },
    { {Vector2(2,0)}, {Vector2(1,1)}, {Vector2(0,2)} }
};

const char PLAYER_PEICE = 'X';
const char COMPUTER_PEICE = 'O';

enum class state { init, computer_turn, player_turn, computer_won, player_won, stalemate, game_over };
enum state currentState;

///////////////////////////////////////////////////////////////
///////////////     FUNCTION DEFINITIONS     //////////////////
///////////////////////////////////////////////////////////////

void PrintBoard();
void InitBoard();
bool IsValidIndex(int validRow, int validColumn);
bool AreRemainingSpaces();
bool PlacePiece(char piece, int getRow, int getCol);
state FindWinningCombo(char piece);
state PlayerTurn();
state ComputerTurn();
state EvaluateGameState(state result);

///////////////////////////////////////////////////////////////
////////////////////     FUNCTIONS     ////////////////////////
///////////////////////////////////////////////////////////////

int main() {
    char again;

    do
    {
        again = ' ';
        currentState = state::init; //Unscoped, Enum.3

        //Introduction
        cout << "\t\t Welcome to Tic-Tac-Toe!\n\n";

        cout << "The Player's piece is " << PLAYER_PEICE << ". \nThe Computer's piece is " << COMPUTER_PEICE << ".\n";
        cout << "\nPlayer, you will go first!\n";

        // Game Loop
        while (currentState != state::game_over) {
            currentState = EvaluateGameState(currentState);
        }

        cout << "\n\nGame Over. Thanks for playing!";

        //Replay Loop
        while (again != 'y' && again != 'n') {
            cout << "\n\nDo you want to play again? (y/n): ";
            cin >> again;
        }

        cout << endl;
    } while (again == 'y');

    cout << "\n\nGood-bye!";

    cout << endl;

    return 0;

}

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

    for (int i = 0; i < (ROWS * COLUMNS) - 1; i++) {
        if (gameboard[WINNING_ROWS[i][0].x][WINNING_ROWS[i][0].y] == piece &&
            gameboard[WINNING_ROWS[i][0].x][WINNING_ROWS[i][0].y] == gameboard[WINNING_ROWS[i][1].x][WINNING_ROWS[i][1].y] &&
            gameboard[WINNING_ROWS[i][1].x][WINNING_ROWS[i][1].y] == gameboard[WINNING_ROWS[i][2].x][WINNING_ROWS[i][2].y]) {
            winFound = true;
        }
    }

    cout << endl;

    // Determine next state
    if (winFound) {
        if (piece == COMPUTER_PEICE) {
            return state::computer_won;
        }
        else //if (piece == PLAYER_PEICE) 
        {
            return state::player_won;
        }
    }
    else {
        if (AreRemainingSpaces()) {
            if (piece == COMPUTER_PEICE) {
                return state::player_turn;
            }
            else //if (piece == PLAYER_PEICE) 
            {
                return state::computer_turn;
            }
        }
        else {
            return state::stalemate;
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
    case state::init: {
        srand(static_cast<unsigned int>(time(0))); //seed random number generator
        InitBoard();
        result = state::player_turn;
        break;
    }
    case state::player_turn: {
        cout << "\nPlayers turn:\n";
        result = PlayerTurn();
        PrintBoard();
        break;
    }
    case state::computer_turn: {
        cout << "\nComputers turn:\n";
        result = ComputerTurn();
        PrintBoard();
        break;
    }
    case state::player_won: {
        result = state::game_over;
        cout << "\nPlayer wins! Congratulations!\n";
        break;
    }
    case state::computer_won: {
        result = state::game_over;
        cout << "\nComputer wins. Better luck next time.\n";
        break;
    }
    case state::stalemate: {
        result = state::game_over;
        cout << "\nStalemate! No winner.\n";
        break;
    }
    default: {
        break;
    }
    }//end switch 

    return result;
}
