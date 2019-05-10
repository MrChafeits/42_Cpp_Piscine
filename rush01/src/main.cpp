#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <curses.h>

void display(int argc, char* argv[]) {
	int _yMax=0,_xMax=0,ch=0;
	initscr();
	cbreak();
	// noecho();
	curs_set(0);
	getmaxyx(stdscr, _yMax, _xMax);
	keypad(stdscr, TRUE);
	if (argc > 2) {
		mvprintw(_yMax/2-1,8,"argv[0] = %s", *argv);
		mvprintw(_yMax/2,8,"argv[1] = %s", argv[1]);
	} else {
		mvprintw(_yMax/2-1,8,"argv[0] = %s", *argv);
	}
	while (true) {
		curs_set(0);
		switch (ch = getch()) {
		case 'q': case '\e': return;
		default: break;
		}
	}
}

int main(int argc, char* argv[]) {
	display(argc, argv);
	endwin();
	return 0;
}
