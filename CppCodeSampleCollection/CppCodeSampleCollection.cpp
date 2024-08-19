// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Scoping

void func();

int main() { 
    int var = 5;
    cout << "In main() var is: " << var << "\n\n";

    func();

    cout << "Back in main() var is: " << var << "\n\n";

    {
        cout << "In main() in a new scope var is " << var << "\n\n";

        cout << "Creating a new var in a new scope. \n";
        int var = 10;
        cout << "In main() in a new scope var is " << var << "\n\n";
    }

    cout << "At end of main() var created in new scope no longer exists. \n";
    cout << "At end of main() var is: " << var << "\n";

    cout << endl;

    return 0;
}

void func() {
    int var = -5;
    cout << "In func() var is " << var << "\n\n";    
}