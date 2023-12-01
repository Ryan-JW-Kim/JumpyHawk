/*
 * Description: implementation of edit.hpp
 * Author: HBF
 * Version: 2021-08-24
 */

#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include "pipes.hpp"

void drawPipes(pipeList *list) {
	/*
	 * Draw pipes from a linked list of pipes
	 */

	if (list->numPipes != 0) {

		pipe *currPipe = list->start;

		while (currPipe != NULL) {

			drawPipe(currPipe);
			std::cout << "Drawing" << "\n";
			currPipe = currPipe->prev;
		}
	}
}

void drawPipe(pipe *currPipe) {
	/*
	 * Draw individual pipe given its pointer
	 */

	// Draw top rectangle
	glColor3f(0, 0, 0);
	glLineWidth(4);
	glBegin(GL_POLYGON);
		glVertex2f(currPipe->x, currPipe->gapY);
		glVertex2f(currPipe->x, -10);
		glVertex2f(currPipe->x+currPipe->width, -10);
		glVertex2f(currPipe->x+currPipe->width, currPipe->gapY);
	glEnd();

	// Draw bottom rectangle
	glBegin(GL_POLYGON);
		glVertex2f(currPipe->x, currPipe->gapY+currPipe->gapHeight);
		glVertex2f(currPipe->x+currPipe->width, currPipe->gapY+currPipe->gapHeight);
		glVertex2f(currPipe->x+currPipe->width, 1000);
		glVertex2f(currPipe->x, 1000);
	glEnd();


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

int createNext(pipeList *list, float randomSeed) {
	/*
	 * Create the next pipe given some randomSeed to generate the location
	 * of the pipe gap, check that adding new pipe will not violate
	 * maxPipes restriction, and add to pipeList at end pointer.
	 */

	if (isFull(list)) {
		return 0;
	}
	GLint padding = 30;
	GLint x, width, gapY, gapHeight;
	pipe *endPipe = list->end;

	pipe *newPipe = new pipe();

	newPipe->width =  20;
	newPipe->gapY = 400;
	newPipe->gapHeight = 30;
	newPipe->onScreen = 0;
	newPipe->prev = endPipe;
	newPipe->scoreCounted = 0;

	if (list->numPipes == 0) {
		x = 50;
		list->start = newPipe;
	} else {
		x = endPipe->x + padding;
		endPipe->next = newPipe;
	}

	newPipe->x = x;

	list->end = newPipe;
	list->numPipes += 1;

	return 1;

}

int isFull(pipeList *list) {
	/*
	 * Helper method to determine if the given pipeList is at capacity.
	 */

	if (list->numPipes >= list->maxPipes) {
		return 1;
	}

	return 0;
}
