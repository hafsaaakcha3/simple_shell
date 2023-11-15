#include "shell.h"

/**
 * check_spaces_tabs - Checks if a string contains only spaces and tabs
 * @str: The string to check
 * Return: 1 if the string contains only spaces and tabs, 0 otherwise
 */
int check_spaces_tabs(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}
