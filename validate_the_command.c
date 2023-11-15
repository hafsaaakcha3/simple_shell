#include "shell.h"

/**
 * validate_the_command - Validates a command and its arguments
 *
 * @args: An array of strings containing the command and its arguments
 * @input: The input string
 * @exit_num: The exit status to use if no exit status is specified
 *
 * Return: 1 if the command is valid, 0 otherwise
 */
int validate_the_command(char **args, char *input, int exit_num)
{
	if (handle_the_builtins(args, input, exit_num))
	{
		return (1);
	}

	if (!does_command_exist(args))
	{
		fprintf(stderr, "Command not found: %s\n", args[0]);
		free_arguments(args);
		return (0);
	}

	return (1);
}
