// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ctime;
using std::vector;

// Command Pattern
// Phone

// Declarations

class Command {
public:
    void virtual Execute() {};
};

class Phone {
public:
    Phone() {};
    void TouchScreen();
    Command SetCommand(Command* command);
    ~Phone();
private:
    Command* _command = 0;
};

class Clock {
public:
    Clock();
    ~Clock();
    void SetAlarm(int min);
    void EndAlarm();
    void StartStopwatch();
    void EndStopwatch();
    void LapStopwatch();
    void UpdateClock();
private:
    vector<int> *_laps;              // store elapsed seconds foreach lap in lapped order
    int *_remainingAlarmTime;        // in seconds, active if greater than 0
    int *_elapsedStopwatchTime;      // in seconds
    bool* _stopwatchActive;
};

class SetAlarmCommand : public Command {
public:
    SetAlarmCommand(Clock* clock, int min) : _myClock(clock), _min(min) {};
    void virtual Execute() {
        _myClock->SetAlarm(_min);
    }
private:
    Clock* _myClock;
    int _min;
};

class EndAlarmCommand : public Command {
public:
    EndAlarmCommand(Clock* clock) : _myClock(clock) {};
    void virtual Execute() {
        _myClock->EndAlarm();
    }
private:
    Clock* _myClock;
};

class StartStopwatchCommand : public Command {
public:
    StartStopwatchCommand(Clock* clock) : _myClock(clock) {};
    void virtual Execute() {
        _myClock->StartStopwatch();
    }
private:
    Clock* _myClock;
};

class EndStopwatchCommand : public Command {
public:
    EndStopwatchCommand(Clock* clock) : _myClock(clock) {};
    void virtual Execute() {
        _myClock->EndStopwatch();
    }
private:
    Clock* _myClock;
};

class LapStopwatchCommand : public Command {
public:
    LapStopwatchCommand(Clock* clock) : _myClock(clock) {};
    void virtual Execute() {
        _myClock->LapStopwatch();
    }
private:
    Clock* _myClock;
};

class UpdateClockCommand : public Command {
public:
    UpdateClockCommand(Clock* clock) : _myClock(clock) {};
    void virtual Execute() {
        _myClock->UpdateClock();
    }
private:
    Clock* _myClock;
};

// Main

int main()
{
    Clock* clock1 = new Clock();

    Phone* phone = new Phone();

    phone->SetCommand(new UpdateClockCommand(clock1));
    phone->TouchScreen();

    cout << endl;
    return 0;
}


// Definitions

Phone::~Phone() {
    delete _command;
    cout << "Phone pointers cleaned.";
}

void Phone::TouchScreen() {
    _command->Execute();
}

Command Phone::SetCommand(Command* command) {
    _command = command;
    return *_command;
}

// Clock

Clock::Clock() {
    _laps = new vector<int>;
    _remainingAlarmTime = new int(0);
    _elapsedStopwatchTime = new int(0);
    _stopwatchActive = new bool(false);
}

Clock::~Clock() {
    delete _remainingAlarmTime;
    delete _elapsedStopwatchTime;
    delete _stopwatchActive;
    vector<int>::iterator iter;
    for (iter = (*_laps).begin(); iter != (*_laps).end(); ++iter) {
         *iter = 0;
    }
    delete _laps; 
    
    cout << "Clock pointers cleaned.";
}

void Clock::SetAlarm(int min) {
    *_remainingAlarmTime = min * 60;
    cout << min << " minute alarm set.\n";
}

void Clock::EndAlarm() {
    *_remainingAlarmTime = 0;
    cout << "Alarm cancelled.\n";
}

void Clock::StartStopwatch() {
    cout << "Stopwatch starting.\n";
    *_stopwatchActive = true;
}

void Clock::EndStopwatch() {
    cout << "Stopwatch ending at " << *_elapsedStopwatchTime << ".\n";
    if (!_laps->empty()) {
        int i = 1;
        for (vector<int>::iterator iter = (*_laps).begin(); iter != (*_laps).end(); ++iter, ++i) {
            cout << "Lap " << i << ": " << *iter << endl;
        }
    }
    *_stopwatchActive = false;
    (*_laps).clear();
    *_elapsedStopwatchTime = 0;
}

void Clock::LapStopwatch() {
    (*_laps).push_back(*_elapsedStopwatchTime);
    cout << "Lap recorded.\n";
}

void Clock::UpdateClock() {
    // alarm
    if (*_remainingAlarmTime > 0) {
        --(*_remainingAlarmTime);
        cout << "Remaining Alarm Time: " << *_remainingAlarmTime << endl;

        if (*_remainingAlarmTime == 0) {
            cout << "Alarm Ended!\n";
        }
    }
    else {
        cout << "No alarm set.\n";
    }

    cout << endl;

    // stopwatch
    if (*_stopwatchActive) {
        ++(*_elapsedStopwatchTime);
        cout << "Elapsed Stopwatch: " << *_elapsedStopwatchTime << endl;
    } else {
        cout << "Stopwatch disabled.\n";
    }

    cout << endl;
}



//