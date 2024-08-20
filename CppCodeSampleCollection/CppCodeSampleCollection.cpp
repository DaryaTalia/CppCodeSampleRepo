// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Critter Constructor

// Class Definition
// New type
class Critter {
public:
    int m_Hunger; //data member, m_

    Critter(int hunger = 0);
    void Greet(); // member function prototype
};

// Could also use Member Initializers:
// Critter::Critter(int hunger = 0, int boredom = 0):
// m_Hunger(hunger),        // dataMember = parameter
// m_Boredom(boredom) {}    // empty constructor body
Critter::Critter(int hunger) {
    cout << "A new critter has been born!" << endl;
    m_Hunger = hunger;
    Greet();
}

// Member function definition
void Critter::Greet() {
    cout << "Hi. I'm a critter. My hunger level is " << m_Hunger << ".\n\n";
}

int main() {
    Critter crit1;
    Critter crit2(7);

    cout << endl;

    return 0;
}
