#include "stats.h"

Stats::Stats(WINDOW * win, int y, int x, int _score, int _lives, int _puTime) {
	window = win;
	yLoc = y;
	xLoc = x;
	score = _score;
	lives = _lives;
	puTime = _puTime;
}

void Stats::updateScore(int _score) {
	score = _score;
}

bool Stats::updateLives(int _lives) {
	if (lives != _lives) {
		lives = _lives;
		return true;
	}
	return false;
}

bool Stats::updatePowerUp(bool huntState) {
	if (!huntState && puTime) {
		puTime--;
		return false;
	} else {
		puTime = powerUpTime;
		return true;
	}
}

void Stats::display() {
	mvwprintw(window, yLoc, xLoc, "Score: %d\tLives: %d", score, lives);
	mvwprintw(window, yLoc + 1, xLoc, "Power Time: %.0f\t", (double)(frameDelay/1000000.0 * puTime));
}
