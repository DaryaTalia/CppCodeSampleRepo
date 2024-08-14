// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <iostream>

using namespace std;

// Finicky Counter
int main()
{    
    int count = 0;

    while (true) {
        count += 1;

        //end loop if count is greater than 10
        if (count > 10) {
            break;
        }

        //skip the number 5
        if (count == 5) {
            continue;
        }

        cout << count << endl;
    }

    return 0;
}