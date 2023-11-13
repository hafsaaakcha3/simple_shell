#include "my_shell.h"

/**
 * handle_builtins - Handle built-in shell commands
 * @args: An array of command arguments
 * @input_str: The user input string
 * @exit_status: The exit status to set on exit
 *
 * Description:
 * This function handles built-in shell commands like "exit" and "env". If the
 * command is "exit," it checks for an optional exit status, sets it, frees
 * memory, and exits the program. If the command is "env," it prints the
 * environment variables and returns. For all other commands, it returns 0.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int handle_builtins(char **args, char *input_str, int exit_status)
{
	int status = EXIT_SUCCESS;

	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1])
			status = atoi(args[1]);
		else if (exit_status != -1)
			status = exit_status;
		free_args(args);
		free(input_str);
		exit(status);
	}
	else if ((strcmp(args[0], "env") == 0) || (strcmp(args[0], "printenv") == 0))
	{
		print_environment();
		free_args(args);
		return 1;
	}

	return 0
