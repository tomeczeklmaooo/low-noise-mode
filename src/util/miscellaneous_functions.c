#include <stdio.h>

#include "miscellaneous_functions.h"

void print_commands()
{
	printf("\x1B[1mList of commands\x1B[0m\n\n");

	printf("/commands -> displays this list of commands\n");
	printf("/about    -> displays a short text about this game\n");
	printf("/exit     -> exits the game\n");
}

void print_about()
{
	printf("\x1B[1mAbout\x1B[0m\n\n");
	printf("This game is a project of mine that I intend to develop during long autumn and winter evenings.\n");
	printf("It takes a bit of inspiration from the minimalist text adventure \"A Dark Room\" (it's amazing),\n");
	printf("but here I decided on command navigation (which is an inspiration in and of itself from a little\n");
	printf("game I had to develop in PHP for programming classes). Initially it will be a pure text-only experience,\n");
	printf("but hopefully it will evolve into something quite nicer :)\n\n");
	printf("Source code is available at: https://github.com/tomeczeklmaooo/low-noise-game\n");
	printf("This project is licensed under the BSD-3-Clause License - see the LICENSE file for details.\n");
}
