#include "shell.h"
/**
 * getpath - get the executable path of command
 * @command: command written
 * @argv: argument vector
 * Return: executable path with command
 */
char *getpath(char __attribute__((unused)) **argv, char **command)
{
	char *path = _getenv("PATH"), *actual_path;
	char **parsed_path = parsing(argv, path, ":\n");
	int x, len = _strlen(command[0]);
	int path_len, access_check;

	free(path);
	for (x = 0; parsed_path[x]; x++)
	{
		path_len = _strlen(parsed_path[x]) + len + 2;
		actual_path = malloc(sizeof(char) * path_len);
		if (actual_path == NULL)
		{
			__free(parsed_path);
			return (NULL);
		}
		actual_path = _strcpy(actual_path, parsed_path[x]);
		actual_path = strcat(actual_path, "/");
		actual_path = strcat(actual_path, command[0]);
		actual_path = strcat(actual_path, "\0");
		access_check = access(actual_path, X_OK);
		if (access_check == 0)
		{
			__free(parsed_path);
			return (actual_path);
		}
		free(actual_path);
	}
	__free(parsed_path);
	return (NULL);
}
