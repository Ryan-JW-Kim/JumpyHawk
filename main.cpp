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
player player = {10, 50, 0, 0, 1, 3};
score score = {0};
pipeList pipeList = {NULL, NULL, 15, 0};

//time_t now = time(nullptr);

void init(void) {
	glutInitDisplayMode(GLUT_DOUBLE);  // GLUT_DOUBLE for double frame buffer
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Jumpy Hawk");
	glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, winHeight, 0.0); // set top left as origin

	// Initialize pipeList to max size
	while (!isFull(&pipeList)) {
		float seed = rand() % 10 + 1;
		createNext(&pipeList, seed);
	}

}

void drawObjectList() {
	glClear(GL_COLOR_BUFFER_BIT); // Clear display window.

	// Calculate deltaTime for physics
	GLfloat deltaTime = 1/60; // Default to 60 updatees per second
//	now = time(nullptr);

	update(&player, deltaTime);

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
    case 1:
    	jump(&player);
    	break;
    case 2:
    	// QUIT GAME
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
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

