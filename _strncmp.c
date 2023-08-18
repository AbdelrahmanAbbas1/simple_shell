#include "main.h"

/**
 * _strncmp - Compares two strings for the n of bytes
 * @s1: The first string
 * @s2: The second string
 * @n: The number of bytes
 *
 * Return: 0 if equal, 1 if s1 is larger and -1 if s1 is smaller
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
	}

	return (0);
}
