// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using std::cout;
// using std::cin;
using std::endl;
using std::ostream;
using std::string;
using std::vector;

// Critter Friend

class Critter {
    // make following global functions friends of the Critter class
    // friend is a special keyword that can be used inside a class definition
    friend void Peek(const Critter& aCritter);
    // operator overloading allows controlled meaning over built-in operators for new defined types
    // syntax: operatorX, where X is the operator to be overloaded
    // cout is of the type ostream which already overloads the << operator
    friend ostream& operator<< (ostream& os, const Critter& aCriiter);

public:
    static int s_Total;             

    Critter(int hunger = 0, int boredom = 0);
    Critter(const string& name = " ");
    ~Critter();

    static int GetTotal();        

    int GetHunger() const;
    void SetHunger(int hunger);
    int GetBoredom() const;
    void SetBoredom(int boredom);

    string GetName() const;
    void Greet();
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);


private:
    string m_Name;
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

Critter::Critter(const string& name) : m_Name(name) { 
    m_Hunger = 0;
    m_Boredom = 0;
}

Critter::~Critter() {
    cout << "Bye!" << endl;
    s_Total--;
}

int Critter::GetTotal() {          
    return s_Total;
}

inline string Critter::GetName() const
{
    return m_Name;
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


class Farm {
public:
    Farm(int spaces = 1);
    void Add(const Critter& aCritter);
    void RollCall() const;

private:
    vector<Critter> m_Critters;
};

Farm::Farm(int spaces) {
    m_Critters.reserve(spaces); //Allocating space for the variable amount of Critter objects
}

void Farm::Add(const Critter& aCritter) {
    m_Critters.push_back(aCritter);
}

void Farm::RollCall() const {
    for (vector<Critter>::const_iterator iter = m_Critters.begin(); iter != m_Critters.end(); iter++)
    {
        cout << iter->GetName() << " here.\n";
    }
}


void Peek(const Critter& aCritter);
ostream& operator<<(ostream& os, const Critter& aCritter);


int main() {
    bool playAgain = true;
    char play;

    cout << "Welcome to Critter Caretaker!\n\n";

    while (playAgain) {
        Critter crit("Poochie");
        cout << "My critter's name is " << crit.GetName() << endl;

        cout << "\nCalling Peek() to access crit's private data member, m_name: \n";
        Peek(crit);

        cout << "\nSending crit object to cout with the << operator: \n";
        cout << crit;

        playAgain = false;
    }

    cout << endl;

    return 0;
}

// global friend function which can access all of a Critter object's members
void Peek(const Critter& aCritter) {
    cout << aCritter.m_Name << endl;
}

// global friend function which can access all of Critter object's members
// overloads the << operator so you can send a Critter object to cout
ostream& operator<< (ostream& os, const Critter& aCritter) {
    os << "Critter Object - ";
    os << "m_Name: " << aCritter.m_Name;
    return os;
}