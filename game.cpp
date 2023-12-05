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

#include <GL/glut.h>

void drawScore(int score) {
    // Convert the score to a string
    char scoreStr[12]; // Buffer to hold the score as string
    sprintf(scoreStr, "%d", score); // Convert integer to string

    // set the color for the score text to Black
    glColor3f(0.0f, 0.0f, 0.0f); // Black color

    // disable lighting and depth test to ensure the text is visible on top of everything
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);

    // set the raster position for the text to top left corner
    glRasterPos2f(20.0f, 20.0f);

    // draw each character of the score string
    for (char* p = scoreStr; *p; p++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
    }
}
