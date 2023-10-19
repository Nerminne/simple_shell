#include "shell.h"
/**
 * parsing - handling parsing string
 * @argv: argument vector
 * @str: string to be parsed
 * @delim: delimeter
 * Return: parsed string
 */

char **parsing(char **argv, char *str, const char *delim)
{
	char **parsed_str;
	char *str_cpy, *token;
	int x, toknum;
	(void)argv;

	str_cpy = _strdup(str);
	if (str_cpy == NULL)
		return (NULL);
	token = strtok(str, delim);
	for (toknum = 0; token; toknum++)
		token = strtok(NULL, delim);

	parsed_str = malloc((sizeof(char *)) * (toknum + 1));
	if (parsed_str == NULL)
		return (NULL);

	token = strtok(str_cpy, delim);
	for (x = 0; token; x++)
	{
		parsed_str[x] = _strdup(token);
		token = strtok(NULL, delim);
	}
	parsed_str[x] = NULL;
	free(str_cpy);

	return (parsed_str);
}
