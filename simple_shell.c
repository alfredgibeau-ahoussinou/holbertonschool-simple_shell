#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1042
#define MAX_ARGS_LENGTH 1024

void display_prompt() {
    printf("cisfun$ ");
}

void run_command(char *command) {
    pid_t pid = fork();
    if (pid == 0) {
        char *args[MAX_ARGS_LENGTH];
        size_t i = 0;

        char *token = strtok(command, " \t\n");
        while (token != NULL && i < sizeof(args) / sizeof(args[0]) - 1) {
            args[i++] = token;
            token = strtok(NULL, " \t\n");
        }

        args[i] = NULL;

        /* Fermeture des descripteurs de fichier inutilisés si nécessaire */
        /* close(fd); */

        if (execvp(args[0], args) == -1) {
            perror("simple_shell");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("simple_shell");
    } else {
        int status;
        waitpid(pid, &status, WUNTRACED);
    }
}

int shell3() {
    char command[MAX_COMMAND_LENGTH];
    while (1) {
        display_prompt();
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }
        command[strcspn(command, "\n")] = '\0';
        run_command(command);
    }
    return EXIT_SUCCESS;
}
