// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Critter Caretaker

class Critter {
public:
    static int s_Total;             

    Critter(int hunger = 0, int boredom = 0);
    ~Critter();

    static int GetTotal();        

    int GetHunger() const;
    void SetHunger(int hunger);
    int GetBoredom() const;
    void SetBoredom(int boredom);

    void Greet();
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);


private:
    int m_Hunger;
    int m_Boredom;

    int GetMood() const;
    void PassTime(int time = 1);
};

int Critter::s_Total = 0;          

Critter::Critter(int hunger, int boredom) : m_Hunger(hunger), m_Boredom(boredom) {
    cout << "A new critter has been born!" << endl;
    ++s_Total;
    Greet();
}

Critter::~Critter() {
    cout << "Bye!" << endl;
    s_Total--;
}

int Critter::GetTotal() {          
    return s_Total;
}

int Critter::GetHunger() const {
    return m_Hunger;
}

void Critter::SetHunger(int hunger) {
    if (hunger < 0) {
        m_Hunger = 0;
    }
    else {
        m_Hunger = hunger;
    }
}

int Critter::GetBoredom() const {
    return m_Boredom;
}

void Critter::SetBoredom(int boredom) {
    if (boredom < 0) {
        m_Boredom = 0;
    }
    else {
        m_Boredom = boredom;
    }
}

void Critter::Greet() {
    cout << "Hi. I'm a critter. My hunger level is " << m_Hunger << ".\n\n";
}

void Critter::Talk() {
    cout << "I feel ";

    int mood = GetMood();
    if (mood > 15) {
        cout << "mad.\n";
    }
    else if (mood > 10) {
        cout << "frustrated.\n";
    }
    else if (mood > 5) {
        cout << "okay.\n";
    }
    else {
        cout << "happy.\n";
    }

    if (m_Hunger > m_Boredom) {
        cout << "I could eat!";
    } else if (m_Hunger < m_Boredom) {
        cout << "I could play!";
    }
    cout << endl << endl;

    PassTime();
}

void Critter::Eat(int food) {
    cout << "MM, good!\n\n";
    SetHunger(GetHunger() - food);
    PassTime();
}

void Critter::Play(int fun) {
    cout << "You can't catch me!\n\n";
    SetBoredom(GetBoredom() - fun);
    PassTime();
}

void Critter::PassTime(int time) {
    m_Hunger += time;
    m_Boredom += time;
}

int Critter::GetMood() const {
    return (m_Hunger + m_Boredom);
}





int main() {
    bool playAgain = true;
    char play;

    Critter yourCritter;

    cout << "Welcome to Critter Caretaker!\n\n";

    while (playAgain) {
        // Print Legend
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n";
        cout << "4 - See your critter's stats\n";

        // Get Player Choice
        int input = -1;
        while (input < 0 || input > 4) {
            cout << "\nChoice:\t";
            cin >> input;
        }

        // Evaluate Player Choice
        switch (input) {
        case 0: {
            playAgain = false;
            cout << "Quitting the Critter Caretaker game...\n";
            break;
        }

        case 1: {
            yourCritter.Talk();
            break;
        }

        case 2: {
            yourCritter.Eat();
            break;
        }

        case 3: {
            yourCritter.Play();
            break;
        }

        case 4: {
            cout << endl;
            cout << "Hunger: " << yourCritter.GetHunger() << endl;
            cout << "Boredom: " << yourCritter.GetBoredom() << endl;
            cout << endl;
            break;
        }

        default: {
            cout << "Invalid input.";
            break;
        }
        }
    }

    cout << endl;

    return 0;
}

// Psuedocode
// 
// Create one critter
// 
// While the game is active, do the following:
//      Print a Legend for available player actions
//      Wait for valid player input
//      Switch to the correct critter or game function based on player input
//      Output the selected function or exit the game
//