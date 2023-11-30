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

void update(player *player, GLfloat deltaTime) {
	/*
	 * Apply simple physics to the player given the time passed
	 * since the last update.
	 */
}

void jump(player *player) {
	/*
	 * Adjust the player Y-velocity to reflect a sudden increased
	 * in upward force.
	 */

}

void drawPlayer(player *player) {
	/*
	 * Draw the player sprite given its x and y position as well
	 * as the orientation (when player falling nose down)
	 */
}
