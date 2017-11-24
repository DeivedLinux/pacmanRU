#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include <stdbool.h>

typedef struct gameManager{
	int maxLifes;
	int life;
	int* maxScores;
	int score;
} *ptrGameManager;

bool run(void* parameters);
void lerScores(ptrGameManager gm);
void salvarScore(ptrGameManager gm);
void die(ptrGameManager gm);
void gameOver(ptrGameManager gm);

#endif