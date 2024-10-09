#include "cchai.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>


const struct Screen new_screen()
{
	const struct Screen screen = 
	{
		.is_active = false, .height = 0, .stream = stdout
	};
	return screen;
}

int count_character(const char *string)
{
	int count = 0;

	for (int i = 0, string_length = strlen(string); i < string_length; ++i)
	{
		if (string[i] == '\n') { ++count; }
	}

	return count;
}

void clear_screen(const struct Screen *screen)
{
	if (screen->height > 0)
	{
		// Yep.
	}
	fputs("\x1b[2K", screen->stream);
}

void write_screen(const char * string, const struct Screen *screen)
{
	fputs(string, screen->stream);
}

void update_screen(const char *string, struct Screen *screen)
{
	write_screen(string, screen);

	screen->height = count_character(string);
}

void start_screen(struct Screen *screen)
{
	screen->is_active = true;

	update_screen("", screen);
}

void stop_screen(struct Screen *screen)
{
	assert(screen->is_active && "stop_screen being called on inactive screen.");

	screen->is_active = false;
}

