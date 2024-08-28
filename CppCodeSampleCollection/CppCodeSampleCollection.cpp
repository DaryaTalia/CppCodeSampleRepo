// CppCodeSampleCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// DnD Lite Psuedocode

int main() { 
    cout << "DnD Lite Development Begins!";

    cout << endl;

    return 0;
}

// The game will introduce itself and the winning and losing objectives.
 
// The player can enter a number between 1 and 4 for how many characters 
// they would like to create for their party.
// For each valid number, the player will be asked the following:
// "What is character (i)'s name?: "
// 
// Next, the game will print a list of available classes.
// "What is (name)'s class?: "
// 
// Next, the game will confirm the selected class's default ability.
// "(name)'s first ability as a (class) is (defaultClassAbility). Description: "
// (defaultClassAbility).description << endl
// 
// Then, the game will print a list of available abilities for that class.
// "What is (name)'s second ability? "
// "What is (name)'s third ability? "
// 
// "Character Complete! \nName: (name)\nClass: (class)\nAbilities: "
// (ability1).name - (ability1).description
// (ability2).name - (ability2).description
// (ability3).name - (ability3).description
// 
// If there is another character to be made: "Next Character:\n"
// If all characters have been made: "Character Creation Complete!"

// Round One is initializing

// The amount of player characters with a 20% change of adding 1 amount of 
// enemy characters will be made in a similar way
// For the randomly determined number of enemy characters, the computer will:
//      Randomly select a name
//      Randomly select a class
//      Randomly select two abilities

// When all characters have been made, pointers to each character, player and enemy,
// will be randomly shuffled in a list. This is their play order for the round.
// This list will be iterated through for each turn until all of one sides characters
// have 0 or less health.

// Round One is initialized

// The play order and essential details will be printed for each character:
// "(icon) name (class): currentHealth / startHealth"
// 
// Beginning with the first character in the play order list.
// "It is name's turn.\n"

// If the character is a player:
// A list of the current character's abilities will be printed alongside a number
// to choose them:
// "(itr) ability.name: ability.description"
// "(itr) ability.name: ability.description"
// "(itr) ability.name: ability.description"
// 
// "Pick an ability: "
// After a valid selection, confirm choice:
// "name will use ability.name."

// If the ability requires 1 or more targets that are not the self, the game will ask
// to select as many necessary valid targets:
// "Who will name use ability.name on? "
// 
// Folowed by a list of valid targets:
// "((iter) (icon) target.name" ++
// For each valid selection: "name chose target.name.\n"

// When all targets, if any, are selected, run the generic ActivateAbility() on each
// target.
// Each ability will print flavor text of the abilities affect per target:
// "name burns target,name like a forest fire.\n"
// 
// Each ability will print the results of its ability on the target:
// "target.name: Health decreased by value. New Health: target.currHealth"

// After all abilities are ran, the round checks to see if at least 1 character
// of both enemy and player have more than 0 health. 
// If so, the round continues.
// 
// If not, the player wins if they have at least 1 character with more than 0 health
// and all of the enemy characters have 0 health.
// The player loses if the enemy has at least 1 character with more tha 0 health
// and all of the player characters have 0 health.

// If the player wins, the game can ask if the player would like to continue
// If the player would like to continue, the player characters are restored to 
// default and the potential of their health and abilities will grow.
// Enemy characters will have an increase to their max health and
// ability strengths.
// A new round will begin initializing.

// If the player loses, the game can ask if the player would like to try again
// If the player wants to try again, the player characters are restored to default.
// The enemy characters will be restored to default.
// The round will reset using the same play order.

// If the player choose to quit the game, the game will not save any data and
// close the program.