// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// Game Stats 2.0
int main()
{
    unsigned int score = 5000;
    cout << "\nscore: " << score << endl;

    score = score + 100;
    cout << "\nscore: " << score << endl;

    score += 100;
    cout << "\nscore: " << score << endl;
    
    int lives = 3;
    ++lives;
    cout << "lives: " << lives << endl;

    lives = 3;
    lives++;
    cout << "lives: " << lives << endl;

    lives = 3;
    int bonus = ++lives * 10;
    cout << "lives, bonus = " << lives << ", " << bonus << endl;

    lives = 3;
    bonus = lives++ * 10;
    cout << "lives, bonus = " << lives << ", " << bonus << endl;

    // integer wrap around
    score = 4294967295;
    cout << "\nscore: " << score << endl;
    ++score;
    cout << "score: " << score << endl;

    return 0;
}
