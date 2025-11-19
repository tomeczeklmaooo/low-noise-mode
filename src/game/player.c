#include <stdio.h>

#include "player.h"
#include "../util/string.h"

// === PLAYER MOVE COMMAND
i32 player_move(const char *location, const char *type)
{
	printf("MOVE: %s (%s)\n", location, type);

	// if type == fast   -> travel_time   = (base_travel_time + location_travel_time_offset) * 0.5
	//                   -> player_energy = energy_before_travel - (travel_time * energy_depletion_rate_fast)
	// if type == normal -> travel_time   = base_travel_time + location_travel_time_offset
	//                   -> player_energy = energy_before_travel - (travel_time * energy_depletion_rate_normal)
	// if type == slow   -> travel_time   = (base_travel_time + location_travel_time_offset) * 1.5
	//                   -> player_energy = energy_before_travel - (travel_time * energy_depletion_rate_slow)

	// after the type check do a check if the location exists (helper function, maybe static?)
	// if location exists change the player location after time amount in travel_time
	// who knows what else here

	return 0;
}

i32 cmd_player_move(u64 argc, char **argv)
{
	if (argc < 3)
	{
		fprintf(stderr, "/move command is missing %s\n", argc == 1 ? "2 arguments: location, type" : "1 argument: type");
		return -1;
	}

	return player_move(argv[1], argv[2]);
}

// === SHOW INVENTORY COMMAND
i32 show_inventory()
{
	printf("INVENTORY\n");

	return 0;
}

i32 cmd_show_inventory(u64 argc, char **argv)
{
	(void)argc;
	(void)argv;
	return show_inventory();
}

// === SHOW STATS COMMAND
i32 show_stats()
{
	printf("STATS\n");

	return 0;
}

i32 cmd_show_stats(u64 argc, char **argv)
{
	(void)argc;
	(void)argv;
	return show_stats();
}
