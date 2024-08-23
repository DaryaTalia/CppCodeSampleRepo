// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// Critter Farm

class Critter {
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
    string m_Name; // relationship, "has-a" string object
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

// accepts a cpnstant refernce to a Critter object
// adds a copy of the object to the m_Critters vector
// this creates an extra copy of each Critter object every time called
// performance overhead could be reduced by using a vector of pointers to objects
void Farm::Add(const Critter& aCritter) {
    m_Critters.push_back(aCritter);
}

void Farm::RollCall() const {
    for (vector<Critter>::const_iterator iter = m_Critters.begin(); iter != m_Critters.end(); iter++)
    {
        cout << iter->GetName() << " here.\n";
    }
}



int main() {
    bool playAgain = true;
    char play;

    cout << "Welcome to Critter Caretaker!\n\n";

    while (playAgain) {
        Critter crit("Poochie");
        cout << "My critter's name is " << crit.GetName() << endl;

        cout << "\nCreating critter farm.\n";
        Farm myFarm(3);

        cout << "\nAdding three critters to the farm.\n";
        myFarm.Add(Critter("Moe"));     // constructs and deconstructs object long enough for use
        myFarm.Add(Critter("Larry"));
        myFarm.Add(Critter("Curly"));

        cout << "\nCalling Roll...\n";
        myFarm.RollCall();

        playAgain = false;
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