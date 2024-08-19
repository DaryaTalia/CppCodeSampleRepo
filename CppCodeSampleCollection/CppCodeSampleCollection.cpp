// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Give Me a Number

int triple(int number);
string triple(string text);

int main() { 
    cout << "Tripling 5: " << triple(5) << "\n\n";
    cout << "Tripling 'gamer': " << triple("gamer") << "\n\n";

    cout << endl;

    return 0;
}

int triple(int number) {
    return (number * 3);
}

string triple(string text) {
    return (text + text + text);
}