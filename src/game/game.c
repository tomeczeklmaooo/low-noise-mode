#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "game.h"
#include "commands.h"
#include "../util/types.h"
#include "../util/string.h"

void input_loop()
{
	while (true)
	{
		char command_input[32];

		printf("\n>> ");
		if (fgets(command_input, sizeof(command_input), stdin) == NULL)
		{
			fprintf(stderr, "Failed to read input from stdin.\n");
		}

		trim_whitespace(command_input);

		if (command_input[0] != '/') // game commands start with '/'
		{
			continue;
		}

		u64 tokens_count = 0;
		char **parsed_command = parse_string(command_input, " ", &tokens_count);

		for (u64 i = 0; i < command_count; i++)
		{
			if (strcmp(parsed_command[0], command_list[i].command) != 0) // command was not matched
			{
				continue;
			}

			if (command_list[i].function == NULL)
			{
				fprintf(stderr, "Command \"%s\" does not have an assigned function.\n", command_list[i].command);
				continue;
			}

			if (!command_list[i].accepts_params && tokens_count > 1)
			{
				fprintf(stderr, "Command \"%s\" does not accept parameters.\n", command_list[i].command);
				continue;
			}

			command_list[i].function(tokens_count, parsed_command);
		}

		free(parsed_command);
	}
}

i32 initialize_game()
{
	printf("Welcome to Low Noise Game! This game is currently work in progress and will certainly not look like a game for a long time.\n");
	printf(" ==> You can list all commands by issuing \x1B[1m/commands\x1B[0m\n");
	printf(" ==> You can learn more about the game by issuing \x1B[1m/about\x1B[0m\n");

	input_loop();

	return 0;
}
