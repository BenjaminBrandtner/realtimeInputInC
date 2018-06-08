/*Author: Benjamin Brandtner
 * getch mit ncurses */

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

int main (void)
{
	int zeichen;

	initscr();
	printw("Bitte ein q eingeben.\n");
	noecho();
	refresh();

	while((zeichen=getch())!='q')
	{
		printw("Sie haben %c eingegeben. Das ist nicht q.\n", zeichen);
	}

	printw("Vielen Dank\n");
	refresh();
	sleep(1);
	endwin();



	return 0;
}
