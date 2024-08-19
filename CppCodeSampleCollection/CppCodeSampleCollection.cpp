// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Yes or No

char askYesNo();
char askYesNo(string question);

int main() { 
    char answer1 = askYesNo();
    cout << "Thanks for answering: " << answer1 << "\n\n";

    char answer2 = askYesNo("Do you wish to save your game?");
    cout << "Thanks for answering: " << answer2 << "\n\n";

    cout << endl;

    return 0;
}

char askYesNo() {
    char response;
    do {
        cout << "Please enter 'y' or 'n': ";
        cin >> response;
    } 
    while (response != 'y' && response != 'n');

    return response;
}

char askYesNo(string question) {
    char response;
    do {
        cout << question << " (y/n): ";
        cin >> response;
    } while (response != 'y' && response != 'n');

    return response;
}