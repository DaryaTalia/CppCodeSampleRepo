// LostFortune.cpp : Adventure Game
//

#include <iostream>
#include <string>

using namespace std::cout;
using namespace std::cin;
using namespace std::endl;
using namespace std::string;

// Lost Fortune
// A personalized adventure
int main()
{
    const int GOLD_PIECES = 900;
    int adventures, killed, survivors;
    string leader;

    //get the information
    cout << "Welcome to Lost Fortune\n\n";
    cout << "Please enter the following information for your personalized adventuren\";

    cout << "Enter a number: ";
    cin >> adventures;

    cout << "Enter a number, smaller than the first: ";
    cin >> killed;

    survivors = adventurers - killed;

    cout << "Enter your last name: ";
    //cin only works with strings that have no whitespace in them
    //(such as tabs or spaces)
    cin >> leader;

    //the the story
    cout << "\nA brave group of " << adventurers << " set out on a quest ";
    cout << "- in search of the lost treasure of the Ancient Dwarves. ";
    cout << "The group was led by hat legendary rogue, " << leader << ".\n";

    cout << "\nAlong the way, a band of marauding ogres ambushed the party. ";
    cout << "All fought bravely under the command of  " << leader;
    cout << ", and the ogres were defeated, but at a cost. ";
    cout << "Of the adventurers, " << killed << " were vanquished, ";
    cout << "leaving just " << survivors << " in the group. \n ";

    cout << "\nThe party was about to give up all hope. ";
    cout << "But while laying the deceased to rest, ";
    cout << "they stumbled upon the buried fortune. ";
    cout << "So the adventurers split " << GOLD_PIECES << " gold pieces. ";
    cout << leader << " held on to the extra " << (GOLD_PIECES % survivors);
    cout << "pieces to keep things air of course.\n";

    return 0;
}
