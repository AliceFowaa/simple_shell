#include "shell.h"

/**
 * Auth: Alice Agyemang
 *   Benjamin Kwame Oduro
 * _memset - Fills memory with a constant byte.
 * @s: Pointer to the memory area.
 * @b: The byte to fill *s with.
 * @n: The number of bytes to be filled.
 *
 * Return: A pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
for (unsigned int i = 0; i < n; i++)
{
s[i] = b;
}
return (s);
}

/**
 * ffree - Frees a string of strings.
 * @pp: String of strings.
 */
void ffree(char **pp)
{
if (!pp)
{
return;
}

char **a = pp;
while (*pp)
{
free(*pp++);
}
free(a);
}

/**
 * _realloc - Reallocates a block of memory.
 * @ptr: Pointer to the previous malloc'ed block.
 * @old_size: Byte size of the previous block.
 * @new_size: Byte size of the new block.
 *
 * Return: Pointer to the reallocated block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
{
return (malloc(new_size));
}

if (!new_size)
{
free(ptr);
return (NULL);
}

if (new_size == old_size)
{
return (ptr);
}

p = malloc(new_size);

if (!p)
{
return (NULL);
}

old_size = (old_size < new_size) ? old_size : new_size;

while (old_size--)
{
p[old_size] = ((char *)ptr)[old_size];
}

free(ptr);
return (p);
}
