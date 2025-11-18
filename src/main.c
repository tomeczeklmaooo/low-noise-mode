#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <curses.h>

#include "util/string.h"
#include "util/log.h"
#include "util/types.h"
#include "util/miscellaneous_functions.h"
#include "game/player.h"
#include "game/commands.h"

i32 main(i32 argc, char **argv)
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
	printf(" ==> You can learn more about the game by issuing \x1B[1m/about\x1B[0m\n");

	while (true)
	{
		char command_input[32];

		printf("\n>> ");
		if (fgets(command_input, sizeof(command_input), stdin) == NULL)
		{
			fprintf(stderr, "Failed to read input from stdin.\n");
		}

		trim_whitespace(command_input);

		if (command_input[0] != '/')
		{
			continue;
		}

		u64 tokens_count = 0;
		char **parsed_command = parse_string(command_input, " ", &tokens_count);

		for (u64 i = 0; i < command_count; i++)
		{
			if (strcmp(parsed_command[0], command_list[i].command) == 0)
			{
				if (command_list[i].callback != NULL)
				{
					if (!command_list[i].accepts_params && tokens_count > 1)
					{
						fprintf(stderr, "Command \"%s\" does not accept parameters.\n", command_list[i].command);
						continue;
					}

					command_list[i].callback();
				}
				else
				{
					fprintf(stderr, "Command \"%s\" does not have an assigned function.\n", command_list[i].command);
					continue;
				}
			}
		}

		free(parsed_command);
	}

	return 0;
}
