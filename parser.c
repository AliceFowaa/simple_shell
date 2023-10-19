#include "shell.h"

/**
 * Auth: Alice Agyemang
 *   Benjamin Kwame Oduro
 * is_cmd - Determines if a file is an executable command.
 * @info: The info struct.
 * @path: Path to the file.
 *
 * Return: 1 if true, 0 otherwise.
 */
int is_cmd(info_t *info, char *path)
{
struct stat st;

(void)info; /* Unused parameter. */
if (!path || stat(path, &st) != 0)
{
return (0);
}

return (S_ISREG(st.st_mode) ? 1 : 0);
}

/**
 * dup_chars - Duplicates characters from a string within a given range.
 * @pathstr: The string to duplicate from.
 * @start: Starting index.
 * @stop: Stopping index.
 *
 * Return: Pointer to a new buffer.
 */
char *dup_chars(const char *pathstr, int start, int stop)
{
static char buf[1024];
int k = 0;

for (int i = start; i < stop; i++)
{
if (pathstr[i] != ':')
{
buf[k++] = pathstr[i];
}
}

buf[k] = '\0';
return (buf);
}

/**
 * find_path - Finds the given command in the PATH string.
 * @info: The info struct.
 * @pathstr: The PATH string.
 * @cmd: The command to find.
 *
 * Return: Full path of the command if found, or NULL.
 */
char *find_path(info_t *info, char *pathstr, const char *cmd)
{
if (!pathstr || !cmd)
{
return (NULL);
}

if (strlen(cmd) > 2 && starts_with(cmd, "./"))
{
if (is_cmd(info, cmd))
{
return (cmd);
}
}

int i = 0, curr_pos = 0;
char *path;

while (1)
{
if (!pathstr[i] || pathstr[i] == ':')
{
path = dup_chars(pathstr, curr_pos, i);
if (!*path)
{
_strcat(path, cmd);
}
else
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (is_cmd(info, path))
return (path);
if (!pathstr[i])
break;
curr_pos = i;
}
i++;
}
return (NULL);
}
