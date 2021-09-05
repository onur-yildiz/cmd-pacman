#ifndef ghost_h
#define ghost_h
#include "character.h"

#include <cstdlib>

#define gate 'x'
#define pac '@'

class Ghost : public Character{
protected:
	int yTailLoc, xTailLoc, prevDecision;
	char tailChar;
public:
	Ghost(WINDOW * win, int y, int x, char _symbol, bool _hunter) : Character(win, y, x, _symbol, _hunter) {
		yTailLoc = y;
		xTailLoc = x;
		prevDecision = KEY_DOWN;
		tailChar = ' ';
	}
	~Ghost();
	virtual int decide(int, int, int);
	bool update(int);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	bool checkStatus();
	bool checkSpawnGate();
	int getAvailableDirection();
	void setRole(bool);
};


#endif
