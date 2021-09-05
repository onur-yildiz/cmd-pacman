#ifndef pac_h
#define pac_h
#include <ncurses.h>
#include "character.h"

#define ghost '#'
#define powerup '$'
#define point '.'
#define death '!'

class Pac : public Character {
private:
	int lives, score;
	bool hunter;
public:
	Pac(int _lives, WINDOW * win, int y, int x, char _symbol, bool _hunter) : Character(win, y, x, _symbol, _hunter) {
		lives = _lives;
		score = 0;
	}
	~Pac();
	bool checkCollision(int, int);
	void revive();
	int updateStats();
	int getScore();
	int getLives();
	void updateLocation();
	void setRole(bool);
};



#endif
