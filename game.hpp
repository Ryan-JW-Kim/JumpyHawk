/*
 * Description: SimpleDraw menu function header
 * Author: HBF
 * Version: 2021-08-24
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include <GL/glut.h>
#include "pipes.hpp"
#include "player.hpp"

typedef struct score {
	int currentScore;
	int currentSpeed;
} SCORE;

void iterScore(score *board);
void saveSession(score *board);
void updateBoard(score *board, pipeList *list, player *player);
void drawScore(score *board);

#endif /* GAME_HPP_ */
