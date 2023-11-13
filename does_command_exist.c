#include "my_shell.h"

/**
 * does_cmd_exist - Check if a command exists in the PATH
 * @args: An array of command arguments
 *
 * Description:
 * This function checks if a command specified in the 'args' array exists in the
 * directories specified in the PATH environment variable. It returns 1 if the
 * command is found and is executable, or 0 if it is not.
 *
 * Return: 1 if the command exists and is executable, 0 otherwise.
 */
int does_cmd_exist(char **args)
{
	char *path, *dir;
	char path_search[4096];
	char cmd_path[4096];

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
			snprintf(cmd_path, sizeof(cmd_path), "%s/%s", dir, args[0]);
			if (access(cmd_path, X_OK) == 0)
			{
				return 1;
			}
			dir = strtok(NULL, ":");
		}
	}
	return 0;
}