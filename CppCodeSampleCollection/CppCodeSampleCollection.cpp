// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <iostream>

using namespace std;


// Score Rater 2.0
int main()
{    
    int score ;
    cout << "Enter your score: ";
    cin >> score;
    
    if (score >= 1000) {
        cout << "You scored more 1000 or more. Impressive!\n";        
    }
    else {
        cout << "You scored less than 1000.\n";
    }

    return 0;
}