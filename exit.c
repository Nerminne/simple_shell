#include "shell.h"
/**
 * __exit - function handling exit
 * @nothing: input string
 * Return: nothing
 */
void __exit(char *nothing)
{
	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);
	free(nothing);
	exit(0);
}
/**
 * exit_perror - printing exit error
 * @arg: program name
 * @command_no: command number
 * @command: input command
 * Return: nothing
 */
void exit_perror(char *arg, int command_no, char **command)
{
	write(1, arg, _strlen(arg));
	write(1, ": ", 2);
	print_no(command_no);
	write(1, ": ", 2);
	write(1, command[0], _strlen(command[0]));
	write(1, ": Illegal number: ", 18);
	write(1, command[1], _strlen(command[1]));
	write(1, "\n", 1);
}
