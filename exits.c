#include "shell.h"

/**
 * _strncpy - copies a string with a length limit
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the maximum number of characters to be copied
 * Return: the concatenated string
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
char *original_dest = dest;

while (n > 0 && *src != '\0')
{
*dest++ = *src++;
n--;
}

while (n > 0)
{
*dest++ = '\0';
n--;
}

return (original_dest);
}

/**
 * _strncat - concatenates two strings with a length limit
 * @dest: the destination string
 * @src: the source string
 * @n: the maximum number of bytes to be used
 * Return: the concatenated string
 */
char *_strncat(char *dest, const char *src, size_t n)
{
char *original_dest = dest;

while (*dest != '\0')
dest++;

while (n > 0 && *src != '\0) {
*dest++ = *src++;
n--;
}

if (n > 0)
*dest = '\0';

return (original_dest);
}

/**
* _strchr - locates a character in a string
* @s: the string to be parsed
* @c: the character to look for
* Return: a pointer to the first occurrence of c in s, or NULL if not found
*/
char *_strchr(const char *s, int c)
{
while (*s != '\0') {
if (*s == c)
return ((char *)s);
s++;
}

return (NULL);
}
