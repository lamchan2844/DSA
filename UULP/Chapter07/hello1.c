/* hello1.c
 *
 */
#include <stdio.h>
#include <curses.h>

void main()
{
	initscr();	//turn on curses
	clear();	//clear screen
	move(10,20);	
	addstr("Hello World");
	move(LINES-1,0);
	refresh();
	getch();
	endwin();
}
