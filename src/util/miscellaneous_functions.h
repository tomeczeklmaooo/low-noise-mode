#ifndef MISCELLANEOUS_FUNCTIONS_H
#define MISCELLANEOUS_FUNCTIONS_H

#include "types.h"

void print_title(const char *title);

i32 print_commands();
i32 cmd_print_commands(u64 argc, char **argv);

i32 print_about();
i32 cmd_print_about(u64 argc, char **argv);

i32 exit_game();
i32 cmd_exit_game(u64 argc, char **argv);

#endif /* MISCELLANEOUS_FUNCTIONS_H */
