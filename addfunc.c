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
 * str_tok - splits string into tokens
 * @s: string to split
 * @separator: separator
 * Return: array of pointers to tokens
 
char **str_tok(char *s, const char *separator)
{
	char *token;
	int nbtokens = 0, i, j, l, tlen = 0, len = 0, start = 0, k = 0, end = 0;

	if (s == NULL)
		return (NULL);
	nbtokens = numberOfToken(s, separator);
	if (nbtokens == 0)
		return (NULL);
	token = malloc(sizeof(char *) * (nbtokens + 1));
	if (token == NULL)
	{
		perror("malloc error");
		return (NULL);
	}
	len = str_len(s);
	for (i = 0; i <= len; i++)
	{
		if (s[i] && checksprt(s[i], separator) && tlen++ == 0)
			start = i;
		else if (checksprt(s[i], separator) || !s[i])
		{
			if (tlen)
			{
				end = i - 1;
				token[k] = malloc((tlen + 1) * sizeof(char));
				if (token[k] == NULL)
				{
					perror("malooc");
					while (k >= 0)
						freelist(token, k);
				}
				for (j = start; l = 0; j <= end; j++, l++)
					token[k][l] = s[j];
				token[k][l] = '\0';
				tlen = 0, k++;
			}
		}
	}
	token[k] = NULL;
	return (token);
}
*/
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
