#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void display_prompt1() {
    printf("#cisfun$ ");
    fflush(stdout);
}

int execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        /* Child process */
        if (execlp(command, command, (char *)NULL) == -1) {
            perror("simple_shell");
            exit(1); /* Exiting with a non-zero value to indicate failure*/
        }
    } else if (pid < 0) {
        /* Forking error */
        perror("simple_shell");
    } else {
        /* Parent process */
        do {
            
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));

        return 1;
    }

    return 0;
}

int shell5() {
    char command[100]; /* Maximum command length */

    while (1) {
        display_prompt1();

        if (fgets(command, sizeof(command), stdin) == NULL) {
            /* Handle end of file (Ctrl+D) */
            printf("\nExiting shell.\n");
            break;
        }

        /* Remove newline character */
        command[strcspn(command, "\n")] = '\0';

        if (execute_command(command) == 0) {
            /* Command not found or execution failed */
            printf("./shell: No such file or directory\n");
        }
    }

    return 0;
}
