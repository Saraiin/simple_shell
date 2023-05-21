#ifndef SHEL_H
#define SHEL_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

/* for string */
int str_len(char *s);
char *str_dup(char *s);
char *str_cpy(char *dest, char *src);
/*parsing the input line */
char **splitline(char *line, char *linecpy);
int numberOfToken(char *line, const char *separator);

#endif
