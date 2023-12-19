#ifndef SHELL_H_
#define SHELL_H_
#define MAX_LENGTH 1024
#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* environmental variables */
extern char **environ;
int execute_command(char *command);
void display_prompt1();
int shell5();
   char command[MAX_LENGTH];
/**
 * ... (le reste de votre code)
 */

#endif /* SHELL_H_ */
