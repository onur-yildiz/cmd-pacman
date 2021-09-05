#include "angry.h"

int Angry::decide(int yPacLoc, int xPacLoc, int pacDirection) {
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

bool Angry::decideAndUpdate(int yPacLoc, int xPacLoc, int pacDirection) {
	return update(decide(yPacLoc, xPacLoc, pacDirection));
}
