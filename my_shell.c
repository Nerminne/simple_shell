#include "shell.h"
/**
 * main - simple shell implementation
 * @argv: argument vector
 * @ac: argument count
 * Return: 0 on success
 */
int main(__attribute__((unused)) int ac, char **argv)
{
	int command_line = 0;
	char *buffer = NULL;
	char **av;
	size_t n = 0;
	ssize_t get_error;

	while (1)
	{
		command_line++;
		prompt_check();
		signal(SIGINT, SIG_IGN);
		get_error = getline(&buffer, &n, stdin);
		if (get_error == -1)
			__exit(buffer);
		if (_strcmp("exit\n", buffer) == 0)
		{
			free(buffer);
			exit(0);
		}
		if (_strcmp("\n", buffer) != 0)
		{
			if (isatty(STDIN_FILENO) == 0)
				non_interactive(argv, buffer);
			else
			{
				av = parsing(argv, buffer, " \n\t");
				command_type(argv, av, command_line);
			}
		}
		free(buffer);
		buffer = NULL;
		fflush(stdin);
	}
	return (0);
}
