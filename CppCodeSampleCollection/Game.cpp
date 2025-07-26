#include <iostream>
#include <algorithm>
#include <vector>
#include "Game.h"
#include <map>
#include <cstdlib>

using std::vector;
using std::map;

vector<string> names = {
"Sage",
"Eira",
"Sigurd",
"Thara",
"G'eldryn",
"Jace",
"Melody",
"Brynn",
"Dorgath",
"Fingon",
"Gojo",
"Erevan",
"Raven",
"Thranduil",
"Merlin",
"Yannick",
"Orion",
"Adelaide",
"Zoth",
"Yorik",
"Xanth",
"Morka",
};

Game::Game(int code) {
	std::cout << "Debug.Log: Game::Game(" << code << ") \n\n";	

	// Define player's characters
	StartGame();
	std::cout << "Debug.Log: Game::Game(" << ++code << ") | StartGame() Successful \n\n";

	// Define first set of enemy characters and establish play order
	InitNewRound();
	std::cout << "Debug.Log: Game::Game(" << ++code << ") | InitNewRound() Successful \n\n";

	roundsCount = 0;
}

Game::~Game() {
	*currentRound = NULL;
	delete currentRound;

	vector<Player*>::iterator playerP = playerChars->begin();
	while (playerP != playerChars->end()) {
		*playerP = NULL;
		delete* playerP;
		++playerP;
	}
	playerChars->clear();
	playerChars = NULL;
	delete playerChars;
}

void Game::StartGame() {
	// The game will introduce itself and the winning and losing objectives.
	std::cout << "Welcome to DnD Lite!\n\n";
	std::cout << "This is a C++, turn-based DnD battle game.\n";
	std::cout << "You can build a team of up to 4 characters, choose their names, classes, and abilities, and battle against enemy opponents.\n";
	std::cout << "Use your abilities wisely to support your team, disadvantage the enemy, and win the round.\n\n";

	std::cout << "Let's begin.\n\n";

	playerChars = new vector<Player*>(CharacterVerification());

	// Get Classes for each player character
	DefineCharacters();
}

int Game::CharacterVerification() {

	int characterCount = 0;
	while (characterCount < 2 || characterCount > 4) {
		std::cout << "How many characters would you like to control? (2-4) \t";
		std::cin >> characterCount;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return characterCount;
}

void Game::DefineCharacters() {
	//TODO: Add check for unique class between characters/players

	Player newPlayer = Player("");

	vector<Player*>::iterator thisPlayer = playerChars->begin();
	int characterIndex = 1;

	while (thisPlayer != playerChars->end()) {
		// Choose a name for this player
		string myName = "";

		std::cout << "(Character " << characterIndex << ") What is this character's name? \t";
		std::cin >> myName;
		playerChars->at(characterIndex - 1) = new Player(myName);

		// Initialize this player's Class and Abilities
		//newPlayer = ChooseClass();

		 playerChars->at(characterIndex - 1)->ChooseClass();

		// Determine if we've initialized enough characters to give the player feedback
		if (characterIndex == playerChars->size()) {
			std::cout << "Character Creation Complete!\n";
		}
		else {
			std::cout << "\nNext Character:\n";
		}

		std::cout << std::endl;

		++characterIndex;
		++thisPlayer;
	}

}

void Game::EndGame() {
	std::cout << "Thanks for playing!\n";
}

void Game::InitNewRound() {
	currentRound = new Round(this);
}



Round::Round(Game* _game) {
	InitializeEnemies(_game);
	SetPlayOrder(_game);
}

Round::~Round() {
	// Destruct enemies
	vector<Enemy*>::iterator enemyP = enemyChars->begin();
	while (enemyP != enemyChars->end()) {
		*enemyP = NULL;
		delete* enemyP;
		++enemyP;
	}
	enemyChars->clear();
	enemyChars = NULL;
	delete enemyChars;

	// Destruct pointers in character order
	vector<GenericCharacter*>::iterator characterP = playerOrder->begin();
	while (characterP != playerOrder->end()) {
		*characterP = NULL;
		delete* characterP;
		++characterP;
	}
	playerOrder->clear();
	playerOrder = NULL;
	delete playerOrder;
}

Round& Round::operator=(const Round& round)
{
	std::swap(*enemyChars, *round.enemyChars);
	std::swap(*playerOrder, *round.playerOrder);

	return *this;
}

void Round::InitializeEnemies(Game* _game) {
	enemyChars = new vector<Enemy*>(_game->playerChars->size());

	map<string, bool> enemyClasses;

	enemyClasses["Bard"] = false;
	enemyClasses["Cleric"] = false;
	enemyClasses["Fighter"] = false;
	enemyClasses["Ranger"] = false;
	enemyClasses["Rogue"] = false;
	enemyClasses["Wizard"] = false;

	int selection = -1;
	int randomNum;

	// Set enemy classes and abilities
	vector<Enemy*>::iterator thisEnemy = enemyChars->begin();

	while (thisEnemy != enemyChars->end()) {
		// Set Random Name
		// TODO: Set Random Name
		randomNum = rand() % names.size() + 1;
		(*thisEnemy) = new Enemy(names[randomNum]);

		// Set classes
		bool cl = false;

		while (!cl) {
			randomNum = rand() % 6;

			switch (randomNum) {
			case 0: {
				if (!enemyClasses["Bard"]) {
					(*thisEnemy)->myClass = new Bard();
					enemyClasses["Bard"] = true;
					cl = true;
				}
				break;
			}
			case 1: {
				if (!enemyClasses["Cleric"]) {
					(*thisEnemy)->myClass = new Cleric();
					enemyClasses["Cleric"] = true;
					cl = true;
				}
				break;
			}
			case 2: {
				if (!enemyClasses["Fighter"]) {
					(*thisEnemy)->myClass = new Fighter();
					enemyClasses["Fighter"] = true;
					cl = true;
				}
				break;
			}
			case 3: {
				if (!enemyClasses["Ranger"]) {
					(*thisEnemy)->myClass = new Ranger();
					enemyClasses["Ranger"] = true;
					cl = true;
				}
				break;
			}
			case 4: {
				if (!enemyClasses["Rogue"]) {
					(*thisEnemy)->myClass = new Rogue();
					enemyClasses["Rogue"] = true;
					cl = true;
				}
				break;
			}
			case 5: {
				if (!enemyClasses["Wizard"]) {
					(*thisEnemy)->myClass = new Wizard();
					enemyClasses["Wizard"] = true;
					cl = true;
				}
				break;
			}

			default: {
				break;
			}
			}
		}

		// Set abilities
		int ab1 = -1;
		int ab2 = -1;

		while (ab1 < 0) {
			randomNum = rand() % 6;

			(*thisEnemy)->myAbilities.emplace_back((*thisEnemy)->myClass->GetAbilityList()->at(ab1));
		}

		while (ab2 < 0) {
			randomNum = rand() % 6;

			if (ab2 == ab1) {
				ab2 = -1;
			}
			else {
				(*thisEnemy)->myAbilities.emplace_back((*thisEnemy)->myClass->GetAbilityList()->at(ab2));
			}
		}

		++thisEnemy;
	}

}

void Round::SetPlayOrder(Game* _game) {
	// Player Order is the size of the total number of player's and enemies in the round
	playerOrder = new vector<GenericCharacter*>();
	playerOrder->reserve(_game->playerChars->size() + enemyChars->size());

	// Insert Player Characters'
	playerOrder->insert(playerOrder->begin(), _game->playerChars->begin(), _game->playerChars->end());
	// Insert Enemy Characters'
	playerOrder->insert(playerOrder->end(), enemyChars->begin(), enemyChars->end());

	random_shuffle(playerOrder->begin(), playerOrder->end());

	DisplayRoundStatus(_game);
}

void Round::DisplayRoundStatus(Game* _game)
{
	// Round Number
	//icon Player (Class): _currHealth/_maxHealth

	vector<GenericCharacter*>::iterator players = playerOrder->begin();

	std::cout << "\nRound " << _game->roundsCount + 1 << " : \n";

	while (players != playerOrder->end()) {
		std::cout << (*players)->icon << " " << (*players)->name << " (" << (*players)->myClass << ") | Health: " << (*players)->_currHealth << "/" << (*players)->_maxHealth << "\n";

		players++;
	}

}

bool Round::PlayRound(Game* _game) {
	enemyChars->clear();

	return true;
}

void Round::RestartRound(Game* _game) {
	vector<Enemy*>::iterator thisEnemy = enemyChars->begin();
	while (thisEnemy != enemyChars->end()) {
		//enemyChars->
	}

	//vector<Player*>::iterator thisPlayer = playerChars->begin();
	//while (thisPlayer != playerChars->end()) {
		//thisEnemy->Reset();
	//}
}