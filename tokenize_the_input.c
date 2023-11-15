#include "shell.h"

/**
 * tokenize_the_input - Tokenizes a string into an array of strings
 *
 * @input: The string to tokenize
 *
 * Return: An array of strings containing the tokens
 */
char **tokenize_the_input(char *input)
{
	char **args = NULL;
	char *separator = " \n\t";
	char *token;
	int index = 0;

	token = strtok(input, separator);

	while (token != NULL)
	{
		args = (char **)realloc(args, (index + 2) * sizeof(char *));
		args[index] = (char *)malloc(strlen(token) + 1);
		strcpy(args[index], token);
		token = strtok(NULL, separator);
		index++;
	}

	args[index] = NULL;
	free(token);
	return (args);
}
