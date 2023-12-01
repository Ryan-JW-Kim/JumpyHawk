/*
 * Description: SimpleDraw file operation function header
 * Author: HBF
 * Version: 2021-08-24
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <GL/glut.h>

typedef struct player {
	GLint x, y, width, height;
	GLfloat orientation, velocity, gravity, jumpForce;
} PLAYER;

void updatePhysics(player *player, GLfloat deltaTime);
void jump(player *player);
void drawPlayer(player *player);


#endif /* PLAYER_HPP_ */
