//

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Pointing

int main() {
    int* pAPointer;

    // "Point to nothing", NULL pointer
    // DO NOT dereference a null pointer, causes undefined behavior
    // memory does not exist
    // same error as NullReferenceException in C# or NullPointerException in Java
    int* pScore = 0;

    int score = 1000;
    // Pointers store addresses of objects
    pScore = &score; // point to the address of score

    cout << "Assigning &score to pScore\n";
    cout << "&score is: " << &score << "\n"; //address of score variable
    cout << "pScore is: " << pScore << "\n"; //address stored in pScore
    cout << "score is: " << score << "\n";
    // * is dereference operator here
    // "the object to which pScore points to"
    cout << "*pScore is: " << *pScore << "\n";

    cout << endl;

    cout << "Adding 500 to score\n";
    score += 500;
    cout << "score is: " << score << "\n";
    cout << "*pScore is: " << *pScore << "\n";

    cout << endl;

    cout << "Adding 500 to *pScore\n";
    *pScore += 500;
    cout << "score is: " << score << "\n";
    cout << "*pScore is: " << *pScore << "\n";

    cout << endl;

    // Unlike references, pointers can point to different objects at different times
    // during the life of a program.
    cout << "Assigning &newScore to pScore\n";
    int newScore = 5000;
    pScore = &newScore;
    cout << "&newScore is: " << &newScore << "\n";
    cout << "pScore is: " << pScore << "\n";
    cout << "newScore is: " << newScore << "\n";
    cout << "*pScore is: " << *pScore << "\n";

    cout << endl;

    cout << "Assigning &str to pStr\n";
    string str = "score";
    string* pStr = &str;
    cout << "str is: " << str << "\n";
    cout << "*pStr is: " << *pStr << "\n";
    // Whenever you dereference a pointer to access a data member or member function, surround the
    // dereferenced pointer with a pair of parentheses.This ensures that the dot operator will be applied
    // to the object to which the pointer points.
    cout << "(*pStr).size() is: " << (*pStr).size() << "\n";
    cout << "pStr->size() is: " << pStr->size() << "\n";

    // a constant pointer, a pointer that is constant, must be initialized
    // is: (int) (*const)
    // can only point to a non-constant value
    int* const newPScore = &score;

    // a pointer to a constant int
    // is: (const int) (*)
    // const before the type of value
    // can point to different objects but cannot alter their values
    // can point to either a non-constant or constant value
    const int* pNumber = &newScore;

    // a constant pointer to a constant
    // is: (const int) (*const)
    // can only point to the initialized object
    // cannot alter the value of the addressed object
    // can point to either a non-constant or constant value
    const int &BONUS = 90;
    const int* const pBONUS = &BONUS;

    cout << endl;

    return 0;
}
