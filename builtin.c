#include "shell.h"
/**
 * builtin - handeling builtin commands
 * @argv: argument vector
 * @com: input command
 * @line_no: line number of command
 * Return: 0 if builtin 1 if not
 */
int builtin(char **argv, char **com, int line_no)
{
	int x, y, exit_status;

	if ((_strcmp(com[0], "exit") == 0) && (com[1] != NULL))
	{
		exit_status = _atoi(com[1]);
		if (exit_status == -1)
		{
			exit_perror(argv[0], line_no, com);
			__free(com);
			return (0);
		}
		else
		{
			__free(com);
			exit(exit_status);
		}
	}
	if ((_strcmp(com[0], "env") == 0) && (com[1] == NULL))
	{
		for (x = 0; environ[x]; x++)
		{
			for (y = 0; environ[x][y]; y++)
			{
				write(1, &environ[x][y], 1);
			}
				write(1, "\n", 1);
		}
		__free(com);
		return (0);
	}
	else if ((_strcmp(com[0], "env") == 0) && (com[1] != NULL))
	{
		_perror(argv[0], line_no, com[0]);
		__free(com);
		return (0);
	}
	return (1);
}

/**
 * _perror - handling error
 * @arg: program name
 * @command_no: command number
 * @command: input command
 * Return: nothing
 */
void _perror(char *arg, int command_no, char *command)
{
	write(1, arg, _strlen(arg));
	write(1, ": ", 2);
	print_no(command_no);
	write(1, ": ", 2);
	write(1, command, _strlen(command));
	write(1, ": not found", 11);
	write(1, "\n", 1);
}
/**
 * print_no - print integer
 * @num: number to be printed
 * Return: nothing
 */
void print_no(int num)
{
	if ((num / 10) > 0)
		print_no(num / 10);
	print_c((num % 10) + '0');
}
/**
 * print_c - print character
 * @d: character
 * Return: 1 on success
 */
int print_c(char d)
{
	return (write(1, &d, 1));
}
/**
 * _atoi - function that convert char to int
 * @string: string to be converted
 * Return: integer
 */
int _atoi(char *string)
{
	int num = 0;

	for (; *string; string++)
	{
		if (*string == '-')
			return (-1);

		if (*string >= '0' && *string <= '9')
			num = num * 10 + (*string - '0');
		else if (*string < '0' || *string > '9')
			return (-1);

	}
	return (num);
}
