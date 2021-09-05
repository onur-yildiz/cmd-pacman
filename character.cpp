#include "character.h"
#include <ncurses.h>

Character::Character(WINDOW * win, int y, int x, char _symbol, bool _hunter) {
	window = win;
	yLoc = ySpawnLoc = y;
	xLoc = xSpawnLoc = x;
	symbol = _symbol;
	hunter = _hunter;
	direction = KEY_DOWN;
	getmaxyx(window, yMax, xMax);
}

int Character::getX() {
	return xLoc;
}

int Character::getNextX() {
	if (direction == KEY_LEFT)
		return xLoc - 1;
	else if (direction == KEY_RIGHT)
		return xLoc + 1;
	else
		return xLoc;
}

int Character::getY() {
	return yLoc;
}

int Character::getNextY() {
	if (direction == KEY_UP)
		return yLoc - 1;
	else if (direction == KEY_DOWN)
		return yLoc + 1;
	else
		return yLoc;
}

int Character::getDirection() {
	return direction;
}

bool Character::checkCollision(int y, int x) {
	if (mvwinch(window, y, x) == wall || mvwinch(window, y, x) == symbol) {
		return true;
	}
	return false;
}

bool Character::checkEnemyCollision(char enemy, int y, int x) {
	if (mvwinch(window, yLoc, xLoc) == enemy ) {
		return true;
	} else if (mvwinch(window, y, x) == enemy ) {
		return true;
	}
	return false;
}

void Character::display() {
	mvwaddch(window, yLoc, xLoc, symbol);
}

void Character::revive() {
	mvwaddch(window, yLoc, xLoc, ' ');
	yLoc = ySpawnLoc;
	xLoc = xSpawnLoc;
}

void Character::moveUp() {
	if (!checkCollision(yLoc - 1, xLoc)) {
		mvwaddch(window, yLoc, xLoc, ' ');
		yLoc--;
	}
}

void Character::moveDown() {
	if (!checkCollision(yLoc + 1, xLoc)) {
		mvwaddch(window, yLoc, xLoc, ' ');
		yLoc++;
	}
}

void Character::moveLeft() {
	if (!checkCollision(yLoc, xLoc - 1)) {
		mvwaddch(window, yLoc, xLoc, ' ');
		if (xLoc - 1 == -1) 
			xLoc = 22;
		else
			xLoc--;
	}
}

void Character::moveRight() {
	if (!checkCollision(yLoc, xLoc + 1)) {
		mvwaddch(window, yLoc, xLoc, ' ');
		if (xLoc + 1 == 23)
				xLoc = 0;
		else
			xLoc++;
	}
}
