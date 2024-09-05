// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ctime;
using std::vector;
using std::map;
using std::make_pair;

// Observer Pattern

/////////////////////////////////////////////////////////////////////////////
// Declarations

enum class Event {};

class Entity {

};

// Command Pattern for delegates
class Delegate {
public:
    void virtual Execute() {};
};

class Observer {
public:
    Observer() : _next(NULL), _prev(NULL) {};
    virtual ~Observer() {};
    virtual void OnNotify(const Entity& entity, Event event) = 0;
    Observer* GetNext() {
        return _next;
    }
    Observer* GetPrev() {
        return _prev;
    }
private:
    Observer* _next;
    Observer* _prev;
};

// Event Manager
class Subject {
public:
    Subject() : _head(NULL), _tail(NULL) {}
    Subject(Observer* observer) : _head(observer), _tail(NULL) {}

    void AddObserver(Observer* observer);
    void RemoveObserver(Observer* observer);
    
private:
    Observer* _head;
    Observer* _tail;

protected:
    void Notify(const Entity& entity, Event event);
};

class Player {

};

class Collectable {

};

class Game {

};

class HUD : public Entity, Observer {
    friend class Subject;

public:
    HUD() : Observer() {};
    ~HUD();
    virtual void OnNotify(const Entity& entity, Event event);

private:
    void UpdateHUD();
    Observer* _next;
    Observer* _prev;
};

class GameManager : public Entity {

};

class AudioManager : public Entity {

};

/////////////////////////////////////////////////////////////////////////////

// Subject Defs
void Subject::Notify(const Entity& entity, Event event) {
    for (Observer* iter = _head;
        iter != NULL;
        ++iter) {
        iter->OnNotify(entity, event);
        iter = iter->GetNext();
    }
}

// Player Defs


// Collectable Defs


// Game Defs


// HUD Defs

class UpdateHUDDelegate : public Delegate {
public:
    UpdateHUDDelegate(HUD* hud) : _myHUD(hud) {};
    void virtual Execute() {
        //_myHUD->UpdateHUD();
    }

private:
    HUD* _myHUD;
};


// GameManager Defs


// AudioManager Defs


/////////////////////////////////////////////////////////////////////////////
// Main

int main()
{
    cout << "Game Over!" << endl;
    return 0;
}


