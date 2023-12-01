/*
 * Description: SimpleDraw edit function header
 * Author: HBF
 * Version: 2021-08-24
 */

#ifndef PIPES_HPP_
#define PIPES_HPP_

#include <GL/glut.h>
#include "player.hpp"

typedef struct pipe {
	GLint x, width, gapY, gapHeight;
	struct pipe *prev, *next;
	int scoreCounted;

} PIPE;

typedef struct pipeList {
	pipe *start, *end;
	int maxPipes;
	int numPipes;
} LIST;

void drawPipes(pipeList *list);
void drawPipe(pipe *currPipe);
void movePipes(pipeList *list, GLfloat gameSpeed, GLfloat deltaTime);
void trimPipeList(pipeList *list);
int createNext(pipeList *list);
int isFull(pipeList *list);

#endif /* PIPES_HPP_ */
