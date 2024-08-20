// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Array Passer

void increase(int* const array, const int NUM_ELEMENTS);
void display(const int* const array, const int NUM_ELEMENTS);

int main() {
    bool playAgain = true;
    char play;

    int myScore = 150;
    int yourScore = 1000;

    while (playAgain) {
        // App
        cout << "Creating an array of high scores.\n\n";
        const int NUM_SCORES = 3;
        // An array name is a constant pointer (* const) to the first element of the array.
        int highScores[NUM_SCORES] = {5000, 3500, 2700};

        cout << "Displaying scores using array name as a constant pointer.\n";
        // array name can be dereferenced to access the first element
        cout << *highScores << endl;
        // *(highScores + 1) is equivalent to highScores[1]
        cout << *(highScores + 1) << endl;
        cout << *(highScores + 2) << "\n\n";

        cout << "Increasing scores by passing array as a constant pointer.\n\n";
        // will only point to highScores' address but can edit highScores' value
        increase(highScores, NUM_SCORES);

        cout << "Displaying scores by passing array as a constant pointer to a constant.\n";
        // read access only to highScores' value
        display(highScores, NUM_SCORES);


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

// When you pass an array to a function, it’s usually a good idea to also pass the number of elements
// in the array so the function can use this to avoid attempting to access an element that doesn’t
// exist.

void increase(int* const array, const int NUM_ELEMENTS) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        // *(array + i) += 500; // is also valid
        array[i] += 500;
    }
}

void display(const int* const array, const int NUM_ELEMENTS) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        cout << array[i] << endl;
    }
}
