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
#include <signal.h>


/* for string */
int str_len(char *s);
char *str_dup(char *s);
char *str_cpy(char *dest, char *src);
/*parsing the input line */
char **splitline(char *line, char **envpt, int st);
int numberOfToken(char *line, const char *separator);
/*executer*/
int exectcmd(char *xe, char **av, char **envpt);
int (*callMyFunc(char *command))(char *x, int nb, char **args, char **env, int status);
char *get_env(const char *envname, char **arenv);
char *str_cat(char *s1, char *s2);
int str_cmp(char *s1, const char *s2);
char *getPath(char *cmd, char *pathenv);
int printenv(char *exe, int ac, char **args, char **ptenv, int status);
/*building functions*/
/*exit*/
int checkdegit(int n);
int exitt(char *exe, int ac, char **args, char **envpt, int st);
int atoii(char *str);
void freelist(char **ar, int i);
/**
 * struct Node - struct forenv var
 * @name: name of env var
 * @value: value ofit
 * @nex: pointerto the next
 */
typedef struct Node
{
	char *name;
	char *value;
	struct Node *next;
} Node_t;
/**
 * struct funcbuild - struct for command functions
 * @cmd: command
 * @func: the function for command
 */
typedef struct funcbuild
{
	char *cmd;
	int (*func)(char *exe, int ac, char **args, char **ptenv, int status);
} funcbuild_t;
/* print env variable */
int str_cmp(char *s1, const char *s2);
extern char **environ;
char **str_tok(char *s, const char *separator);
void freeit(char **ar);
int getArlen(char **args);
void exitcmd(int status, char **av, char *line, char **c);
char **getAllCmd(char *line);
int changeVar(char **args, char **e, int st);
char *convertnum(int n, int base, int checkcasse);
void cmtignore(char *line);
#endif
