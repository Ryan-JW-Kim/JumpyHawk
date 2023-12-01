/*
 * Description: SimpleDraw main function and mouse functions.
 * Compile: g++ -o simpledraw.exe edit.cpp file.cpp menu.cpp object.cpp simpledraw.cpp -lfreeglut -lopengl32 -lglu32
 * Run: a.exe
 * Author: HBF
 * Version: 2021-08-24
 */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include "player.hpp"
#include "pipes.hpp"
#include "game.hpp"


// global variables
// display window size
GLsizei winWidth = 800, winHeight = 600;

// object
player player = {30, 0, 1, 0, 1, 2.5};
score score = {0};
pipeList pipeList = {NULL, NULL, 15, 0};

void physicsUpdate(int value) {
	// Calculate deltaTime for physics
    static int prevTime = glutGet(GLUT_ELAPSED_TIME);
    int currentTime = glutGet(GLUT_ELAPSED_TIME);
    GLfloat deltaTime = (currentTime - prevTime);
    prevTime = currentTime;

    // Update physics using deltaTime
    update(&player, deltaTime);

    // Set up the timer callback to trigger physicsUpdate again
    glutTimerFunc(16, physicsUpdate, 1);
}

void init(void) {
	glutInitDisplayMode(GLUT_DOUBLE);  // GLUT_DOUBLE for double frame buffer
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Jumpy Hawk");
	glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, winHeight, 0.0); // set top left as origin

	// Initialize pipeList to max size
	float seed = rand() % 10 + 1;

	while (createNext(&pipeList, seed)) {
		seed = rand() % 10 + 1;
	}
}

void drawObjectList() {
	glClear(GL_COLOR_BUFFER_BIT); // Clear display window.

	// Draw objects
	drawPipes(&pipeList);
	drawPlayer(&player);
	drawScore(&score);

	glFlush();
	glutSwapBuffers();
}

static void
key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case ' ':
    	jump(&player);
    	break;
    case 'q':
    	break;
    }


    glutPostRedisplay();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	/*  Reset viewport and projection parameters  */
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble(newWidth), GLdouble(newHeight), 0.0);
	/*  Reset display-window size parameters.  */
	winWidth = newWidth;
	winHeight = newHeight;
	drawObjectList();
}

int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0); // For Eclipse stdout debugging
	setvbuf(stderr, NULL, _IONBF, 0);

	glutInit(&argc, argv);
	init();
	glutDisplayFunc(drawObjectList);
	glutReshapeFunc(winReshapeFcn);
	glutKeyboardFunc(key);
	glutTimerFunc(16, physicsUpdate, 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

