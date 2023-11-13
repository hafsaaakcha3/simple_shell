#include "my_shell.h"

/**
 * print_environment - Print environment variables
 */
void print_environment(void)
{
	char *env_copy;
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		env_copy = *env;
		shell_print(env_copy);
	}
}
