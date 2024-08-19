// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// STL Containers and Psuedocode

int main() { 
    // Psuedocode
    
    // If Snake is suspected by an enemy
    //      The enemy should investigate
    //      Snake should evade
    // Otherwise
    //      The enemy should continue their patrol
    //      Snake can continue sneaking
    // Snake can collect ammo pack
    // Snake can change uniform
    // Snake can leave the area


    // Stepwise Refinement
    
    // Snake can collect ammo pack:

    // Move Snake to ammo's position
    // Add ammo to Snake's inventory
    // Destroy ammo from game world (or add to hidden pool)

    return 0;
}

// STL Containers

// deque            sequential      double-ended queue
// list             sequential      linear list
// map              associative     key/value pairs, 1 key to 1 value
// multimap         associative     key/value pairs, 1 key to 1+ values
// priority_queue   adaptor         priority queue
// queue            adaptor         queue
// set              associative     each elemt is unique
// stack            adaptor         stack
// vector           sequential      dynamic array
