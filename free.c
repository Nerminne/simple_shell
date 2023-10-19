#include "shell.h"
/**
 * __free - free array of string
 * @command: array of string
 * Return: nothing
 */
void __free(char **command)
{
	int i;

	for (i = 0; command[i]; i++)
		free(command[i]);
	free(command);
}
