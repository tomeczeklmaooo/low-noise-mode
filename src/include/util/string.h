#ifndef LNMG_STRING_H
#define LNMG_STRING_H

void trim_whitespace(char *str);
char **parse_string(char *str, const char *delim, size_t *tokens_count);

#endif /* LNMG_STRING_H */
