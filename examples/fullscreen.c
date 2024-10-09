#include "../src/cchai.h"
#include <stdio.h>
#include <threads.h>
#include <unistd.h>

int main()
{
	struct Screen screen = new_screen();
	
	start_screen(&screen);

	char text[20] = "";
	for (int i = 0; i < 5; ++i)
	{
		sprintf(text, "%d", i);

		update_screen(text, &screen);
	}

	stop_screen(&screen);
}
