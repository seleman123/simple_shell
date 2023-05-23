#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line
 * @info: contains potential arguments
 * Descritpion: displays the history list, one command by line
 *  Return: retruns 0
 */
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: info_t struct
 * @str: string alias
 * Description: sets alias to string
 * Return: returns 0 on success and 1 on error
 */
int unset_alias(info_t *info, char *str)
{
char *p, c;
int r;
p = _strchr(str, '=');
if (!p)
return (1);
c = *p;
*p = 0;
r = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*p = c;
return (r);
}

/**
 * set_alias - sets alias to string
 * @info: info_t struct
 * @str: tring alias
 * Description: sets alias to string
 * Return: returns 0 on success and 1 on error
 */
int set_alias(info_t *info, char *str)
{
char *p;
p = _strchr(str, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(info, str));
unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: alias node
 * Descritpion: prints an alias string
 * Return: returns 0 on success and 1 on error
 */
int print_alias(list_t *node)
{
char *p = NULL, *a = NULL;
if (node)
{
p = _strchr(node->str, '=');
for (a = node->str; a <= p; a++)
_putchar(*a);
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
 * _myalias - behaves like the builtin alias
 * @info: contains the potential arguments
 * Descritpion: behaves like the builtin alias
 *  Return: retuns 0
 */
int _myalias(info_t *info)
{
int i = 0;
char *p = NULL;
list_t *n = NULL;
if (info->argc == 1)
{
n = info->alias;
while (n)
{
print_alias(n);
n = n->next;
}
return (0);
}
for (i = 1; info->argv[i]; i++)
{
p = _strchr(info->argv[i], '=');
if (p)
set_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
}
return (0);
}
