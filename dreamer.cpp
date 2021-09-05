#include "dreamer.h"
#include <cstdlib>

int Dreamer::decide(int yPacLoc, int xPacLoc, int pacDirection) {
		if (yPacLoc <= yLoc && xPacLoc <= xLoc) { // tl
			if (checkCollision(yLoc - 1, xLoc) && checkCollision(yLoc, xLoc - 1) || !hunter)
				return getAvailableDirection();
			if (rand() % 2)
				return KEY_UP;
			return KEY_LEFT;
		}
		if (yPacLoc < yLoc && xPacLoc > xLoc) { // tr
			if (checkCollision(yLoc - 1, xLoc) && checkCollision(yLoc, xLoc + 1) || !hunter)
				return getAvailableDirection();
			if (rand() % 2)
				return KEY_UP;
			return KEY_RIGHT;
		}
		if (yPacLoc > yLoc && xPacLoc < xLoc) { // bl
			if (checkCollision(yLoc + 1, xLoc) && checkCollision(yLoc, xLoc - 1) || !hunter)
				return getAvailableDirection();
			if (rand() % 2)
				return KEY_DOWN;
			return KEY_LEFT;
		}
		if (yPacLoc >= yLoc && xPacLoc >= xLoc) { // br
			if (checkCollision(yLoc + 1, xLoc) && checkCollision(yLoc, xLoc + 1) || !hunter)
				return getAvailableDirection();
			if (rand() % 2)
				return KEY_DOWN;
			return KEY_RIGHT;
		}
}

bool Dreamer::decideAndUpdate(int yPacLoc, int xPacLoc, int pacDirection) {
	return update(decide(yPacLoc, xPacLoc, pacDirection));
}
