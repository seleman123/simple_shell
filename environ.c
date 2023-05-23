#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: contains the potential arguments
 *  Descritpion: prints the current environment
 * Return: returns 0
 */
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: contains the potential arguments
 * @name: env var name
 * Descritpion: gets the value of an environ variable
 * Return: returns the value
 */
char *_getenv(info_t *info, const char *name)
{
list_t *n = info->env;
char *p;
while (n)
{
p = starts_with(n->str, name);
if (p && *p)
return (p);
n = n->next;
}
return (NULL);
}

/**
 * _mysetenv - initializes a new or modifies env variable
 * @info: contains the potential arguments
 * Description: initializes a new or modifies env variable
 *  Return: retuns 0
 */
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
 * _myunsetenv - removes an env variable
 * @info: contains the potential arguments
 * Descritption: removes an env variable
 * Return: returns 0
 */
int _myunsetenv(info_t *info)
{
int i;
if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
_unsetenv(info, info->argv[i]);
return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: contains the potential arguments
 * Description: populates env linked list
 * Return: returns 0
 */
int populate_env_list(info_t *info)
{
list_t *n = NULL;
size_t i;
for (i = 0; environ[i]; i++)
add_node_end(&n, environ[i], 0);
info->env = n;
return (0);
}
