#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

#include "../util/types.h"
#include "tools.h"

struct inventory_t
{
	u16 res_wood;
	u16 res_stone;
	u16 res_wool;
	u16 res_leather;
	u16 res_feather;
	u16 res_wheat;
	u16 res_iron;
	// ... other resources later

	struct tool_t tool_pickaxe;
	struct tool_t tool_axe;
	struct tool_t tool_knife;
	struct tool_t tool_bow;
	// ... other tools later
};

struct player_stats_t
{
	u8 health;
	u8 armor;
	u8 energy;
	u8 strength;
	u64 time_alive;
	u64 time_since_last_sleep;
	struct inventory_t inventory;
	bool is_scared;
};

i32 player_move(/* const char *location, const char *type */); // params commented out until I figure out callbacks with variable params
i32 player_show_inventory(void);
i32 player_show_stats(void);


#endif /* PLAYER_H */
