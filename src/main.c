#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <curses.h>

#include "include/util/string.h"
#include "include/util/log.h"

static void print_commands()
{
	printf("\x1B[1mList of commands\x1B[0m\n\n");
	printf("(none)\n");
}

static void print_about()
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

int main(int argc, char **argv)
{
	if (argc == 2 && strcmp(argv[1], "--ncurses") == 0)
	{
		int win_rows = 0;
		int win_cols = 0;

		if (initscr() == NULL)
		{
			fprintf(stderr, "initscr() failed\n");
			exit(1);
		}

		getmaxyx(stdscr, win_rows, win_cols);
		printw("%s (with %d args)\n[rows/y: %d | cols/x: %d]\nPress any key to quit",
			argv[0], argc, win_rows, win_cols);
		refresh();
		getch();
		endwin();
	}

	printf("%s (with %d args)\n", argv[0], argc);

	printf("Welcome to Low Noise Game! This game is currently work in progress and will certainly not look like a game for a long time.\n");
	printf(" ==> You can list all commands by issuing \x1B[1m/commands\x1B[0m\n");
	printf(" ==> You can learn more about the game by issuing \x1B[1m/about\x1B[0m\n\n");

	while (true)
	{
		char command_input[32];

		printf(">> ");
		if (fgets(command_input, sizeof(command_input), stdin) == NULL)
		{
			log_fatal("Failed to read user input from stdin");
			exit(1);
		}

		log_debug("From stdin: %s", command_input);
		trim_whitespace(command_input);

		switch (command_input[0])
		{
			case '/':
			{
				log_debug("Received command");
				// MISC COMMANDS
				if (strcmp(command_input, "/commands") == 0)
				{
					print_commands();
				}
				if (strcmp(command_input, "/about") == 0)
				{
					print_about();
				}
				break;
			}

			default:
				log_debug("Received normal text");
				break;
		}
	}

	return 0;
}
