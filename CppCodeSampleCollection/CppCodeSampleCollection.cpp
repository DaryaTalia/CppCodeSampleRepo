// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
// using std::cin;
using std::endl;

// Heap

int* intOnHeap();   // returns an int on the heap
void leak1();       // creates a memory leak
void leak2();       // creates another memory leak

int main() {
    // the new operator allocates memory on the heap and returns its address
    // use new followed by the type of value to reserve space for
    // pHeap points to allocated memory on the heap and not the stack
    int* pHeap = new int;
    *pHeap = 10;
    cout << "*pHeap: " << *pHeap << "\n\n";

    // memory on the heap can persist beyond the function in which it was allocated
    int *pHeap2 = intOnHeap();
    cout << "*pHeap2: " << *pHeap2 << "\n\n";

    cout << "Freeing memory pointed to by pHeap.\n\n";
    // memory on the heap must be explicitly freed
    // if 'new' is used, 'delete' must also be used
    delete pHeap; 

    cout << "Freeing memory pointed to by pHeap2.\n\n";
    delete pHeap2;

    // memory is now free on the heap but the local variables aren't directly affected
    // pHeap and pHeap2 are now dangling pointers

    // get rid of dangling pointers
    // never attempt to derefernce a dangling pointer
    // assign them with 0
    pHeap = 0;
    pHeap2 = 0;

    cout << endl;

    return 0;
}

// creates an object on the heap and returns a pointer or reference to it
// returns a pointer to this chunk of memory thanks to dynamic memory
int* intOnHeap() {
    int* pTemp = new int(20);
    return pTemp;
}

// memory leaks: allocating memory but losing any way to access it again or feee it
// large leaks can cause a program to run out of memory and crash

// memory lost until the programs ends
// drip1 is a local variable and the only way to access this chunk of memory
// local variable will stop existing after this scope region ends 
// but the corresponding memory will still be reserved for int(30)
// no way to free the allocated meory
// ways to resolve: delete to free the memory, or return a copy of the pointer drip1
// memory should later be freed elsewhere if a pointer is returned
void leak1() {
    int* drip1 = new int(30);
}

void leak2() {
    // one chunk of memory
    int* drip2 = new int(50);
    // another chunk of memory
    drip2 = new int(100);   // int(50) is no longer accessible
    delete drip2;           // only frees int(100)
    // drip2 was a dangling pointer, but will stop existing at the end of this function
}