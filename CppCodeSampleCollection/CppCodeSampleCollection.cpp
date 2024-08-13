// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    int gameScore1, gameScore2, gameScore3;

    cout << "Provide the first score: "; 
    cin >> gameScore1;

    cout << "\nProvide the second score: ";
    cin >> gameScore2;

    cout << "\nProvide the third score: ";
    cin >> gameScore3;

    int average = (gameScore1 + gameScore2 + gameScore3) / 3;

    cout << "\nAverage score: " << average;

    return 0;
}