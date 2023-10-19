#ifndef SHELL_H
#define SHELL_H

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stddef.h>

extern char **environ;

void prompt_check(void);
void __exit(char *nothing);
int _strlen(char *str);
char *_strdup(char *str);
char **parsing(char **argv, char *str, const char *delim);
void executing(char **argv, char **command, int command_line);
void __free(char **command);
int _strcmp(char *first_str, char *second_str);
void non_interactive(char **argv, char *str);
void command_type(char **argv, char **command, int command_line);
int builtin(char **argv, char **com, int line_no);
void _perror(char *arg, int command_no, char *command);
void print_no(int num);
int print_c(char d);
char *getpath(char __attribute__((unused)) **argv, char **command);
char *_getenv(char *env_var);
char *_strcpy(char *first_str, char *second_str);
char *_strcat(char *first_str, char *second_str);
int _atoi(char *string);
void exit_perror(char *arg, int command_no, char **command);
void child_idc(char **command, char *actual_command);

#endif
