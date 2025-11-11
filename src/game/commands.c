#include <stdlib.h>

#include "commands.h"
#include "../util/types.h"

struct command_t command_list[6] = {
	{ "/inv", "shows what the player currently has in their inventory", false, NULL },
	{ "/stats", "shows statistics about the player, as well as the savegame", false, NULL },
	{ "/move", "moves the player to a new location", true, NULL },
	{ "/commands", "shows this help text", false, NULL },
	{ "/about", "shows the about text", false, NULL },
	{ "/exit", "exits the game", false, NULL }
};
