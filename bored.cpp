#include "bored.h"
#include <math.h>
#include <ncurses.h>

int Bored::decide(int yPacLoc, int xPacLoc, int pacDirection) {
	int distance = sqrt((yPacLoc - yLoc)^2 + (xPacLoc - xLoc)^2);
	
	switch(pacDirection) {
		case KEY_UP:
			yPacLoc -= distance / 2;
			break;
		case KEY_DOWN:
			yPacLoc += distance / 2;
			break;
		case KEY_LEFT:
			xPacLoc -= distance / 2;
			break;
		case KEY_RIGHT:
			xPacLoc += distance / 2;
			break;
		default:
			break;
	}
	
	if (yPacLoc <= yLoc && xPacLoc <= xLoc) { // tl
		if (checkCollision(yLoc - 1, xLoc) || prevDecision == KEY_DOWN || !hunter)
			if (checkCollision(yLoc, xLoc - 1) || prevDecision == KEY_RIGHT || !hunter)
				if (rand() % 2)
					return KEY_RIGHT;
				else
					return KEY_DOWN;
			else
				return KEY_LEFT;
		else
			return KEY_UP;
	}
	if (yPacLoc < yLoc && xPacLoc > xLoc) { // tr
		if (checkCollision(yLoc - 1, xLoc) || prevDecision == KEY_DOWN || !hunter)
			if (checkCollision(yLoc, xLoc + 1) || prevDecision == KEY_LEFT || !hunter)
				if (rand() % 2)
					return KEY_LEFT;
				else
					return KEY_DOWN;
			else
				return KEY_RIGHT;
		else
			return KEY_UP;
	}
	if (yPacLoc > yLoc && xPacLoc < xLoc) { // bl
		if (checkCollision(yLoc + 1, xLoc) || prevDecision == KEY_UP || !hunter)
			if (checkCollision(yLoc, xLoc - 1) || prevDecision == KEY_RIGHT || !hunter)
				if (rand() % 2)
					return KEY_RIGHT;
				else
					return KEY_UP;
			else
				return KEY_LEFT;
		else
			return KEY_DOWN;
	}
	if (yPacLoc >= yLoc && xPacLoc >= xLoc) { // br
		if (checkCollision(yLoc + 1, xLoc) || prevDecision == KEY_UP || !hunter)
			if (checkCollision(yLoc, xLoc + 1) || prevDecision == KEY_LEFT || !hunter)
				if (rand() % 2)
					return KEY_LEFT;
				else
					return KEY_UP;
			else
				return KEY_RIGHT;
		else
			return KEY_DOWN;
	}
}

bool Bored::decideAndUpdate(int yPacLoc, int xPacLoc, int pacDirection) {
	return update(decide(yPacLoc, xPacLoc, pacDirection));
}
