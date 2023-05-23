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
void exectcmd(char **args);
/*building functions*/
/*exit*/
int checkdegit(int n);
int exitt(int ac, char **args, char ***ptenv, int prstatus);
int atoii(char *str);

/**
 * struct funcbuilt - struct for command functions
 * @cmd: command
 * @func: the function for command
 */
typedef struct funcbuild
{
	char cmd;
	int (*func)(int ac, char **args, char ***ptenv, int status);
}funcbuild_t;
#endif
