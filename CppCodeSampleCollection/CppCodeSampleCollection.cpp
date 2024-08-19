// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Taking Damage

int radiation(int health);

int main() { 
    int health = 80;
    cout << "Your health is " << health << "\n\n";

    health = radiation(health);
    cout << "After radiation exposure your health is " << health << "\n\n";

    health = radiation(health);
    cout << "After radiation exposure your health is " << health << "\n\n";

    health = radiation(health);
    cout << "After radiation exposure your health is " << health << "\n\n";

    cout << endl;

    return 0;
}

inline int radiation(int health) {
    return (health / 2);
}

//  Although obsessing about performance is a game programmer’s favorite hobby, there’s a danger in
// focusing too much on speed. In fact, the approach many developers take is to first get their game
// programs working well before they tweak for small performance gains. At that point, programmers
// will profile their code by running a **utility (a profiler)** that analyzes where the game program spends
// its time. If a programmer sees bottlenecks, he or she might consider **hand optimizations** such as
// function inlining.
//