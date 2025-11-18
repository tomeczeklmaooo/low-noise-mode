#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "miscellaneous_functions.h"
#include "types.h"
#include "../game/commands.h"

void print_title(const char *title)
{
	printf("\x1B[1m%s\x1B[0m\n\n", title);
}

i32 print_commands()
{
	print_title("List of commands");

	u64 max_length = 0;

	for (u64 i = 0; i < command_count; i++)
	{
		u64 length = strlen(command_list[i].command);
		if (length > max_length)
		{
			max_length = length;
		}
	}

	for (u64 i = 0; i < command_count; i++)
	{
		printf(
			"%-*s  : %s (%s)\n",
			(i32)max_length,
			command_list[i].command,
			command_list[i].description,
			command_list[i].accepts_params == true ? "takes parameters" : "no parameters"
		);
	}

	return 0;
}

i32 print_about()
{
	print_title("About");
	
	printf("This game is a project of mine that I intend to develop during long autumn and winter evenings.\n");
	printf("It takes a bit of inspiration from the minimalist text adventure \"A Dark Room\" (it's amazing),\n");
	printf("but here I decided on command navigation (which is an inspiration in and of itself from a little\n");
	printf("game I had to develop in PHP for programming classes). Initially it will be a pure text-only experience,\n");
	printf("but hopefully it will evolve into something quite nicer :)\n\n");
	printf("Source code is available at: https://github.com/tomeczeklmaooo/low-noise-game\n");
	printf("This project is licensed under the BSD-3-Clause License - see the LICENSE file for details.\n");

	return 0;
}

i32 exit_game()
{
	printf("Bye bye!\n");
	exit(0);
}
