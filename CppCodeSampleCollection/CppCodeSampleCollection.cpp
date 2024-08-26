// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <string>

using std::cout;
//using std::cin;
using std::endl;
//using std::string;
using std::ostream;

// Polymorphc Bad Guy

class Enemy {
public:
    Enemy(int damage = 10);
    // make virtual to overrude and clear memory in derived classes
    virtual ~Enemy();
    Enemy& operator=(const Enemy& e);
    void virtual Taunt() const;        // made virtual to be overridden
    void virtual Attack() const;        // made virtual to be overridden

protected:
    int* m_pDamage;
};

Enemy::Enemy(int damage) {
    m_pDamage = new int(damage);
}

Enemy::~Enemy() {
    cout << "In Enemy destructor, deleting m_pDamage.\n";
    delete m_pDamage;
    m_pDamage = 0;
}

Enemy& Enemy::operator=(const Enemy& e) {
    return *this;
}

void Enemy::Taunt() const {
    cout << "The enemy says he will fight you.\n";
}

void Enemy::Attack() const {
    cout << "An enemy attacks and inflicts " << *m_pDamage << " damage points.\n";
}


class Boss : public Enemy {
public:
    Boss(int multiplier = 3);
    virtual ~Boss();
    Boss& operator=(const Boss& b);
    void virtual Taunt() const;         // optional use of virtual keyword
    void virtual Attack() const;        // optional use of virtual keyword

protected:
    int* m_pMultiplier;
};

Boss::Boss(int multiplier) {
    m_pMultiplier = new int(multiplier);
}

Boss::~Boss() {
    cout << "In Boss destructor, deleting m_pMultiplier.\n";
    delete m_pMultiplier;
    m_pMultiplier = 0;
}

// Not inherited from base class
Boss& Boss::operator=(const Boss& b) { // or add    : Enemy(b) to handle inherited data members
    Enemy::operator=(b);    // handles the data members inherited from Enemy
    return *this;
}

void Boss::Taunt() const {              // override base class member function
    cout << "The boss says he will end your pitiful existence.\n";
}

void Boss::Attack() const {
    cout << "A boss attacks and inflicts " << (*m_pDamage) * (*m_pMultiplier) << " damage points.\n";
}


int main() {
    cout << "Calling Attack() on Boss object through pointer to Enemy:\n\n";
    // can interact with derived objects w/o exactly knowing their type
    Enemy* pBadGuy = new Boss();
    pBadGuy->Attack();

    cout << "\n\nDeleting pointer to Enemy:\n";
    // derived objects delete in reversed order
    delete pBadGuy;
    pBadGuy = 0;

    cout << endl;

    return 0;
}
