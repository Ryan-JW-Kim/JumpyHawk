/*
 * Description: implementation of SimpleDraw file functions
 * Author: HBF
 * Version: 2021-08-24
 */

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "player.hpp"

void updatePhysics(player *player, GLfloat deltaTime) {
	/*
	 * Apply simple physics to the player given the time passed
	 * since the last update.
	 */
    GLfloat deltaY = (player->velocity - player->gravity) * (deltaTime);

    player->y -= deltaY;

	player->velocity *= 0.9; // Velocity decay
	if (player->velocity <= 0.02) { player->velocity = 0; } // Round down

	glutPostRedisplay();

}

void jump(player *player) {
	/*
	 * Adjust the player Y-velocity to reflect a sudden increased
	 * in upward force.
	 */

	GLfloat maxVelocity = 5;

	player->velocity += player->jumpForce;

	if (player->velocity > maxVelocity) { // Max velocity
		player->velocity = maxVelocity;
	}

}

void drawPlayer(player *player) {
	/*
	 * Draw the player sprite given its x and y position as well
	 * as the orientation (when player falling nose down)
	 */


	glColor3f(0, 0, 0);
	glLineWidth(4);
	glBegin(GL_POLYGON);

		glVertex2f(player->x,       player->y);
		glVertex2f(player->x,       player->y+player->height);
		glVertex2f(player->x+player->width, player->y+player->height);
		glVertex2f(player->x+player->width, player->y);

	glEnd();

}
