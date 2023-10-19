#include "shell.h"
/**
 * command_type - check command type
 * @argv: argument vector
 * @command: parsed input command
 * @command_line: command line number
 * Return nothing
 */
void command_type(char **argv, char **command, int command_line)
{
	if (command[0] == NULL)
	{
		__free(command);
		return;
	}
	if (builtin(argv, command, command_line) == 1)
		executing(argv, command, command_line);
}
