#include "shell.h"

#define MAX_LENGTH 1024

int main() {
    char command[MAX_LENGTH];

    while (1) {
        printf("cisfun$ ");
        /* Affichage du prompt */

        if (!fgets(command, MAX_LENGTH, stdin)) {
            /* Lecture de la commande */
            break;
        }

        if (strcmp(command, "exit") == 0) {
            /* Commande pour quitter */
            break;
        }
    }

    return 0;
}