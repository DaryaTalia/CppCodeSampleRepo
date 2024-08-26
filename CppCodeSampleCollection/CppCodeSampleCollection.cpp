// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <string>

using std::cout;
//using std::cin;
using std::endl;
//using std::string;
using std::ostream;

// Abstract Creature

class Creature {    // abstract class due to at least 1 pure virtual member function
public:
    Creature(int health = 100);
    virtual void Greet() const = 0;     // pure virtual member function, fx implementation depends on derived classes
    virtual void DisplayHealth() const;

protected:
    int m_Health;
};

Creature::Creature(int health) : m_Health(health) {}

void Creature::DisplayHealth()  const {
    cout << "Health: " << m_Health << endl;
}


class Orc : public Creature {
public:
    Orc(int health = 20);
    virtual void Greet() const;
};

Orc::Orc(int health) : Creature(health) {}

void Orc::Greet() const {
    cout << "The orc grunts hello.\n";
}


int main() {
    Creature* pCreature = new Orc();
    pCreature->Greet();
    pCreature->DisplayHealth();

    cout << endl;

    return 0;
}
