#include "shell.h"
/**
 * non_interactive - handling non-interactive mode
 * @argv: argument vector
 * @str: input
 * Return: nothing
 */
void non_interactive(char **argv, char *str)
{
	char **line_separator;
	char **command;
	int x;

	if (*str == '\n' || *str == ' ')
		str++;
	line_separator = parsing(argv, str, "\n");
	for (x = 0; line_separator[x]; x++)
	{
		command = parsing(argv, line_separator[x], " ");
		command_type(argv, command, x + 1);
	}
	__free(line_separator);
}
