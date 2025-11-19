#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdbool.h>

#include "../util/types.h"

struct command_t
{
	// command name, e.g. "/inv", "/stats"
	char command[16];
	// description of the command
	char description[64];
	// if false only the command is valid, e.g. "/inv" will be accepted but "/inv some params" will not
	bool accepts_params;
	callback_cmd_t function;
};

extern u64 command_count;
extern struct command_t command_list[6];

#endif /* COMMANDS_H */
