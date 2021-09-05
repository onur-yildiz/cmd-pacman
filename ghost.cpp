#include "ghost.h"
#include <cstdlib>
#include <ncurses.h>

int Ghost::decide(int yPacLoc, int xPacLoc, int direction) {
	switch(rand() % 4) {
		case 0:
			if (prevDecision == KEY_DOWN)
				break;
			return KEY_UP;
			break;
		case 1:
			if (prevDecision == KEY_UP)
				break;
			return KEY_DOWN;
			break;
		case 2:
			if (prevDecision == KEY_RIGHT)
				break;
			return KEY_LEFT;
			break;
		case 3:
			if (prevDecision == KEY_LEFT)
				break;
			return KEY_RIGHT;
			break;
		default:
			break;
	}
}

bool Ghost::update(int newDirection) {
	int oldDirection;
	if (direction != newDirection && ((newDirection == KEY_UP && !checkSpawnGate()) || newDirection == KEY_DOWN || newDirection == KEY_LEFT || newDirection == KEY_RIGHT)) {
		oldDirection = direction;
		direction = newDirection;
		if (checkCollision(getNextY(), getNextX()))
			direction = oldDirection;
	}
	
	if(checkStatus())
		return true;
	
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
	prevDecision = direction;
	return false;
}

void Ghost::moveUp() {
	if (!checkCollision(yLoc - 1, xLoc)) {
		mvwaddch(window, yTailLoc, xTailLoc, tailChar);
		if (mvwinch(window, yLoc - 1, xLoc) != pac) {
			tailChar = mvwinch(window, yLoc - 1, xLoc);
		} else {
			tailChar = ' ';
		}
		yLoc--;
		yTailLoc = yLoc;
		xTailLoc = xLoc;
	}
}

void Ghost::moveDown() {
	if (!checkCollision(yLoc + 1, xLoc)) {
		mvwaddch(window, yTailLoc, xTailLoc, tailChar);
		if (mvwinch(window, yLoc + 1, xLoc) != pac) {
			tailChar = mvwinch(window, yLoc + 1, xLoc);
		} else {
			tailChar = ' ';
		}
		yLoc++;
		yTailLoc = yLoc;
		xTailLoc = xLoc;
	}
}

void Ghost::moveLeft() {
	if (!checkCollision(yLoc, xLoc - 1) && !(yLoc == 10 && xLoc - 1 == 4)) {
		mvwaddch(window, yTailLoc, xTailLoc, tailChar);
		if (mvwinch(window, yLoc, xLoc - 1) != pac) {
			tailChar = mvwinch(window, yLoc, xLoc - 1);
		} else {
			tailChar = ' ';
		}
		xLoc--;
		yTailLoc = yLoc;
		xTailLoc = xLoc;
	}
}

void Ghost::moveRight() {
	if (!checkCollision(yLoc, xLoc + 1) && !(yLoc == 10 && xLoc + 1 == 18)) {
		mvwaddch(window, yTailLoc, xTailLoc, tailChar);
		if (mvwinch(window, yLoc, xLoc + 1) != pac) {
			tailChar = mvwinch(window, yLoc, xLoc + 1);
		} else {
			tailChar = ' ';
		}
		xLoc++;
		yTailLoc = yLoc;
		xTailLoc = xLoc;
	}
}

bool Ghost::checkStatus() {
	if (!hunter && checkEnemyCollision(pac, getNextY(), getNextX())) {
		if (tailChar == '.')
		tailChar = ' ';
		yTailLoc = ySpawnLoc;
		xTailLoc = xSpawnLoc;
		revive();
		return true;
	}
}

bool Ghost::checkSpawnGate() {
	if (mvwinch(window, yLoc - 1, xLoc) == gate) {
		return true;
	}
	return false;
}

int Ghost::getAvailableDirection() {
	switch(rand() % 4) {
		case 0:
			return KEY_UP;
			break;
		case 1:
			return KEY_DOWN;
			break;
		case 2:
			return KEY_LEFT;
			break;
		case 3:
			return KEY_RIGHT;
			break;
		default:
			break;
	}
}

void Ghost::setRole(bool hunt) {
	hunter = hunt;
}
