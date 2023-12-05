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
     * Draw the player sprite as a bird with a square body, a yellow beak,
     * and an eye, given its x and y position.
     */

    // Draw body (Purple square)
    glColor3f(0.5, 0, 0.5); // RGB for purple
    glBegin(GL_QUADS); // Using GL_QUADS for a square
        glVertex2f(player->x, player->y);
        glVertex2f(player->x + player->width, player->y);
        glVertex2f(player->x + player->width, player->y + player->height);
        glVertex2f(player->x, player->y + player->height);
    glEnd();

    // Draw beak (Yellow triangle)
    glColor3f(1, 1, 0); // RGB for yellow
    glBegin(GL_TRIANGLES);
        glVertex2f(player->x + player->width, player->y); // Bottom right of the square
        glVertex2f(player->x + player->width, player->y + player->height); // Top right of the square
        glVertex2f(player->x + player->width + player->height, player->y + player->height / 2); // Point of the beak
    glEnd();

    // Draw eye (White circle)
    int num_segments = 20; // Number of segments used to approximate the circle
    float eye_radius = player->height / 10; // Eye radius
    float eye_center_x = player->x + 3 * player->width / 4; // X coordinate of eye center
    float eye_center_y = player->y + 1 * player->height / 2; // Y coordinate of eye center

    glColor3f(0, 0, 0); // RGB for black
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // Current angle
        float x = eye_radius * cosf(theta); // Calculate the x component
        float y = eye_radius * sinf(theta); // Calculate the y component
        glVertex2f(x + eye_center_x, y + eye_center_y); // Output vertex
    }
    glEnd();
}
