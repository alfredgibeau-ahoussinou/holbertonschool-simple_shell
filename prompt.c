#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024

int main() {
    char command[MAX_LENGTH];

    while (1) {
        printf("cisfun$");
        /* Affichage du prompt */

        if (!fgets(command, MAX_LENGTH, stdin)) break;
        /* Lecture de la commande */

        /* Suppression du saut de ligne à la fin */
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) break;
        /* Commande pour quitter */
        
    /* Affiche le contenu du répertoire courant */
    printf("Contenu du répertoire courant :\n");
    system("ls");

    /* Affiche le répertoire de travail actuel */
    printf("\nRépertoire de travail actuel :\n");
    system("pwd");

    /* Affiche le contenu du répertoire courant, y compris les fichiers cachés */
    printf("\nContenu du répertoire courant (y compris les fichiers cachés) :\n");
    system("ls -a");

    }

    return 0;
}