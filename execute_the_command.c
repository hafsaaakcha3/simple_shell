#include "my_shell.h"

/**
 * exec_cmd - Execute a command with arguments
 * @args: An array of command arguments
 * @input_str: The user input string
 *
 * Description:
 * This function attempts to execute a command specified in the 'args' array.
 * If the command's path is not provided and the command is not in the current
 * directory, it searches for the command in the directories specified in the
 * PATH environment variable. If it finds a valid executable, it executes it.
 * If the command execution fails, it prints an error message and returns
 * EXIT_FAILURE. If the command is executed successfully, it does not return.
 *
 * Return: EXIT_SUCCESS on successful execution, EXIT_FAILURE on failure.
 */
int exec_cmd(char **args, char *input_str)
{
	char *path, *dir;
	char path_search[4096];
	char cmd_path[4096];

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		execve(args[0], args, NULL);
		perror(input_str);
		return EXIT_FAILURE;
	}
	else
	{
		path = getenv("PATH");
		if (path == NULL)
		{
			write(2, "PATH variable not found.\n", 25);
			exit(EXIT_FAILURE);
		}
		sprintf(path_search, ":%s:/usr/bin", path);
		dir = strtok(path_search, ":");
		while (dir)
		{
			snprintf(cmd_path, sizeof(cmd_path), "%s/%s", dir, args[0]);
			if (access(cmd_path, X_OK) == 0)
			{
				execve(cmd_path, args, NULL);
				perror(input_str);
				return EXIT_FAILURE;
			}
			dir = strtok(NULL, ":");
		}
	}
	return EXIT_SUCCESS;
}

