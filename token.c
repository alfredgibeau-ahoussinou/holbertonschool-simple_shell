#include <stdio.h>
#include <string.h>
#include "shell.h"

int main7() {
    char input[100];
    char *token;  /* Déplacez la déclaration ici */

    printf("Entrez une série d'arguments : ls, ls -a, cd, pwd ");
    fgets(input, sizeof(input), stdin);

    /* Utilisation de strtok pour diviser la chaîne en "tokens" */
    token = strtok(input, " \t\n"); /* Délimiteurs : espace, tabulation, saut de ligne */

    /* Parcourir tous les "tokens" */
    while (token != NULL) {
        printf("Token : %s\n", token);
        token = strtok(NULL, " \t\n");
    }

    return 0;
}
