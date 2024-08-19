// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// High Scores

int main() { 
    vector<int>::const_iterator iter;

    cout << "Creating a list of scores.";
    vector<int> scores;
    scores.push_back(1500);
    scores.push_back(3500);
    scores.push_back(7500);

    cout << "\nHigh Scores:\n";
    for (iter = scores.begin(); iter != scores.end(); iter++) {
        cout << *iter << endl;
    }

    cout << "\nFinding a score.";
    int score;
    cout << "\nEnter a score to find: ";
    cin >> score;

    iter = find(scores.begin(), scores.end(), score);
    if (iter != scores.end()) {
        cout << "Score found.\n";
    }
    else {
        cout << "Score not found.\n";
    }

    cout << "\nRandomizing scores.";
    srand(static_cast<unsigned int>(time(0))); 
    random_shuffle(scores.begin(), scores.end());

    cout << "\nHigh Scores:\n";
    for (iter = scores.begin(); iter != scores.end(); iter++) {
        cout << *iter << endl;
    }

    cout << "\nSorting scores.";
    sort(scores.begin(), scores.end());

    cout << "\nHigh Scores:\n";
    for (iter = scores.begin(); iter != scores.end(); iter++) {
        cout << *iter << endl;
    }

    cout << endl;

    return 0;
}
