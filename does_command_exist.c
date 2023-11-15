#include "shell.h"

/**
 * does_command_exist - Checks if a command exists in the PATH environment var
 * @args: An array of strings containing the command and its arguments
 * Return: 1 if the command exists, 0 otherwise
 */
int does_command_exist(char **args)
{
	char *path, *dir;
	char path_search[4096];
	char command_path[4096];

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		return (access(args[0], X_OK) == 0);
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
				return (1);
			}
			dir = strtok(NULL, ":");
		}
	}
	return (0);
}
