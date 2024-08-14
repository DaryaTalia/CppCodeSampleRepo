// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Die Roller
int main()
{    
    //static_cast<unsigned int> coverts/casts system date and time to an unsigned int
    //execute this code once before calls to rand()
    srand(static_cast<unsigned int>(time(0))); //seed random number generator

    //rand() generates a number between 0 and 32767 (RAND_MAX)
    int randomNumber = rand();
    cout << RAND_MAX<< endl;

    //modulus may not always produce uniform results
    int die = (randomNumber % 6) + 1;
    cout << "You rolled a "<< die << endl;

    return 0;
}