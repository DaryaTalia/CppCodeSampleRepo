// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <string>

using std::cout;
//using std::cin;
using std::endl;
//using std::string;
using std::ostream;

// Overriding Boss

class Enemy {
public:
    Enemy(int damage = 10);
    Enemy& operator=(const Enemy& e) {};
    void virtual Taunt() const;        // made virtual to be overridden
    void virtual Attack() const;        // made virtual to be overridden

protected:
    int m_Damage;
};

Enemy::Enemy(int damage) : m_Damage(damage) {}

Enemy& Enemy::operator=(const Enemy& e) {
    return *this;
}

void Enemy::Taunt() const {
    cout << "The enemy says he will fight you.\n";
}

void Enemy::Attack() const {
    cout << "Attack! Inflicts " << m_Damage << " damage points!\n";
}


class Boss : public Enemy {
public:
    Boss(int damage = 30);
    Boss& operator=(const Boss& b) {};
    void virtual Taunt() const;         // optional use of virtual keyword
    void virtual Attack() const;        // optional use of virtual keyword
};

Boss::Boss(int damage) : Enemy(damage) {} // call base class constructor with argument

// Not inherited from base class
Boss& Boss::operator=(const Boss& b) { // or add    : Enemy(b) to handle inherited data members
    Enemy::operator=(b);    // handles the data members inherited from Enemy
    return *this;
}

void Boss::Taunt() const {              // override base class member function
    cout << "The boss says he will end your pitiful existence.\n";
}

void Boss::Attack() const {
    Enemy::Attack();                    // call base class member function
    cout << "And laughs heartily at you.\n";
}


int main() {
    cout << "Enemy object:\n";
    Enemy anEnemy;
    anEnemy.Taunt();
    anEnemy.Attack();

    cout << "\n\nBoss object:\n";
    Boss aBoss;     // the Enemy constructor is called first, and then the Boss constructor
    aBoss.Taunt();
    aBoss.Attack();

    cout << endl;

    return 0;
}

// Declare any base class member function to be overridden as virtual
// Provides a way for overridden versions of the member function to work as expected
// with pointers and references to objects.
// 
// the virtual keyword is only needed in the declaration, not the definition
// 
// once a member function has been declared as virtual, it's virtual in any dervied class.
// the virtual keyword doesn not need to be used again, but can be useful to recognize
// a function as being virtual.
// 
// when you override an overloaded base class member function, all other overloaded versions
// are hideen. the only way to access other versions is to explicitly call the base class
// member function. Good idea to override every version of the overloaded function 
// if one is overloaded.
// 