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
	printf(" ==> You can learn more about the game by issuing \x1B[1m/about\x1B[0m\n\n");

	while (true)
	{
		char command_input[32];

		printf(">> ");
		if (fgets(command_input, sizeof(command_input), stdin) == NULL)
		{
			fprintf(stderr, "Failed to read input from stdin");
		}

		trim_whitespace(command_input);

		switch (command_input[0])
		{
			case '/':
			{
				u64 tokens_count = 0;
				char **parsed_command = parse_string(command_input, " ", &tokens_count);
				// PLAYER GENERAL COMMANDS
				if (strcmp(command_input, "/inv") == 0)
				{
					// show what the player has in the inventory
					
					// placeholder data
					struct inventory_t player_inv = {
						0, 1, 2, 3, 4, 5, 6,
						{ 0, "Wood pickaxe", 2, 50 },
						{ 1, "Iron axe", 30, 100 },
						{ 2, "Kitchen knife", 10, 255 },
						{ 3, "Bow", 15, 200 }
					};

					printf("Wood: %d\n", player_inv.res_wood);
					printf("Stone: %d\n", player_inv.res_stone);
					printf("Wool: %d\n", player_inv.res_wool);
					printf("Leather: %d\n", player_inv.res_leather);
					printf("Feather: %d\n", player_inv.res_feather);
					printf("Wheat: %d\n", player_inv.res_wheat);
					printf("Iron: %d\n", player_inv.res_iron);
					printf(
						"Pickaxe:\n  * type: %d\n  * name: %s\n  * damage: %d\n  * durability: %d\n",
						player_inv.tool_pickaxe.type,
						player_inv.tool_pickaxe.name,
						player_inv.tool_pickaxe.damage,
						player_inv.tool_pickaxe.durability
					);
					printf(
						"Axe:\n  * type: %d\n  * name: %s\n  * damage: %d\n  * durability: %d\n",
						player_inv.tool_axe.type,
						player_inv.tool_axe.name,
						player_inv.tool_axe.damage,
						player_inv.tool_axe.durability
					);
					printf(
						"Knife:\n  * type: %d\n  * name: %s\n  * damage: %d\n  * durability: %d\n",
						player_inv.tool_knife.type,
						player_inv.tool_knife.name,
						player_inv.tool_knife.damage,
						player_inv.tool_knife.durability
					);
					printf(
						"Bow:\n  * type: %d\n  * name: %s\n  * damage: %d\n  * durability: %d\n",
						player_inv.tool_bow.type,
						player_inv.tool_bow.name,
						player_inv.tool_bow.damage,
						player_inv.tool_bow.durability
					);
				}
				if (strcmp(command_input, "/stats") == 0)
				{
					// show all player and savegame stats
				}
				// PLAYER ACTION COMMANDS
				if (strcmp(command_input, "/move") == 0)
				{
					// params: location, type
					player_move(parsed_command[1], parsed_command[2]);
				}
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

				free(parsed_command);

				break;
			}

			default: // do nothing
				break;
		}
	}

	return 0;
}
