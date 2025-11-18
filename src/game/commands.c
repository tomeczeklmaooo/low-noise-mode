#include <stdlib.h>

#include "commands.h"
#include "player.h"
#include "../util/types.h"
#include "../util/miscellaneous_functions.h"

u64 command_count = sizeof(command_list) / sizeof(command_list[0]);

struct command_t command_list[6] = {
	{ "/inv", "shows what the player currently has in their inventory", false, &player_show_inventory },
	{ "/stats", "shows statistics about the player, as well as the savegame", false, &player_show_stats },
	{ "/move", "moves the player to a new location", true, &player_move },
	{ "/commands", "shows this help text", false, &print_commands },
	{ "/about", "shows the about text", false, &print_about },
	{ "/exit", "exits the game", false, &exit_game }
};
