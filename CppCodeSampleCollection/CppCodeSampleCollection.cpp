// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CppCodeSampleCollection.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    LostFortune();

    return 0;
}

// Lost Fortune
// A personalized adventure

void LostFortune() {
    const int SKELETONS = 7;
    int coffin_gold, reward_gold, miles;
    string civilian_lady, paladin, rogue, sorcerer, bard;

    char proceed;

    //get the information
    cout << "Welcome to Lost Fortune, 2.0\n\n";
    cout << "Please enter the following information for your personalized adventure\n";

        cout << "Enter a number: ";
    cin >> coffin_gold;

    cout << "Enter another number: ";
    cin >> reward_gold;

    cout << "Enter another number: ";
    cin >> miles;

    cout << "Enter a lady's name: ";
    cin >> civilian_lady;

    cout << "Enter a bard's name: ";
    cin >> bard;

    cout << "Enter a paladin's name: ";
    cin >> paladin;

    cout << "Enter a rogue's name: ";
    cin >> rogue;

    cout << "Enter a sorcerer's name: ";
    cin >> sorcerer;

    //tell the story
    cout << "\nA ragtag group of adventurers travel the coast. ";
    cout << "The group met " << civilian_lady << " in town, who is distraught after her mother went missing some weeks ago. ";
    cout << "The group agreed to help her find clues.\n";

    cout << "\nEnter any key to continue: ";
    cin >> proceed;

    cout << "\nThis quest led them to the coast. ";
    cout << rogue << ", the rogue, learned that a shipwreck washed up " << miles;
    cout << " miles from the town. Their paladin leader, " << paladin << ", leads the way down the beach. When they can see the wreckage, ";
    cout << sorcerer << ", the sorcerer detects something unusual about the sand. They caution the group to move slowly, but " << bard << ", the bard, skips ahead unaware. ";

    cout << "\nEnter any key to continue: ";
    cin >> proceed;

    cout << "\nSuddenly, skeletons burst from the sand! The group is surrounded by " << SKELETONS << " skeletons. They fight past the skeletons into the ship. ";
    cout << rogue << " and " << bard << " check the lower quarters while " << sorcerer << " and " << paladin << " check the upper quarters.";

    cout << "\nEnter any key to continue: ";
    cin >> proceed;

    cout << "\nIn the upper quarters, " << sorcerer << " uses a detection spell to find anything valuable in the debris. ";
    cout << "They point out something shiny to " << paladin << ". ";
    cout << paladin << " picks up a compass. Opening it, they see a picture of " << civilian_lady << " and her mother. ";
    cout << "The two also find journals left behind by the Captain suggesting she may have been transporting something dangerous.";

    cout << "\nEnter any key to continue: ";
    cin >> proceed;

    cout << "\n\"Might explain the skeletons,\" " << sorcerer << " offers. ";
    cout << paladin << " sighs before they both hear their bard scream. They look at each other, before rushing downstairs.";

    cout << "\nEnter any key to continue: ";
    cin >> proceed;

    cout << "\nMeanwhile, " << rogue << " and " << bard << " have found dozens of coffins in the storage area. ";
    cout << "Many are already open. \"Why are these here!?\" " << bard << " shrieks. ";
    cout << "The rogue ignores them, searching the open coffins. \"Why are you doing that!?\" ";

    cout << "\nEnter any key to continue: ";
    cin >> proceed;

    cout << "\"Might find something interesting, like who these people were, or gold...\" " << rogue << " tells them. ";
    cout << bard << " grumbles to their self, \"Gold, of course it's gold...\"; ";
    cout << "they follow closely to " << rogue << " as they look.";

    cout << "\nEnter any key to continue: ";
    cin >> proceed;

    cout << "\n" + rogue << " does find gold, " << coffin_gold << " pieces, in fact. ";
    cout << "They also find strange necklaces in almost all of them, two silver eyes with a third gold eye in the middle. ";
    cout << "\"Hm...\" " << rogue << " takes a dagger and pries open a sealed coffin.";

    cout << "\nEnter any key to continue: ";
    cin >> proceed;

    cout << "\n\"No, no, no, no...\" " << bard << " whispers, backing away quickly. ";
    cout << "They stumble over an open coffin just as " << rogue << " opens the lid. ";
    cout << "There's... no one inside. A few scattered goods and coins like the other coffins, and the strange necklace, but no body. ";
    cout << rogue << " opens more coffins but they're all empty. ";
    cout << "They scratch their head and turn back to the bard, finally climbing out of the coffin.";

    cout << "\nEnter any key to continue: ";
    cin >> proceed;
            
    cout << "\"Well good thing, this place is weird enough. " << paladin <<" and " << sorcerer << " probably found what we need so let's just-\"";
    cout << " they freeze as they see " << rogue << " draw their dagger into a defensive position and ready a fire cantrip in their other palm. ";
    cout << "\"Please tell me there's not...\" An artic breeze approaches " << bard << ", and they slowly peek around to see another skeleton, larger than the ones outside. ";

    cout << "\nEnter any key to continue: ";
    cin >> proceed;

    cout << "\nOn instinct, they yell and push it back, scrambling to stand by " << rogue << ". The skeleton growls before lunging at them. "; 
    cout << "Before it can land its attack, " << paladin << " swings their sword and takes the skeleton's head off.";

    cout << "\nEnter any key to continue: ";
    cin >> proceed;
    
    cout << "\nThe group update each other and decide to return to the town to see " << civilian_lady << ". She is grateful for the return of the compass and the journals. ";
    cout << "\"For all your hardwork, please accept this gift. I'll have to ask around town about those necklaces.\" ";
    cout << civilian_lady << " hands " << paladin << " "  << reward_gold << " gold coins. They all say goodbye for the evening before heading to their next quest.";

    cout << "\nEnter any key to continue: ";
    cin >> proceed;
    
    
}
