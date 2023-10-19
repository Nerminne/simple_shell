#include "shell.h"
/**
 * executing - execution of command
 * @argv: argument vector
 * @command: input from terminal
 * @command_line: number of command
 * Return: exit status of execve
 */
void executing(char **argv, char **command, int command_line)
{
	int exe_check;
	char *actual_command = NULL;

	exe_check = access(command[0], X_OK);
	if (exe_check == 0)
		child_idc(command, actual_command);
	else
	{
		actual_command = getpath(argv, command);
		if (actual_command)
			child_idc(command, actual_command);
		else
		{
			_perror(argv[0], command_line, command[0]);
			__free(command);
		}
	}
}
/**
 * child_idc - execution of command
 * @command: input from terminal
 * @actual_command: executable path of command
 * Return: Nothing
 */
void child_idc(char **command, char *actual_command)
{
	int status;
	pid_t child = fork();

	if (child == 0)
	{
		if (actual_command)
		{
			if (execve(actual_command, command, environ) == -1)
			{
				perror("execve error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (execve(command[0], command, environ) == -1)
			{
				perror("execve error");
				exit(EXIT_FAILURE);
			}
		}
	}
	else if (child < 0)
	{
		perror("forking error");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (actual_command)
			free(actual_command);
		__free(command);
		wait(&status);
	}
}
