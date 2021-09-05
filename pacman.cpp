#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include <time.h>

#include "pac.h"
#include "ghost.h"
#include "angry.h"
#include "dreamer.h"
#include "confused.h"
#include "bored.h"
#include "stats.h"
#include "map.h"

using namespace std;

int main(int argc, char **argv) {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	
	WINDOW *win = newwin(28, 28, 1, 1);
	nodelay(win, true);
	keypad(win, true);
	
	int pointsCollected = 0;
	bool huntState = true;
	srand(time(NULL));
	
	Pac *p = new Pac(3, win, 16, 11, pac, false);
	Stats *s = new Stats(win, 25, 1, 0, 3, 12);
	Bored *bored = new Bored(win, 10, 12, ghost, true);
	Angry *dreamer = new Angry(win, 10, 9, ghost, true);
	Angry *angry = new Angry(win, 10, 10, ghost, true);
	Confused *confused = new Confused(win, 10, 13, ghost, true);
	
	// Start screen
	refresh();
	mvwprintw(win, 11, 10, "PACMAN");
	mvwprintw(win, 13, 3, "Press a key to start");
	wrefresh(win);
	getch();
	
	// Initial display
	Map *m = new Map(win);
	p->display();
	confused->display();
	dreamer->display();
	angry->display();
	bored->display();
	wrefresh(win);
	usleep(1500000);
	
	while(1) {
		// Refresh
		flushinp();
		wrefresh(win);
		usleep(frameDelay);

		// Update and display
		if (confused->decideAndUpdate(p->getY(), p->getX(), p->getDirection()))
			pointsCollected++;
  		confused->display();
		if (dreamer->decideAndUpdate(p->getY(), p->getX(), p->getDirection()))
			pointsCollected++;
  		dreamer->display();
		if (angry->decideAndUpdate(p->getY(), p->getX(), p->getDirection()))
			pointsCollected++;
 		angry->display();
		if (bored->decideAndUpdate(p->getY(), p->getX(), p->getDirection()))
			pointsCollected++;
		bored->display();
		
		// Update lives and move all ghosts to spawn if pacman is dead
		if(s->updateLives(p->getLives())) {
			confused->revive();
			dreamer->revive();
			angry->revive();
			bored->revive();
		}
		
		// Game over screen
		if (p->getLives() == 0) {
			s->display();
			wrefresh(win);
			usleep(1000000);
			wclear(win);
			refresh();
			mvwprintw(win, 11, 10, "GAME OVER");
			wrefresh(win);
			getch();
			break;
		}
		
		// Update pacman
		s->display();
		p->updateLocation();
		switch(p->updateStats()) {
			case 0:
				pointsCollected++;
				break;
			case 1:
				huntState = false;
				p->setRole(!huntState);
				confused->setRole(huntState);
				dreamer->setRole(huntState);
				angry->setRole(huntState);
				bored->setRole(huntState);
				break;
			case 2:
				usleep(1500000);
			default:
				break;
		}
		s->updateScore(p->getScore());
		if (s->updatePowerUp(huntState)) {
			huntState = true;
			p->setRole(!huntState);
			confused->setRole(huntState); 
			dreamer->setRole(huntState);
			angry->setRole(huntState);
			bored->setRole(huntState);
		}
		p->display();
		
		// Win screen
		if (pointsCollected == 181) {
			s->display();
			wrefresh(win);
			usleep(1000000);
			wclear(win);
			refresh();
			mvwprintw(win, 11, 10, "YOU WON");
			mvwprintw(win, 13, 8, "Score: %d", p->getScore());
			wrefresh(win);
			getch();
			break;
		}
	}
	
	endwin();
	return 0;
}
