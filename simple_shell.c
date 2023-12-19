#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void display_prompt() {
    printf("simple_shell> ");
}

void run_command(char *command) {
    pid_t pid = fork();
    if (pid == 0) {
        if (execl(command, command, (char *)NULL) == -1) {
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