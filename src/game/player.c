#include <stdio.h>
#include <stdarg.h>

#include "player.h"
#include "../util/string.h"

i32 player_move(/* const char *location, const char *type */)
{
	printf("MOVE\n");

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

i32 player_show_inventory(void)
{
	printf("INVENTORY\n");

	return 0;
}

i32 player_show_stats(void)
{
	printf("STATS\n");

	return 0;
}
