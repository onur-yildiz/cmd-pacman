#ifndef bored_h
#define bored_h
#include "ghost.h"

class Bored : public Ghost{
public:
	Bored(WINDOW * win, int y, int x, char _symbol, bool _hunter) : Ghost(win, y, x, _symbol, _hunter) {}
	~Bored();
	int decide(int, int, int);
	bool decideAndUpdate(int, int, int);
};

#endif
