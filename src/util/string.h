#ifndef STRING_H
#define STRING_H

#include "types.h"

void trim_whitespace(char *str);
char **parse_string(char *str, const char *delim, u64 *tokens_count);

#endif /* STRING_H */
