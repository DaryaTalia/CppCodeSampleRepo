// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Private Critter

// For Classes, members are private by default
class Critter {
public:
    Critter(int hunger = 0);
    int GetHunger() const;          // accessor member function allows indirect access
    void SetHunger(int hunger);
    void Greet();

private:
    int m_Hunger;

};

Critter::Critter(int hunger) : m_Hunger(hunger) {
    cout << "A new critter has been born!" << endl;
    Greet();
}

// constant member functions can't modify a data member of its class or call a non-constant member function of its class
// const at the end of the function header
// ask only for what you need!
// constant member functions *can* alter static data members
// if a data member is keyworded with "mutable", even a constant member function can modify it
int Critter::GetHunger() const {
    return m_Hunger;
}

void Critter::SetHunger(int hunger) {     // accessor member function allows controlled access
    if (hunger < 0) {
        cout << "You can't set a critter's hunger to a negative number.\n\n";
    }
    else {
        m_Hunger = hunger;
    }
}

// Member function definition
void Critter::Greet() {
    cout << "Hi. I'm a critter. My hunger level is " << m_Hunger << ".\n\n";
}

int main() {
    Critter crit(5);
    //cout << crit.m_Hunger;        // illegal, m_Hunter is private
    cout << "Calling GetHunger(): " << crit.GetHunger() << "\n\n";

    cout << "Calling SetHunger() with a -1.\n";
    crit.SetHunger(-1);

    cout << "Calling SetHunger() with a 9.\n";
    crit.SetHunger(9);

    cout << "Calling GetHunger(): " << crit.GetHunger() << "\n\n";

    cout << endl;

    return 0;
}
