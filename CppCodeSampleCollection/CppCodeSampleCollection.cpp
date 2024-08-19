// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Give Me a Number 3.0

int getNumber();
int getNumber(string prompt);

int main() { 
    bool playAgain = true;
    char play;

    while (playAgain) {
        // App
        int number = getNumber();
        cout << number << endl << endl;
        number = getNumber("Give me a number: ");
        cout << number << endl << endl;


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

int getNumber(string prompt) {
    int num = 0;
    cout << prompt;
    cin >> num;
    return num;
}

int getNumber() {
    int num = 0;
    cout << "What number am I thinking? ";
    cin >> num;
    return num;
}



