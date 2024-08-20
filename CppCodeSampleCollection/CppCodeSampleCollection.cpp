//

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Mad-Lib 2.0

string askText(string prompt);
int askNumber(string prompt);
void tellStory(string& name, string& noun, int& number, string& bodyPart, string& verb);

int main() {
    cout << "Welcome to Mad Lib.\n\n";
    cout << "Answer the following questions to help create a new story.\n";

    string name = askText("Please enter a name: ");
    string noun = askText("Please enter a plural noun: ");
    int number = askNumber("Please enter a number, greater than 4: ");
    string bodyPart = askText("Please enter a body part: ");
    string verb = askText("Please enter a verb: ");

    tellStory(name, noun, number, bodyPart, verb);

    cout << endl;

    return 0;
}

string askText(string prompt) {
    string text;
    cout << prompt;
    cin >> text;
    return text;
}

int askNumber(string prompt) {
    int num = 0;
    while (num < 5) {
        cout << prompt;
        cin >> num;
    }
    return num;
}

void tellStory(string& name, string& noun, int& number, string& bodyPart, string& verb) {
    cout << "\nHere's your story:\n";

    cout << name;
    cout << " was exploring the dense forests of Avalon when they suddenly found ";
    cout << number;
    cout << " golden " << noun << ". ";
    cout << name;
    cout << " buried 1 and felt richer. They crushed 1 and felt stronger. When they ";
    cout << verb << " another, their ";
    cout << bodyPart << " disappeared! ";
    cout << name;
    cout << " screamed, abandoning the remaining " << (number - 3) << " " << noun << " and leaving the forest.\n\n";
}