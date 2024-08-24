// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using std::cout;
// using std::cin;
using std::endl;
using std::string;
using std::ostream;

// Heap Data Member

class Critter {
public:
    Critter(const string& name = " ", int age = 0);
    ~Critter();
    Critter(const Critter& c);
    Critter& operator=(const Critter& c);
    
    void Greet() const;

private:
    // declare a data member as a pointer to point to a value on the heap
    string* m_pName;
    int m_Age;
};

Critter::Critter(const string& name, int age) {
    cout << "Constructor called\n";
    // allocate memory on the heap for a string object
    // new returns a pointer for the object
    m_pName = new string(name);
    m_Age = age;
}

// use destructors (~) to clean up any pointers to the heap
Critter::~Critter() {
    cout << "Destructor called\n";
    delete m_pName;
}

// copy constructor: same name as class, accepts a reference to an object of the class
// make constant to protect og object from change
// default copy construtor creates a member-wise copy
// write custom cc when there are data members that point to a value in the heap
// the default will produce a 'shallow copy' which will only copy the address, not create a
// whole new object, this could create a dangling pointer if the memory is later freed.
// copy constructor can perform a 'deep copy', new object, new chunk of memory
Critter::Critter(const Critter& c) {
    cout << "Copy Constructor called\n";
    m_pName = new string(*(c.m_pName));
    m_Age = c.m_Age;
}

// assignment operator member function
// write custom ao when data members point to the heap
Critter& Critter::operator=(const Critter& c) {
    cout << "Overloaded Assignment Operator called\n";
    if(this != &c) {
        delete m_pName;
        m_pName = new string(*(c.m_pName));
        m_Age = c.m_Age;
    }
    return *this;
}

void Critter::Greet() const {
    cout << "I'm " << *m_pName << " and I'm " << m_Age << " years old.\n";
    cout << "&m_pName: " << &m_pName << endl;
}

void testDestructor();
void testCopyConstructor(Critter aCopy);
void testAssignmentOp();

int main() {
    testDestructor();
    cout << endl;

    Critter crit("Poochie", 5);
    crit.Greet();
    testCopyConstructor(crit);
    crit.Greet();
    cout << endl;

    testAssignmentOp();

    cout << endl;

    return 0;
}

void testDestructor() {
    Critter toDestroy("Rover", 3);
    toDestroy.Greet();
}

void testCopyConstructor(Critter aCopy) {
    aCopy.Greet();
}

void testAssignmentOp() {
    Critter crit1("cri1", 7);
    Critter crit2("cri2", 9);
    crit1 = crit2;

    crit1.Greet();
    crit2.Greet();
    cout << endl;

    Critter crit3("crit3", 11);
    crit3 = crit3;
    crit3.Greet();
}