// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <string>

using std::cout;
//using std::cin;
using std::endl;
//using std::string;
using std::ostream;

// Simple Boss

class Enemy {
public:
    int m_Damage;

    Enemy();
    void Attack() const;

};

Enemy::Enemy() : m_Damage(10) {}

void Enemy::Attack() const {
    cout << "Attack inflicts " << m_Damage << " damage points!\n";
}


class Boss : public Enemy {
public:
    int m_DamageMultiplier;

    Boss();
    void SpecialAttack() const;
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
