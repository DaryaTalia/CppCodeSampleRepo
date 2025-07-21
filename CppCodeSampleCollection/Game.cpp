#include <iostream>
#include <algorithm>
#include <vector>
#include "Game.h"

using std::vector;

Game::Game(int code) {
	std::cout << "Debug.Log: Game::Game(" << code << "\) \n\n";	

	// Define player's characters
	StartGame();
	std::cout << "Debug.Log: Game::Game(" << ++code << "\) | StartGame() Successful \n\n";

	// Define first set of enemy characters and establish play order
	InitNewRound();
	std::cout << "Debug.Log: Game::Game(" << ++code << "\) | InitNewRound() Successful \n\n";
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
	int code = 0;

	std::cout << "Debug.Log: Game::StartGame(" << code << "\) \n\n";

	// The game will introduce itself and the winning and losing objectives.
	std::cout << "Welcome to DnD Lite!\n";
	std::cout << "This is a C++, turn-based DnD battle game.\n";
	std::cout << "You can build a team of up to 4 characters, choose their names, classes, and abilities, and battle against enemy opponents.\n";
	std::cout << "Use your abilities wisely to support your team, disadvantage the enemy, and win the round.\n\n";

	std::cout << "Let's begin.\n\n";

	playerChars = new vector<Player*>(CharacterVerification());

	std::cout << "Debug.Log: Game::StartGame(" << ++code << "\) | CharacterVerification() Successful \n\n";

	// Get Classes for each player character
	DefineCharacters();

	std::cout << "Debug.Log: Game::StartGame(" << ++code << "\) | DefineCharacters() Successful \n\n";
}

int Game::CharacterVerification() {
	int code = 0;

	std::cout << "Debug.Log: Game::CharacterVerification(" << code << "\) \n\n";

	int characterCount = 0;
	while (characterCount < 2 || characterCount > 4) {
		std::cout << "How many characters would you like to control? (2-4) \t";
		std::cin >> characterCount;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Debug.Log: Game::CharacterVerification(" << ++code << "\) | CharacterCount = " << characterCount << " \n\n";

	return characterCount;
}

void Game::DefineCharacters() {
	int code = 0;

	std::cout << "Debug.Log: Game::DefineCharacters(" << code << "\) \n\n";

	vector<Player*>::iterator thisPlayer = playerChars->begin();
	int characterIndex = 1;

	while (thisPlayer != playerChars->end()) {

		std::cout << "Debug.Log: Game::DefineCharacters(" << code << "\) | characterIndex = "<< characterIndex <<" \n\n";
		// Choose a name for this player
		string myName = "";

		std::cout << "(Character " << characterIndex << ") What is this character's name? \t";
		std::cin >> myName;
		playerChars->at(characterIndex - 1) = new Player(myName);

		// Initialize this player's Class and Abilities
		playerChars->at(characterIndex - 1)->ChooseClass();

		std::cout << "Debug.Log: Game::DefineCharacters(" << ++code << "\) | ChooseClass() Successful \n\n";

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

	// Set enemy classes and abilities
	vector<Enemy*>::iterator thisEnemy = enemyChars->begin();

	while (thisEnemy != enemyChars->end()) {
		// Set classes

		// Set abilities

		++thisEnemy;
	}

}

void Round::SetPlayOrder(Game* _game) {
	// Player Order is the size of the total number of player's and enemies in the round
	playerOrder = new vector<GenericCharacter*>();
	playerOrder->reserve(_game->playerChars->size() + enemyChars->size());

	// Insert Player Characters'
	playerOrder->insert(playerOrder->begin(), _game->playerChars->begin(), _game->playerChars->end());
	// Insert Enemt Characters'
	playerOrder->insert(playerOrder->end(), enemyChars->begin(), enemyChars->end());




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