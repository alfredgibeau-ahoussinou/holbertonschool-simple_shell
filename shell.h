#define SHEll_H_
#ifndef SHEll_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/* environmental variables */
extern char **environ;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;
/**
 * struct arguments - Values to be accessed by various functions
 * @buf: String
 * @arr: Array of strings
 * @count: Command count
 * @status: Exit status
 * @head: Pointer to first node
 * @argv: Name of the executable
 * @ac: argument count
 * @exit_status: Exit status of the previous cmd
 * @index: Index
 */
typedef struct arguments
{
	char *buf;
	char **arr;
	int count;
	pid_t status;
	list_t *head;
	char *argv;
	int ac;
	int exit_status;
	int index;
} arguments_t;

/**
 * struct built_ins - Struct for built-ins
 * @bi: Name of built-ins
 * @f: Function pointer
 */
typedef struct built_ins
{
	char *bi;
	int (*f)(arguments_t *args);
} built_ins_t;

void display_prompt(); 
int execute_command(char *command);


#endif /*SHELL_H_*/

