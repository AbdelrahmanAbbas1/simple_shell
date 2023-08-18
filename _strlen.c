#include "main.h"

/**
 * _strlen - Gets the length of a sting
 * @s: The string
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}
