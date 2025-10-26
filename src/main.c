#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <curses.h>

#include "include/util/string.h"
#include "include/util/log.h"
#include "include/miscellaneous_functions.h"

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
				if (strcmp(command_input, "/exit") == 0)
				{
					printf("Bye bye!\n");
					exit(0);
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
