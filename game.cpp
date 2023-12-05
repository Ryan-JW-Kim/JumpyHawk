/*
 * Description: implementation of menu.hpp
 * Author: HBF
 * Version: 2021-08-24
 */

#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include "game.hpp"
#include <math.h>

void saveSession(score *board) {
	/*
	 * Save the score of the current session
	 */

	std::ofstream outFile("score.txt");

	if (outFile.is_open()) {
		outFile << "Player Score: " << board->currentScore << "\n";
		outFile.close();
	}

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

			board->currentSpeed += board->increaseSpeed;
			board->increaseSpeed *= 0.5;

			std::cout << "Current Speed: " << board->currentSpeed << "\n";

			}
			currPipe = currPipe->next;
		}
	}
}
void endGame(score *board) {

	saveSession(board);

}

void drawScore(score *board) {
	/*
	 * Draw the score number for the user to see
	 */

	std::cout << "Current Score: " << board->currentScore << "\n";

}
