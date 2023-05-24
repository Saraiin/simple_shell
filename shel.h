#ifndef SHEL_H
#define SHEL_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


/* for string */
int str_len(char *s);
char *str_dup(char *s);
char *str_cpy(char *dest, char *src);
/*parsing the input line */
char **splitline(char *line, char *linecpy);
int numberOfToken(char *line, const char *separator);
/*executer*/
void exectcmd(int ac, char **av, char ***envpt, int status);
int (*callMyFunc(char *))(int ac, char **args, char ***env, int status);
char *get_envar(const char *envname, char **arenv);
char *str_cat(char *s1, char *s2);
int str_cmp(char *s1, const char *s2);
char *getPath(char *cmd, char *pathenv);
int printenv(int ac, char **args, char ***ptenv, int status);
/*building functions*/
/*exit*/
int checkdegit(int n);
int exitt(int ac, char **args, char ***ptenv, int prstatus);
int atoii(char *str);

/**
 * struct funcbuild - struct for command functions
 * @cmd: command
 * @func: the function for command
 */
typedef struct funcbuild
{
	char *cmd;
	int (*func)(int ac, char **args, char ***ptenv, int status);
} funcbuild_t;
/* print env variable */
int printenv(int ac, char **args, char ***ptenv, int status);
int str_cmp(char *s1, const char *s2);
extern char **environ;
char **str_tok(char *s, const char *separator);
void freeit(char **ar, int index);
#endif
