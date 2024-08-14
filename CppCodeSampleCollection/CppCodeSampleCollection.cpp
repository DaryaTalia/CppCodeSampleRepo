// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <iostream>

using namespace std;


// Score Rater
int main()
{
    if (true) {
        cout << "This is always displayed.\n\n";
    }

    if (false) {
        cout << "This is never displayed.\n\n";
    }

    int score = 1000;

    if (score) {
        cout << "At least you didn't score 0.\n\n";
    }

    if (score >= 250) {
        cout << "You scored 250 or more. Decent.\n\n";
    }

    if (score >= 500) {
        cout << "You scored more 500 or more. Nice.\n\n";

        if (score >= 1000) {
            cout << "You scored more 1000 or more. Impressive!\n\n";
        }
    }

    return 0;
}