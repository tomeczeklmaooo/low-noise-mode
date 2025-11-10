#ifndef TOOLS_H
#define TOOLS_H

#include "../util/types.h"

struct tool_t
{
	u8 type;
	char name[32];
	u8 damage;
	u8 durability;
};

#endif /* TOOLS_H */
