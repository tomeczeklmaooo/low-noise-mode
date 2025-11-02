#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "include/util/string.h"

void trim_whitespace(char *str)
{
	char *end_ptr = NULL;

	while (isspace((unsigned char)*str)) str++;

	if (*str == 0)
	{
		*str = '\0';
		return;
	}

	end_ptr = str + strlen(str) - 1;
	while (end_ptr > str && isspace((unsigned char)*end_ptr)) end_ptr--;

	*(end_ptr + 1) = '\0';
}

char **parse_string(char *str, const char *delim, size_t *tokens_count)
{
	char *in_str = str;
	char **parsed_str = NULL;
	char *token = strtok(in_str, delim);
	size_t token_amt = 0;
	size_t n_spaces = 0;

	while (token)
	{
		parsed_str = realloc(parsed_str, sizeof(char*) * ++n_spaces);

		if (parsed_str == NULL)
		{
			exit(-1);
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
