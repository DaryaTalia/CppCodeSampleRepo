#include <iostream>
#include <vector>
#include "Game.h"

using std::vector;

void Game::StartGame() {
	// The game will introduce itself and the winning and losing objectives.
	std::cout << "Welcome to DnD Lite!\n";
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
	while (characterCount < 2 && characterCount > 4) {
		std::cout << "How many characters would you like to control? (2-4) \t";
		std::cin >> characterCount;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return characterCount;
}

void Game::DefineCharacters() {
	vector<Player*>::iterator thisPlayer = playerChars->begin();
	int playerIndex = 1;

	while (thisPlayer != playerChars->end()) {
		// Choose a name for this player
		string myName = "";

		std::cout << "(Player " << playerIndex << ") What is this player's name? \t";
		std::cin >> myName;
		playerChars->at(playerIndex - 1) = new Player(myName);

		// Initialize this player's Class and Abilities
		playerChars->at(playerIndex - 1)->ChooseClass();

		// Determine if we've initialized enough characters to give the player feedback
		if (playerIndex + 1 > playerChars->size()) {
			std::cout << "Character Creation Complete!\n";
		}
		else {
			std::cout << "Next Character:\n";
		}

		std::cout << std::endl;

		++playerIndex;
		++thisPlayer;
	}
}

void Game::EndGame() {
	std::cout << "Thanks \n";

}

Round::Round() {

}