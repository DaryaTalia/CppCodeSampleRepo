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

// High Scores 2.1

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

    cout << "Creating a 10 element vector to hold scores.\n";
    vector<int> _scores(10, 0);
    cout << "Vector size is: " << _scores.size() << endl;
    cout << "Vector capacity is: " << _scores.capacity() << endl; //10
    cout << "Adding a score.\n";
    _scores.push_back(0);
    cout << "Vector size is: " << _scores.size() << endl;
    cout << "Vector capacity is: " << _scores.capacity() << endl; //15
    cout << "Adding a score.\n";
    _scores.push_back(0);
    _scores.push_back(0);
    _scores.push_back(0);
    _scores.push_back(0);
    _scores.push_back(0);
    cout << "Vector size is: " << _scores.size() << endl;
    cout << "Vector capacity is: " << _scores.capacity() << endl; //22

    cout << endl;

    cout << "Creating a list of scores.\n";
    vector<int> moreScores(10, 0);
    cout << "Vector size is: " << moreScores.size() << endl;
    cout << "Vector capacity is: " << moreScores.capacity() << endl; //10

    cout << "Reserving more memory.\n";
    moreScores.reserve(20);
    cout << "Vector size is: " << moreScores.size() << endl;
    cout << "Vector capacity is: " << moreScores.capacity() << endl; //20

    cout << endl;

    return 0;
}
