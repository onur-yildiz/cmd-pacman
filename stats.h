#ifndef stats_h
#define stats_h
#include <ncurses.h>

#define frameDelay 333333
#define powerUpTime 12

class Stats {
private:
	int xLoc, yLoc, lives, score, puTime;
	WINDOW * window;
public:
	Stats(WINDOW*, int, int, int, int, int);
	~Stats() {
		delete window;
	}
	void updateScore(int);
	bool updateLives(int);
	bool updatePowerUp(bool);
	void display();
};

#endif
