#include "shell.h"
/**
 * _strlen - function count string length
 * @str: string
 * Return: length of string
 */
int _strlen(char *str)
{
	int x = 0;

	while (str[x])
		x++;
	return (x);
}
/**
 * _strdup - function that duplicate string
 * @str: string
 * Return: duplicated string
 */
char *_strdup(char *str)
{
	int length = _strlen(str) + 1;
	char *str_dup;
	int x;

	if (str == NULL)
		return (NULL);
	str_dup = malloc(sizeof(char) * length);
	if (str_dup == NULL)
		return (NULL);

	for (x = 0; str[x]; x++)
		str_dup[x] = str[x];
	str_dup[x] = '\0';

	return (str_dup);
}
/**
 * _strcmp - compare between str 1 and str 2
 * @first_str: first string
 * @second_str: second string
 * Return: 0 if strings are equivalent -1 if not
 */
int _strcmp(char *first_str, char *second_str)
{
	int x;

	if (_strlen(first_str) != _strlen(second_str))
		return (-1);

	for (x = 0; first_str[x]; x++)
	{
		if (first_str[x] != second_str[x])
			return (-1);
	}
	return (0);
}
/**
 * _strcpy - copy str 2 to str 1
 * @first_str: first string
 * @second_str: second string
 * Return: copied string
 */
char *_strcpy(char *first_str, char *second_str)
{
	int x;

	for (x = 0; ; x++)
	{
		first_str[x] = second_str[x];
		if (second_str[x] == '\0')
			break;
	}

	return (first_str);
}
/**
 * _strcat - concatenates two strings
 * @first_str: first string
 * @second_str: second string
 * Return: result string
 */
char *_strcat(char *first_str, char *second_str)
{
	int x, y;

	for (x = 0; first_str[x]; x++)
		;
	for (y = 0; second_str[y]; y++)
		first_str[x++] =  second_str[y];
	first_str[x] = '\0';
	return (first_str);
}
