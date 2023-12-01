/*
 * Description: implementation of edit.hpp
 * Author: HBF
 * Version: 2021-08-24
 */

#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include "pipes.hpp"

void drawPipes(pipeList *list) {
	/*
	 * Draw pipes from a linked list of pipes
	 */

}

void drawPipe(pipe *currPipe) {
	/*
	 * Draw individual pipe given its pointer
	 */

}

void movePipes(pipeList *list, GLint gameSpeed) {
	/*
	 * Move pipes within the linked list according to the current gameSpeed
	 * state found within the "score" struct.
	 */

}

void trimPipes(pipeList *list) {
	/*
	 * Given the linked list of pipes delete pipes which are too far
	 * left.
	 */

}

void createNext(pipeList *list, float randomSeed) {
	/*
	 * Create the next pipe given some randomSeed to generate the location
	 * of the pipe gap, check that adding new pipe will not violate
	 * maxPipes restriction, and add to pipeList at end pointer.
	 */

}

int isFull(pipeList *list) {
	/*
	 * Helper method to determine if the given pipeList is at capacity.
	 */

}
