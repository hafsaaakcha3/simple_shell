#include "shell.h"

/**
 * execute_the_forked_command - Exec a command with arguments in a new process
 *
 * @args: An array of strings containing the command and its arguments
 * @input: The input string
 *
 * Return: The exit status of the child process
 */
int execute_the_forked_command(char **args, char *input)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execute_the_command(args, input) == -1)
		{
			perror(input);
			free_arguments(args);
			free(input);
			exit(EXIT_FAILURE);
		}
	}
	if (wait(&status) == -1)
		perror("wait");
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (-1);
}
