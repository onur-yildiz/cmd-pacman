#include "map.h"
#include <ncurses.h>

Map::Map(WINDOW * win) {
	char map[22][24] = {
"XXXXXXXXXXXXXXXXXXXXXXX",
"X..........X..........X",
"X.XXX.XXXX.X.XXXX.XXX.X",
"X$XXX.XXXX.X.XXXX.XXX$X",
"X.....................X",
"X.XXX.X.XXXXXXX.X.XXX.X",
"X.....X....X....X.....X",
"XXXXX.XXXX X XXXX.XXXXX",
"XXXXX.X         X.XXXXX",
"XXXXX.X XXXXXXX X.XXXXX",
"     .  X     X  .     ",
"XXXXX.X XxxxxxX X.XXXXX",
"XXXXX.X         X.XXXXX",
"XXXXX.X XXXXXXX X.XXXXX",
"X..........X..........X",
"X.XXX.XXXX.X.XXXX.XXX.X",
"X$..X.............X..$X",
"XXX.X.X.XXXXXXX.X.X.XXX",
"X.....X....X....X.....X",
"X.XXXXXXXX.X.XXXXXXXX.X",
"X.....................X",
"XXXXXXXXXXXXXXXXXXXXXXX"
	};
	
	for(int i = 0; i < 22; i++) {
		for(int j = 0; j < 23; j++) {
			mvwaddch(win, i, j, map[i][j]);
		}
	}
}
