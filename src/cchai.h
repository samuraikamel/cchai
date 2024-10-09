#pragma once

#include <stdio.h>
struct Screen
{
	int height;
	bool is_active;
	FILE* restrict stream;
};

const struct Screen new_screen();

void update_screen(const char *string, struct Screen *screen);

void start_screen(struct Screen *screen);
void stop_screen(struct Screen *screen);
