#include "shell.h"


void display_prompt() {
    printf("simple_shell> ");
}

void run_command(char *command) {
    pid_t pid = fork();
    if (pid == 0) {
        char *args[1024];  /* Tableau pour stocker les arguments */
        size_t i = 0;  /* Utilisez size_t ici */

        /* Utilisation de strtok pour extraire les arguments */
        char *token = strtok(command, " \t\n");
        while (token != NULL && i < sizeof(args) / sizeof(args[0]) - 1) {
            args[i++] = token;
            token = strtok(NULL, " \t\n");
        }

        args[i] = NULL;  /* Dernier élément du tableau doit être NULL */

        if (execvp(args[0], args) == -1) {
            perror("simple_shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("simple_shell");
    } else {
        int status;
        waitpid(pid, &status, WUNTRACED);
    }
}

int shell3() {
    char command[1024];
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
