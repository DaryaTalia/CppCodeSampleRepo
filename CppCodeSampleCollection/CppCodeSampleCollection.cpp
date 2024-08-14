// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <iostream>

using namespace std;

// Menu Chooser
int main()
{    
    cout << "Difficulty Levels\n\n";
    cout << "1 - Easy\n";
    cout << "2 - Normal\n";
    cout << "3 - Hard\n";

    int choice ;
    cout << "Choice: ";
    cin >> choice;
    
    switch (choice) {
    case 1: {
        cout << "You picked Easy.\n";
        break;
        }
    case 2: {
        cout << "You picked Normal.\n";
        break;
    }
    case 3: {
        cout << "You picked Hard.\n";
        break;
    }
    default: {
        cout << "You made an illegal choice.\n";
        break;
    }
    }

    return 0;
}