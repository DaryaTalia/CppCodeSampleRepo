// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

// Favorite Games

int main() { 
    bool appLoop = true;
    const char exitKey = 'q';
    const char addKey = 'a';
    const char deleteKey = 'd';
    const char viewKey = 'v';
    char key = ' ';
    string game = "";

    vector<string> favoriteGames;
    vector<string>::const_iterator iter;
    vector<string>::iterator gameIterator;

    while (appLoop) {
        // App

        cout << "Legend: \n";

        cout << " - '" << addKey << "' to add a new favorite game.\n";
        cout << " - '" << deleteKey << "' to delete an existing favorite game.\n";
        cout << " - '" << viewKey << "' to view all of your favorite games.\n";
        cout << " - '" << exitKey << "' to exit the app.\n";

        // Key Validation
        do {
            cout << "\nEnter a key: ";
            cin >> key;
            cin.ignore();
        }             
        while (key != addKey && key != deleteKey && key != viewKey && key != exitKey);

        // App Actions
        switch (key) {
            case addKey: {
                // Game Key Validation
                cout << "\n[ADD] Enter the name of the game followed by the enter key:\t";
                getline(cin, game);
                cin.ignore();

                favoriteGames.push_back(game);
                cout << "\n'" << game << "' has been entered into system.\n";
                break;
            }
            case deleteKey: {
                cout << "\n[DELETE] Enter the name of the game followed by the enter key:\t";
                getline(cin, game);
                cin.ignore();

                if (find(favoriteGames.begin(), favoriteGames.end(), game) != favoriteGames.end()) {
                    favoriteGames.erase(find(favoriteGames.begin(), favoriteGames.end(), game));
                    cout << "\n'" << game << "' has been deleted from system.\n";
                }
                else {
                    cout << "\n'" << game << "' is not in the system.\n";
                }
                break;
            }
            case viewKey: {
                cout << "\n[VIEW] Favorite Games:\n";
                for (iter = favoriteGames.begin(); iter != favoriteGames.end(); iter++) {
                    cout << *iter << "\n";
                }
                break;
            }
            case exitKey: {
                cout << "\n[EXIT] Exiting the app. Goodbye";
                appLoop = false;
                break;
            }
            default: {
                cout << "\nInvalid key entered."; 
                break;
            }
        }

        cout << endl;
    }

    cout << endl;

    return 0;
}
