// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <iostream>

using namespace std;

// Play Again
int main()
{    
    char again = 'y';
    while (again == 'y') {        
        cout << "\n**Played an exciting game**";

        // Loop for valid input
        do {
            cout << "\nDo you want to play again? (y/n): ";
            cin >> again; 
        } 
        while (again != 'y' && again != 'n');
    }

    cout << "\nOkay, bye!";

    return 0;
}