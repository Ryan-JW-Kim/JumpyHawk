/*
 * Description: implementation of menu.hpp
 * Author: HBF
 * Version: 2021-08-24
 */

#include <GL/glut.h>
#include <iostream>
#include "game.hpp"

void saveSession(score *board) {
	/*
	 * Save the score of the current session
	 */

}

void updateBoard(score *board, pipeList *list, player *player) {
	/*
	 * Update the current score given the list of pipes and the
	 * player struct. Ensure that pipes are not double counted using
	 * the "scoreCounted" as a boolean to indicate that the given pipe has
	 * already contributed to the score.
	 */

	if (list->numPipes != 0) {

		pipe *currPipe = list->start;

		while (currPipe != NULL) {

			if (currPipe->x < player->x && !currPipe->scoreCounted) {
			board->currentScore += 1;
			currPipe->scoreCounted = 1;

			}
			currPipe = currPipe->next;
		}
	}
}

void drawScore(score *board) {
	/*
	 * Draw the score number for the user to see
	 */

	std::cout << "Current Score: " << board->currentScore << "\n";

}
