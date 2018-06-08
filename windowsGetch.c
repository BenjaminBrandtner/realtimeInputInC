/*Author: Benjamin Brandtner
 * getch() auf Windows */

#include <stdio.h>

int main (void)
{
	char button;

	printf("Please press q.");

	while ((button = getch())!= 'q')
	{
		
		printf("You pressed %c, but you need to press q!\n", button);
	}

	printf("Thank you!");

	return 0;
}
