#ifndef dreamer_h
#define dreamer_h
#include "ghost.h"

class Dreamer : public Ghost{
public:
	Dreamer(WINDOW * win, int y, int x, char _symbol, bool _hunter) : Ghost(win, y, x, _symbol, _hunter) {}
	~Dreamer();
	int decide(int, int, int);
	bool decideAndUpdate(int, int, int);
};

#endif
