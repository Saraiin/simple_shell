#include "shel.h"
/**
 * checksprt - check if character is separator
 * @a: character
 * @s: string of delimiter
 * Return: 1 (success), 0 fails
 */
int checksprt(char a, const char *s)
{
	int k = 0;

	while (s[k])
	{
		if (s[k] == a)
			return (1);
		k++;
	}
	return (0);
}
/**
 * freeit - free an array of string
 * @ar: an array of strings
 */

void freeit(char **ar)
{
	int i = 0;

	while (ar[i] != NULL)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}
/**
 * freelist - free an array of string
 * @ar: the giving array to be freed
 * @i: the last index of the array
 */
void freelist(char **ar, int i)
{
	while (i > 0)
		free(ar[--i]);
	free(ar);
}
