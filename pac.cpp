#include "pac.h"
#include <ncurses.h>
#include <unistd.h>

bool Pac::checkCollision(int y, int x) {
	if (mvwinch(window, y, x) == 'X' || mvwinch(window, y, x) == 'x') {
		return true;
	}
	return false;
}

void Pac::revive() {
	lives--;
	symbol = death;
	display();
	wrefresh(window);
	usleep(2000000);
	symbol = ' ';
	display();
	wrefresh(window);
	symbol = '@';
	
	if(lives == 0) {
		mvwaddch(window, yLoc, xLoc, death);
		xLoc = 0;
		yLoc = 0;
	} else {
		yLoc = ySpawnLoc;
		xLoc = xSpawnLoc;
	}
}

int Pac::updateStats() {
	if (mvwinch(window, yLoc, xLoc) == point) {
		score += 10;
		return 0;
	}
	if (mvwinch(window, yLoc, xLoc) == powerup) {
		score += 100;
		hunter = true;
		return 1;
	}
	if (checkEnemyCollision(ghost, getNextY(), getNextX())) {
		if (hunter) {
			score += 200;
			return 2;
		} else 
			revive();
	}
	return -1;
}

int Pac::getScore() {
	return score;
}

int Pac::getLives() {
	return lives;
}

void Pac::updateLocation() {
	int newDirection = wgetch(window);
	int oldDirection;
	if (direction != newDirection && (newDirection == KEY_UP || newDirection == KEY_DOWN || newDirection == KEY_LEFT || newDirection == KEY_RIGHT)) {
		oldDirection = direction;
		direction = newDirection;
		if (checkCollision(getNextY(), getNextX()))
			direction = oldDirection;
	}
	
	switch(direction) {
		case KEY_UP:
			moveUp();
			break;
		case KEY_DOWN:
			moveDown();
			break;
		case KEY_LEFT:
			moveLeft();
			break;
		case KEY_RIGHT:
			moveRight();
			break;
		default:
			break;
	}
}

void Pac::setRole(bool hunt) {
	hunter = hunt;
}
