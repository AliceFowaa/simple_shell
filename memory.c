#include "shell.h"

/**
 * Auth: Alice Agyemang
 *   Benjamin Kwame Oduro
 * bfree - Frees a pointer and NULLs the address.
 * @ptr: Address of the pointer to free.
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
if (ptr != NULL && *ptr != NULL)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
