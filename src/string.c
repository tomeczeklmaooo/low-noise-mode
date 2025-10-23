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
