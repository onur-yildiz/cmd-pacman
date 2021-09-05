all: pacman

pacman: pacman.cpp
	g++ -o pacman pacman.cpp angry.cpp bored.cpp character.cpp confused.cpp dreamer.cpp ghost.cpp map.cpp pac.cpp stats.cpp -lncurses
