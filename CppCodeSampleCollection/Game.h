#include <vector>

#include "Characters.h"

using namespace std;

#ifndef GAME_H
#define GAME_H
class GenericCharacter;
class Player; 
class Enemy;

class Round;

using std::vector;

class Game {
public:
	unsigned int roundsCount;
	Round* currentRound;
	vector<Player*>* playerChars;

	Game(int code);

	~Game();

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

	~Round();

	Round& operator=(const Round& round);


	bool PlayRound(Game* _game);
	void RestartRound(Game* _game);

	void InitializeEnemies(Game* _game);
	void SetPlayOrder(Game* _game);

	void DisplayRoundStatus(Game* _game);
};

#endif