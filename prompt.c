#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

int main (void) {
	char command[MAX_LENGTH];

	while (1) {
		printf("cisfun$ ");

		if (!fgets(command, MAX_LENGTH, stdin)) {
			/* Lecture de la commande */
			break;
		}

		/* Supprimer le saut de ligne à la fin de la commande */
		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0) {
			/* Commande pour quitter */
			break;
		} else if (strcmp(command, "ls") == 0) {
			/* Commande ls */
			system("ls");
		} else if (strcmp(command, "pwd") == 0) {
			/* Commande pwd */
			system("pwd");
		} else if (strcmp(command, "ls -l") == 0) {
			/* Commande ls -l */
			system("ls -l");
		} else if (strcmp(command, "date") == 0) {
			/* Commande date */
			system("date");
		} else if (strcmp(command, "echo") == 0) {
			/* Commande echo */
			system("echo qwerty");
		} else {
			/* Autres commandes */
			printf("Commande non reconnue: %s\n", command);
		}
	}

	return 0;
}
