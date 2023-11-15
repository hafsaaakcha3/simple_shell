#include "shell.h"

/**
 * handle_the_builtins - Handles built-in shell commands
 *
 * @args: An array of strings containing the command and its arguments
 * @input: The input string
 * @exit_num: The exit status to use if no exit status is specified
 *
 * Return: 1 if the command is a built-in, 0 otherwise
 */
int handle_the_builtins(char **args, char *input, int exit_num)
{
	int exit_status = EXIT_SUCCESS;

	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1])
			exit_status = atoi(args[1]);
		else if (exit_num != -1)
			exit_status = exit_num;
		free_arguments(args);
		free(input);
		exit(exit_status);
	}
	else if ((strcmp(args[0], "env") == 0) || (strcmp(args[0], "printenv") == 0))
	{
		printenv();
		free_arguments(args);
		return (1);
	}

	return (0);
}
