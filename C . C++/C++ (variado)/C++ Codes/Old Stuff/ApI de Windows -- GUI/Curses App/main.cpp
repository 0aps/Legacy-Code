/*
	Based on: http://www.linux.cz/noviny/1998-1112/clanek11.html
*/
#include <stdlib.h>
#include <ctype.h>
#include <curses.h>

#define COLOR1	1
#define COLOR2	2
    
int main () {
	int c;
	char *s;

	initscr ();
	cbreak ();
	noecho ();
	start_color ();
	keypad (stdscr, TRUE);
	curs_set(0);

	if (!has_colors ()) {
		endwin ();
		fputs ("No colors!", stderr); 
		exit (1);
	}

	init_pair (COLOR1, COLOR_RED, COLOR_BLUE);
	init_pair (COLOR2, COLOR_YELLOW, COLOR_BLACK);

	attron (COLOR_PAIR( COLOR1 ));
	mvaddstr (2, 5, "Red on blue.");

	attron (COLOR_PAIR( COLOR2 ));
	mvaddstr (3, 5, "Yellow on black.");

	mvaddstr (LINES-1, COLS-20, "Press F10 for end.");

	while ( (c=getch()) != KEY_F(10)) {
		s = (char *) keyname(c);
		if (s)
			mvprintw (10, 20, "'%s'", s);
		else
			mvprintw (10, 20, "'%c'", (isprint(c) ? c : '.'));
	}

	erase ();
	refresh ();
	endwin ();
	return 0;
}
