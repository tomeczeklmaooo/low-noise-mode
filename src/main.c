#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curses.h>

#include "util/log.h"
#include "util/types.h"
#include "game/game.h"

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

	i32 game_return_code = initialize_game();
	if (game_return_code != 0)
	{
		fprintf(stderr, "Failed to initialize the game!\n");
		exit(game_return_code);
	}

	return 0;
}
