#pragma once

#include <vector>

using std::vector;

class Round {
public:
	vector<Player*> playerChars;
	vector<Enemy*> enemyChars;
	vector<GenericCharacter*> playerOrder;

	Round() {}

	~Round() {}

	void PlayRound() {}
	void RestartRound() {}

	void DisplayRoundStatus() {}
};

class Game {
public:
	unsigned int roundsCount;
	Round* currentRound;

	Game() {
		currentRound = new Round();
	}

	~Game() {
		delete currentRound;
	}

	void InitNewRound() {
		currentRound = new Round();
	}
	void EndGame() {}
};