#ifndef SHELL_H
#define SHELL_H
/*
 *Include header files
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/*
 *thebse aibfbskf
 */
void display_prompt(void);
void jarho_print(const char *message);
void read_command(char *command, size_t size);
void execute_command(const char *command);

#endif /* SHELL_H */
