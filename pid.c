#include "shell.h"

/**
 * shell1 - PID
 *
 * Return: Always 0.
 */
int shell1(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("%u\n", my_pid);
	return (0);
}
