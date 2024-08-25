// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <string>

using std::cout;
//using std::cin;
using std::endl;
//using std::string;
using std::ostream;

// Simple Boss 2.0

class Enemy {
public:
    Enemy();
    void Attack() const;

protected:
    int m_Damage;
};

Enemy::Enemy() : m_Damage(10) {}

void Enemy::Attack() const {
    cout << "Attack inflicts " << m_Damage << " damage points!\n";
}


class Boss : public Enemy {
public:
    Boss();
    void SpecialAttack() const;

private:
    int m_DamageMultiplier;
};

Boss::Boss() : m_DamageMultiplier(3) {}

void Boss::SpecialAttack() const {
    cout << "Special attack inflicts " << (m_DamageMultiplier * m_Damage);
    cout << " damage points!\n";
}


int main() {
    cout << "Creating an enemy.\n";
    Enemy enemy1;
    enemy1.Attack();

    cout << "\nCreating a boss.\n";
    Boss boss1;
    boss1.Attack();
    boss1.SpecialAttack();

    cout << endl;

    return 0;
}

// These base class member functions are not inherited by derived classes:
// Constructors, Copy Constructors, Destructors, Overloaded Assignment Operators
// 
// protected members are only accessible in their own class and certain derived classes
// 