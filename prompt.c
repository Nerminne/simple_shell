#include "shell.h"
/**
 * prompt_check - handling prompt on
 * interactive/non-interactive mode
 * Return: nothing
 */
void prompt_check(void)
{
	if (isatty(STDIN_FILENO))
		write(1, "(>*-*)> ", 8);
}
