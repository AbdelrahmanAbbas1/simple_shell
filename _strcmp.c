#include "main.h"

/**
 * _strcmp - Comapres two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: 0 if equal - -1 if s1 is smaller and 1 if s1 is bigger
 */
int _strcmp(char *s1, char *s2)
{
	int len1 = 0, len2 = 0;
	int i;

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	if (len1 < len2)
		return (-1);
	else if (len2 > len1)
		return (1);
	for (i = 0; i < len1; i++)
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
	}
	return (0);
}
