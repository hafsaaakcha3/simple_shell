#include "my_shell.h"

/**
 * exec_forked_cmd - Execute a command in a forked process
 * @args: An array of command arguments
 * @input_str: The user input string
 *
 * Description:
 * This function forks a new process to execute the given command. In the child
 * process, it calls exec_cmd to execute the command. If an error
 * occurs, it prints an error message and exits. In the parent process, it
 * waits for the child process to complete and returns the exit status of the
 * child process.
 *
 * Return: The exit status of the child process, or -1 on failure.
 */
int exec_forked_cmd(char **args, char *input_str)
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
		if (exec_cmd(args, input_str) == -1)
		{
			perror(input_str);
			free_args(args);
			exit(EXIT_FAILURE);
		}
	}
	if (wait(&status) == -1)
		perror("wait");
	if (WIFEXITED(status))
		return WEXITSTATUS(status);
	return -1;
}
