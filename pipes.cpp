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
			currPipe = currPipe->next;
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

void movePipes(pipeList *list, GLfloat gameSpeed, GLfloat deltaTime) {
	/*
	 * Move pipes within the linked list according to the current gameSpeed
	 * state found within the "score" struct.
	 */

	if (list->numPipes != 0) {

		pipe *currPipe = list->start;

		while (currPipe != NULL) {

			currPipe->x -= (gameSpeed * deltaTime);
			currPipe = currPipe->next;
		}
	}

}

void trimPipeList(pipeList *list) {
	/*
	 * Given the linked list of pipes delete start pipe which may be too far left.
	 */

	// Remove check
	if (list->start->x < (0 - (list->start->width * 2))) {

		pipe *temp = list->start;

		if (temp->next != NULL) { temp->next->prev = NULL; }

		list->start = temp->next;

		if (list->start == NULL) { list->end = NULL; }

		list->numPipes -= 1;

		delete temp;

	}
}

int createNext(pipeList *list) {
	/*
	 * Create the next pipe given some randomSeed to generate the location
	 * of the pipe gap, check that adding new pipe will not violate
	 * maxPipes restriction, and add to pipeList at end pointer.
	 */

	if (isFull(list)) {
		return 0;
	}

	// Define new pipe
	pipe *endPipe = list->end;
	pipe *newPipe = new pipe();
	newPipe->width =  50;
	newPipe->gapHeight = 50;
	newPipe->prev = endPipe;
	newPipe->scoreCounted = 0;

	// Randomize position of pipe gape
	int randMin = newPipe->gapHeight;
	int randMax = glutGet(GLUT_WINDOW_HEIGHT) - newPipe->gapHeight;
	int diff = randMax - randMin;
	float randomSeed = rand() % diff + 1; // Seed random 1 - 25
	newPipe->gapY = newPipe->gapHeight + randomSeed; // For window height of 600

	GLint x;
	if (list->numPipes == 0) {
		x = 250;
		list->start = newPipe;
	} else {
		x = endPipe->x + 200; // Inter-pipe padding of 200 units
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
