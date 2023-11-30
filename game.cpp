/*
 * Description: implementation of menu.hpp
 * Author: HBF
 * Version: 2021-08-24
 */

#include <GL/glut.h>
#include "game.hpp"

void iterScore(score *board) {
	/*
	 * Iterate the currentScore within the given score board object
	 */

}

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
}

void drawScore(score *board) {
	/*
	 * Draw the score number for the user to see
	 */

}
