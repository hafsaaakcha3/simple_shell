#include "shell.h"

/**
 * read_the_input - Reads a line of text from the standard input stream
 *
 * @input: A pointer to a string to store the input
 * @buf_size: A pointer to the size of the input buffer
 *
 * Return: The number of characters read, including the newline character
 */
ssize_t read_the_input(char **input, size_t *buf_size)
{
	ssize_t rd;

	rd = getline(input, buf_size, stdin);
	if (rd == -1)
	{
		if (!isatty(STDIN_FILENO))
			return (-1);
		free(*input);
		perror("getline()");
		exit(EXIT_FAILURE);
	}

	if ((*input)[rd - 1] == '\n')
		(*input)[rd - 1] = '\0';

	return (rd);
}
