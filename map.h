#ifndef map_h
#define map_h
#include <ncurses.h>

class Map {
private:
	char map[22][24];
public:
	Map(WINDOW * win);
};

#endif

/*
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
X             XXX             X
X X XXXXX XXX XXX XXX XXXXX X X
X X            X            X X
X X XXX X XX X   X XX X XXX X X
X X     X XX XXXXX XX X     X X
X   XX XX             XX XX   X
X X XX XX X XXX XXX X XX XX X X
X X XX XX X XXX XXX X XX XX X X
X X                         X X
X X XX XXX XXXXXXXXX XXX XX X X
X   XX     XXxxxxxXX     XX   X
X X XX XXX  XXXxXXX  XXX XX X X
X X      XX         XX      X X
X X XXXX XX XXXXXXX XX XXXX X X
X X    X X           X X    X X
X   X  X   X XX XX X   X  X   X
X X X    XXX X   X XXX    X X X
X X XXXX     X X X     XXXX X X
X X      XXX   X   XXX      X X
X X XXXX XXXX XXX XXXX XXXX X X
X             XXX             X
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
X$...........XXX.............$X
X.X.XXXXX.XXX.XXX.XXX.XXXXX.X.X
X.X............X............X.X
X.X.XXX.X.XX.X...X.XX.X.XXX.X.X
X.X.....X.XX.XXXXX.XX.X.....X.X
X...XX.XX.............XX.XX...X
X.X.XX.XX.X.XXX.XXX.X.XX.XX.X.X
X.X.XX.XX.X.XXX.XXX.X.XX.XX.X.X
X.X.........................X.X
X.X.XX.XXX.XXXXXXXXX.XXX.XX.X.X
X...XX.....XX     XX.....XX...X
X.X.XX.XXX..XXXxXXX..XXX.XX.X.X
X.X......XX.........XX......X.X
X.X.XXXX.XX.XXXXXXX.XX.XXXX.X.X
X.X....X.X...........X.X....X.X
X...X..X...X.XX.XX.X...X..X...X
X.X.X....XXX.X...X.XXX....X.X.X
X.X.XXXX.....X.X.X.....XXXX.X.X
X.X......XXX...X...XXX......X.X
X.X.XXXX.XXXX.XXX.XXXX.XXXX.X.X
X$............XXX............$X
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

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
"XXXXX.X XXxxxXX X.XXXXX",
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

*/
