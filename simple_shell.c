#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * Display a prompt and wait for the user to type a command. A command line always ends with a new line. The prompt is displayed again each time a command has been executed.
 * he command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
 * The command lines are made only of one word. No arguments will be passed to programs.
 * If an executable cannot be found, print an error message and display the prompt again.
 * Handle errors.
 * You have to handle the “end of file” condition (Ctrl+D)
**/

void display_prompt() 
{
	printf("simple_shell$");
}

void run_command(char *command) 
{
	pid_t pid = fork();
	if (pid == 0) {
		char *args[1024];  /* Tableau pour stocker les arguments */
		size_t i = 0;  /* Utilisez size_t ici */

		/* Utilisation de strtok pour extraire les arguments */
		char *token = strtok(command, " \t\n");
		while (token != NULL && i < sizeof(args) / sizeof(args[0]) - 1) 
		{
			args[i++] = token;
			token = strtok(NULL, " \t\n");
		}

		args[i] = NULL;  /* Dernier élément du tableau doit être NULL */

		if (execvp(args[0], args) == -1)
		{
			perror("simple_shell");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0)
	{
		perror("simple_shell");
	} else
	{
		int status;
		waitpid(pid, &status, WUNTRACED);
	}
}

int simple() 
{
	char command[1042];
	while (1)
	{
		display_prompt();
		if (fgets(command, sizeof(command), stdin) == NULL)
		 {
			break;
		 }
		command[strcspn(command, "\n")] = '\0';
		run_command(command);
	}
	return EXIT_SUCCESS;
}
