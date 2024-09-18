#pragma once

#include <vector>
#include "Characters.h"

using std::vector;

class Round {
public:
	vector<Enemy*> enemyChars;
	vector<GenericCharacter*> playerOrder;

	Round();

	~Round();

	bool PlayRound();
	void RestartRound();

	void DisplayRoundStatus();
};

class Game {
public:
	unsigned int roundsCount;
	Round* currentRound;
	vector<Player*>* playerChars;

	Game() {
		StartGame();
		InitNewRound();
	}

	~Game() {
		delete currentRound;
	}

	void InitNewRound() {
		currentRound = new Round();
	}

	void EndGame();

private:
	void StartGame();

	int CharacterVerification();

	void DefineCharacters();
};