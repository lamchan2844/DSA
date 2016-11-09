/* hello4.c
 * purpose show how to use erase,time,and draw for animation
 */
#include <stdio.h>
#include <curses.h>
#include <unistd.h>
void main()
{
	int i;
	initscr();
	clear();
	for (i = 0;i<LINES;i++){
		move(i,i+1);
		if (i%2 == 1)
			standout();
		addstr("HelloWorld");
		if (i%2 == 1)
			standend();
		refresh();
		sleep(1);
		move(i,i+1);
		addstr("                ");
	}
	endwin();
}
