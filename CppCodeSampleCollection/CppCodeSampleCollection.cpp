// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <iostream>
#include <string>

using namespace std;

// Designers Network
int main()
{    
    string username, password;
    bool success;

    cout << "\tGame Designer's Network\n";

    do 
    {
        cout << "\nUsername: ";
        cin >> username;

        cout << "\nPassword: ";
        cin >> password;

        if (username == "S.Meier" && password == "civilization") {
            cout << "\nHey, Sid.";
            success = true;
        } 
        else if(username == "S.Miyamoto" && password == "mariobros") {
            cout << "\nWhat's up, Shigeru?";
            success = true;
        }
        else if (username == "W.Wright" && password == "thesims") {
            cout << "\nHow goes it, Will?";
            success = true;
        }
        else if (username == "H.Kojima" && password == "metalgear") {
            cout << "\nHi, Hideo!";
            success = true;
        }
        else if (username == "guest" && password == "guest") {
            cout << "\nWelcome, guest.";
            success = true;
        }
        else {
            cout << "\nYour login failed.";
            success = false;
        }
    }

    while(!success);

    return 0;
}