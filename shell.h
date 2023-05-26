#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
/**
 * struct buildin - Struct build-in commands
 * @cmd: The build in command
 * @func: the function associated
 */

typedef struct buildin
{
	char *cmd;
	int (*func)(char *exe, int ac, char **av, char **e, int s);
} buildin_t;

extern char **environ;
int showenv(char *exe, int ac, char **as, char **e, int s);
char *_getenv(const char *name, char **e);
void free_list(char **ptr, int i);
char **parseAllcmd(char *lineptr);
void free_args(char **av);
int delimck(char c, const char *delim);
int exitit(char *exe, int ac, char **as, char **e, int s);
void cmdexit(int status, char **av, char *line, char **cmd);
char **parseit(char *lineptr, char **e, int s);
int count_token(char *lineptr, const char *delim);
char *showpath(char *cmd, char *envPath);
void creatPath(char *dirPath, char *cmd, char *path);
void signee(int signal);
int (*callMyfunc(char *c))(char *x, int n, char **a, char **e, int s);
void prmp(void);
void ignore_comments(char *lineptr);
int tokenCnt(char *str, const char *delim);
int array_len(char **args);
int notfound(char *exe, char **av);
void showerror(char *exe, char *desc);
int execut(char *exe, char **av, char **e);
char *str_cat(char *str1, char *str2);
int str_cmp(char *str1, const char *str2);
char *str_cpy(char *dest, char *src);
char *str_dup(char *str);
int str_len(char *str);
int replacevar(char **args, char **e, int s);
char *convertnum(int n, int base, int upper_o_n);
int is_digit(int c);
int atoii(char *s);
#endif
