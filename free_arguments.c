#include "shell.h"

/**
 * free_arguments - Frees an array of strings and sets each element to NULL
 *
 * @args: The array of strings to free
 *
 * Return: None
 */
void free_arguments(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
		args[i] = NULL;
	}
	free(args);
}
