#include "shell.h"

void jarho_print(const char *message) {
    write(STDOUT_FILENO, message, strlen(message));
}
