#include "shell.h"

/**
 * execute_the_command - Executes a command with arguments
 * @args: An array of strings containing the command and its arguments
 * @input: The input string
 * Return: EXIT_SUCCESS if the command is executed , EXIT_FAILURE otherwise
 */
int execute_the_command(char **args, char *input)
{
	char *path, *dir;
	char path_search[4096];
	char command_path[4096];

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		execve(args[0], args, NULL);
		perror(input);
		return (EXIT_FAILURE);
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
			snprintf(command_path, sizeof(command_path), "%s/%s", dir, args[0]);
			if (access(command_path, X_OK) == 0)
			{
				execve(command_path, args, NULL);
				perror(input);
				return (EXIT_FAILURE);
			}
			dir = strtok(NULL, ":");
		}
	}
	return (EXIT_SUCCESS);
}
