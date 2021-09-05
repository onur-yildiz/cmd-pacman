#ifndef angry_h
#define angry_h
#include "ghost.h"

class Angry : public Ghost{
public:
	Angry(WINDOW * win, int y, int x, char _symbol, bool _hunter) : Ghost(win, y, x, _symbol, _hunter) {}
	~Angry();
	int decide(int, int, int);
	bool decideAndUpdate(int, int, int);
};

#endif
