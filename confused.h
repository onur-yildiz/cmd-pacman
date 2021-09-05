#ifndef confused_h
#define confused_h
#include "ghost.h"

class Confused : public Ghost{
public:
	Confused(WINDOW * win, int y, int x, char _symbol, bool _hunter) : Ghost(win, y, x, _symbol, _hunter) {}
	~Confused();
	bool decideAndUpdate(int, int, int);
};

#endif
