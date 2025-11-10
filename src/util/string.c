#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "string.h"
#include "types.h"

void trim_whitespace(char *str)
{
	char *end_ptr = NULL;

	while (isspace((u8)*str)) str++;

	if (*str == 0)
	{
		*str = '\0';
		return;
	}

	end_ptr = str + strlen(str) - 1;
	while (end_ptr > str && isspace((u8)*end_ptr)) end_ptr--;

	*(end_ptr + 1) = '\0';
}

char **parse_string(char *str, const char *delim, u64 *tokens_count)
{
	char *in_str = str;
	char **parsed_str = NULL;
	char *token = strtok(in_str, delim);
	u64 token_amt = 0;
	u64 n_spaces = 0;

	while (token)
	{
		parsed_str = realloc(parsed_str, sizeof(char*) * ++n_spaces);

		if (parsed_str == NULL)
		{
			fprintf(stderr, "Failed to allocate memory for the parsed string\n");
			return NULL;
		}

		parsed_str[n_spaces - 1] = token;
		token_amt++;

		token = strtok(NULL, delim);
	}

	parsed_str = realloc(parsed_str, sizeof(char*) * (n_spaces + 1));
	parsed_str[n_spaces] = 0;

	*tokens_count = token_amt;

	return parsed_str;
}
