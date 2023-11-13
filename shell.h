#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

extern char **environ;

int my_shell(void);
ssize_t read_user_input(char **input, size_t *buf_size);
int validate_command(char **args, char *input, int exit_num);
int handle_builtins(char **args, char *input, int exit_num);
void free_arguments_memory(char **args);
int execute_forked_command(char **args, char *input);
int execute_command(char **args, char *input);
int does_command_exist_in_path(char **args);
int is_only_spaces_tabs(char *str);
char **tokenize_input(char *input);
void handle_signal(int sig);
void shell_print(char *str);
void print_environment(void);

#endif

