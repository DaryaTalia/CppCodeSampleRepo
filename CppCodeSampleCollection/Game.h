#pragma once

#include <vector>
#include "Characters.h"

using std::vector;

class Game {
public:
	unsigned int roundsCount;
	Round* currentRound;
	vector<Player*>* playerChars;

	Game() {
		// Define player's characters
		StartGame();
		// Define first set of enemy characters and establish play order
		InitNewRound();
	}

	~Game() {
		*currentRound = NULL;
		delete currentRound;

		vector<Player*>::iterator playerP = playerChars->begin();
		while (playerP != playerChars->end()) {
			*playerP = NULL;
			delete *playerP;
			++playerP;
		}
		playerChars->clear();
		playerChars = NULL;
		delete playerChars;
	}

	void InitNewRound();

	void EndGame();

private:
	void StartGame();

	int CharacterVerification();

	void DefineCharacters();
};


class Round {
public:
	vector<Enemy*>* enemyChars;
	vector<GenericCharacter*>* playerOrder;

	Round(Game* _game);

	~Round() {
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

	bool PlayRound(Game* _game);
	void RestartRound(Game* _game);

	void InitializeEnemies(Game* _game);
	void SetPlayOrder(Game* _game);

	void DisplayRoundStatus();
};