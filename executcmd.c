#include "shel.h"
char getPath(char *cmd)
{
}

void exectcmd(char **args)
{
	char *cmd = NULL;
	char *cmdpath = NULL;
	int test;
	if (args != NULL)
	{
		cmd = args[0];
		cmdpath = getPath(cmd);
		test = execve(cmdpath, args, NULL);
		if (test == -1)
			perror("Error path");
	}
}
