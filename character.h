#ifndef character_h
#define character_h
#include <ncurses.h>

#define wall 'X'

class Character {
protected:
	int xLoc, yLoc, xMax, yMax, xSpawnLoc, ySpawnLoc, direction;
	WINDOW * window;
	bool hunter;
	char symbol;
public:
	Character(WINDOW*, int, int, char, bool);
	~Character() {
		delete window;
	}
	virtual bool checkCollision(int, int);
	virtual void revive();
	virtual void moveUp();
	virtual void moveDown();
	virtual void moveLeft();
	virtual void moveRight();
	virtual void display();
	
	bool checkEnemyCollision(char, int, int);
	int getX();
	int getNextX();
	int getY();
	int getNextY();
	int getDirection();
};

#endif
