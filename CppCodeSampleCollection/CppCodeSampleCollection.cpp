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

// Command Pattern
// Phone

// Global Variables
bool engaged;

clock_t lastTime;


class Command {
public:
    void virtual Execute() {};
};

class App {};

// Clock class
class Clock : public App {
public:
    Clock();
    ~Clock();
    void SetAlarm(int min);
    void EndAlarm();
    void StartStopwatch();
    void EndStopwatch();
    void LapStopwatch();
    void UpdateClock();
    void UpdateClockDelta();
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

class UpdateClockDeltaCommand : public Command {
public:
    UpdateClockDeltaCommand(Clock* clock) : _myClock(clock) {};
    void virtual Execute() {
        _myClock->UpdateClockDelta();
    }
private:
    Clock* _myClock;
};


// Calendar class
class Calendar : public App {

};


// Music class
class Music : public App {

};

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

void Clock::UpdateClockDelta() {
    int elapsed = (clock() - lastTime) / CLOCKS_PER_SEC;

    // alarm
    if (*_remainingAlarmTime > 0) {
        (*_remainingAlarmTime) -= elapsed;
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
        (*_elapsedStopwatchTime) += elapsed;
        cout << "Elapsed Stopwatch: " << *_elapsedStopwatchTime << endl;
    }
    else {
        cout << "Stopwatch disabled.\n";
    }

    cout << endl;
}


// Phone

class Phone {
public:
    Phone();
    void TouchScreen();
    Command SetCommand(Command* command);
    Clock* GetClock();
    Calendar* GetCalendar();
    Music* GetMusic();
    void UpdateApps();
    ~Phone();
private:
    Command* _command = 0;
    map<string, App*>* _appMap;
    vector<Command*>* _updateCommands;
};

Phone::Phone() {
    _appMap = new map<string, App*>();
    _appMap->insert(make_pair(string("Clock"), new Clock()));
    _appMap->insert(make_pair("Calendar", new Calendar()));
    _appMap->insert(make_pair("Music", new Music()));

    _updateCommands = new vector<Command*>();
    _updateCommands->push_back(new UpdateClockDeltaCommand(GetClock()));

    cout << "Phone initialized.";
}

Phone::~Phone() {
    delete _command;
    _appMap->clear();
    delete _appMap;
    cout << "Phone pointers cleaned.";
}

void Phone::TouchScreen() {
    _command->Execute();
}

Command Phone::SetCommand(Command* command) {
    _command = command;
    return *_command;
}

Clock* Phone::GetClock() {
    return (Clock*)(*_appMap)["Clock"];
}

Calendar* Phone::GetCalendar() {
    return (Calendar*)(*_appMap)["Calendar"];
}

Music* Phone::GetMusic() {
    return (Music*)(*_appMap)["Music"];
}

void Phone::UpdateApps() {
    std::vector<Command*>::const_iterator iter;
    for (iter = (*_updateCommands).begin(); iter != (*_updateCommands).end(); ++iter) {
        (*iter)->Execute();
    }
}

class UpdateAllAppsCommand : public Command {
public:
    UpdateAllAppsCommand(Phone* phone) : _myPhone(phone) {};
    void virtual Execute() {
        _myPhone->UpdateApps();
    }
private:
    Phone* _myPhone;

};

//////////////////////////////// Main

int ChooseApp();
int ChooseClockCommand();
int ChooseMusicCommand();
int ChooseCalendarCommand();
void RunCommand(Phone* _phone, int command);

int main()
{
    engaged = true;

    Phone* phone = new Phone();
    UpdateAllAppsCommand update = UpdateAllAppsCommand(phone);

    lastTime = clock_t();

    while (engaged) {
        cout << "To exit, enter 0: \n";
        RunCommand(phone, ChooseApp());
        update.Execute();
        lastTime = clock();
    }

    cout << endl;
    return 0;
}

int ChooseApp() {
    cout << "Available Apps:\n1. Clock\n2. Calendar\n3. Music\n";
    int app = -1;

    while (app < 0 || app > 3) {
        cout << "\nWhat app would you like to open? \t";
        cin >> app;
    }

    int command = -1;

    switch (app) {
    case 1:
        command = 10;
        command += ChooseClockCommand();
        break;
    case 2:
        command = 20;
        command += ChooseCalendarCommand();
        break;
    case 3:
        command = 30;
        command += ChooseMusicCommand();
        break;
    default:
        // Exit App
        return 0;
    }

    cout << endl;

    return command;
}

int ChooseClockCommand() {
    cout << "\nWhat action in the clock app would you like to perform?\n";
    cout << "1. Set an alarm\n";
    cout << "2. End an alarm\n";
    cout << "3. Start a stopwatch\n";
    cout << "4. Lap a startwatch\n";
    cout << "5. End a stopwatch\n";
    int action = -1;

    while (action < 1 || action > 5) {
        cout << "\nSelect an action (1-5):\t";
        cin >> action;
    }

    return action;
}

int ChooseCalendarCommand() {
    int command = -1;

    return command;
}

int ChooseMusicCommand() {
    int command = -1;

    return command;
}

void RunCommand(Phone* _phone, int command) {
    int _alarm = -1;
    switch (command) {
        // Exit App
    case 0:
        cout << "Exiting the app\n";
        engaged = false;
        break;

        // Clock Commands
    case 11:
        while (_alarm < 1 || _alarm > 10) {
            cout << "\nHow many minutes will you set your alarm? (Whole number less than or equal to 10): ";
            cin >> _alarm;
        }
        _phone->SetCommand(new SetAlarmCommand(_phone->GetClock(), _alarm));
        _phone->TouchScreen();
        break;
    case 12:
        _phone->SetCommand(new EndAlarmCommand(_phone->GetClock()));
        _phone->TouchScreen();
        break;
    case 13:
        _phone->SetCommand(new StartStopwatchCommand(_phone->GetClock()));
        _phone->TouchScreen();
        break;
    case 14:
        _phone->SetCommand(new EndStopwatchCommand(_phone->GetClock()));
        _phone->TouchScreen();
        break;
    case 15:
        _phone->SetCommand(new UpdateClockCommand(_phone->GetClock()));
        _phone->TouchScreen();
        break;

        // Calendar Commands

        // Music Commands

    defaut: {
        cout << "\nInvalid Command, disengaging";
        engaged = false;
        break;
        }
    }
    cout << endl;
}
