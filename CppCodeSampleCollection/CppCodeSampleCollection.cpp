// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Point Point String

int main() {
    string myName = "Darya Talia";
    string* pMyName1 = &myName;
    string* pMyName2 = pMyName1;

    cout << "The length of my name is: " << pMyName2->size() - 1;

    cout << endl;

    return 0;
}
