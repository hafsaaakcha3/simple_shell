#include "shell.h"

/**
 * printenv - Prints all environment variables to the standard output stream
 *
 * Return: None
 */
void printenv(void)
{
	char *env_copy;
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		env_copy = *env;
		shell_print(env_copy);
	}
}
