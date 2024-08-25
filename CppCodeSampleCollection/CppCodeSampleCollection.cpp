// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;

// Game Lobby 2.0

class Player {
    friend ostream& operator<<(ostream& os, const Player& aPlayer);

public:
    Player(const string& name = " ");
    string GetName() const;
    Player* GetNext() const;
    void SetNext(Player* next);

private:
    string m_Name;
    Player* m_pNext; //Pointer to next player in list
};

Player::Player(const string& name) : m_Name(name), m_pNext(0) {}

string Player::GetName() const {
    return m_Name;
}

Player* Player::GetNext() const {
    return m_pNext;
}

void Player::SetNext(Player* next) {
    m_pNext = next;
}

ostream& operator<<(ostream& os, const Player& aPlayer) {
    os << aPlayer.GetName();
    return os;
}


// an aggragate of player objects
class Lobby {
    friend ostream& operator<<(ostream& os, const Lobby& aLobby);

public:
    Lobby();
    ~Lobby();
    void AddPlayer();
    void RemovePlayer();
    void Clear();

private:
    Player* m_pHead;
    Player* m_pTail;
};

Lobby::Lobby(): m_pHead(0) { }

Lobby::~Lobby() {
    Clear();
}

void Lobby::AddPlayer() {
    // create a new player node
    cout << "Please enter the name of the new player: ";
    string name;
    cin >> name;
    Player* pNewPlayer = new Player(name);

    if (m_pHead == 0) {
        m_pHead = pNewPlayer;
    }
    else {
        m_pTail->SetNext(pNewPlayer);
    }

    m_pTail = pNewPlayer;
}

void Lobby::RemovePlayer() {
    if (m_pHead == 0) {
        cout << "The game lobby is empty. No one to remove!\n";
    }
    else {
        // save the memory address of the head player to a new pointer
        Player* ptemp = m_pHead;
        // change the head player to the next player
        m_pHead = m_pHead->GetNext();
        // free the memory chunk m_pHead was using from the heap
        delete ptemp;
    }
}

void Lobby::Clear() {
    while (m_pHead != 0) {
        RemovePlayer();
    }
}

ostream& operator<<(ostream& os, const Lobby& aLobby) {
    Player* pIter = aLobby.m_pHead;
    os << "\nHere's who's in the game lobby: \n";
    if (pIter == 0) {
        os << "The lobby is empty.\n";
    }
    else {
        while (pIter != 0) {
            os << (*pIter);
            pIter = pIter->GetNext();
        }
    }

    return os;
}


int main() {
    Lobby myLobby;
    int choice;

    do {
        cout << myLobby;
        cout << "\nGAME LOBBY\n";

        cout << "0 - Exit the program.\n";
        cout << "1 - Add a player to the lobby.\n";
        cout << "2 - Remove a player from the lobby.\n";
        cout << "3 - Clear the lobby.\n";

        cout << endl << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 0: cout << "Good-bye.\n"; break;
        case 1: myLobby.AddPlayer(); break;
        case 2: myLobby.RemovePlayer(); break;
        case 3: myLobby.Clear(); break;
        default: cout << "That was not a valid choice.\n";
        }
    } 
    
    while (choice != 0);

    cout << endl;

    return 0;
}
