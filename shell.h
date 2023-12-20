#ifndef SHELL_H_
#define SHELL_H_
#define MAX_LENGTH 1024

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* environmental variables */
extern char **environ;
void execute_command(char *command);
void display_prompt1();
int shell5();
char command[MAX_LENGTH];

#endif /* SHELL_H_ */
