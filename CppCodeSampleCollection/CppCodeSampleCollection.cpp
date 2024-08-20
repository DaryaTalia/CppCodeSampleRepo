// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Static Critter

// For Classes, members are private by default
class Critter {
public:
    static int s_Total;             //static member variable declaration, s_

    Critter(int hunger = 0);
    ~Critter();
    static int GetTotal();          //static member function prototype
    int GetHunger() const;
    void SetHunger(int hunger);
    void Greet();

private:
    int m_Hunger;

};

int Critter::s_Total = 0;           //static member variable initialization

Critter::Critter(int hunger) : m_Hunger(hunger) {
    cout << "A new critter has been born!" << endl;
    ++s_Total;
    Greet();
}

Critter::~Critter() {
    cout << "Bye!" << endl;
    s_Total--;
}

int Critter::GetTotal() {           //static member function definition
    return s_Total;
}

int Critter::GetHunger() const {
    return m_Hunger;
}

void Critter::SetHunger(int hunger) {
    if (hunger < 0) {
        cout << "You can't set a critter's hunger to a negative number.\n\n";
    }
    else {
        m_Hunger = hunger;
    }
}

void Critter::Greet() {
    cout << "Hi. I'm a critter. My hunger level is " << m_Hunger << ".\n\n";
}

int main() {
    cout << "The total number of critters is: ";
    cout << Critter::GetTotal() << "\n\n";

    Critter crit1(5), crit2, crit3;
    cout << "Calling GetHunger(): " << crit1.GetHunger() << "\n\n";

    cout << "Calling SetHunger() with a -1.\n";
    crit1.SetHunger(-1);

    cout << "Calling SetHunger() with a 9.\n";
    crit1.SetHunger(9);

    cout << "Calling GetHunger(): " << crit1.GetHunger() << "\n\n";

    {
        //Exists inside this scope only
        Critter crit4;

        cout << "The total number of critters is: ";
        cout << Critter::GetTotal() << "\n\n";
    }

    cout << "The total number of critters is: ";
    cout << Critter::GetTotal() << "\n\n";

    cout << endl;

    return 0;
}
