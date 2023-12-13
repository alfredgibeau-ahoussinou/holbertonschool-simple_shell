#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

int main() {
    char command[MAX_LENGTH];

    while (1) {
        printf("ShellPrompt > ");
        /* Affichage du prompt */

        if (!fgets(command, MAX_LENGTH, stdin)) break;
        /* Lecture de la commande */

        /* Suppression du saut de ligne à la fin */
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) break;
        /* Commande pour quitter */

        system(command);
        /* Exécution de la commande */
    }

    return 0;
}
