#include "shell.h"
/**
 * _getenv - find enviroment variable value
 * @env_var: enviroment variable
 * Return: value of enviroment variable
 */
char *_getenv(char *env_var)
{
	int x, y, i, len = 1;
	char *value;

	for (x = 0; environ[x]; x++)
	{
		for (y = 0; y < _strlen(env_var); y++)
		{
			if (environ[x][y] != env_var[y])
				break;
		}
		if (y == _strlen(env_var) && environ[x][y] == '=')
		{
			y++;
			i = y;
			for (; environ[x][y]; y++)
				len++;

			value = malloc(sizeof(char) * len);
			if (value == NULL)
				return (NULL);

			for (y = 0; environ[x][i]; y++, i++)
				value[y] = environ[x][i];
			value[y] = '\0';

			return (value);
		}
	}
	return (NULL);
}
