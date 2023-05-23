#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: contains the potential arguments
 * Description: exits the shell
 * Return: exits with an exit status
 */
int _myexit(info_t *info)
{
int exitchecker;
if (info->argv[1]) /* If there is an exit arguement */
{
exitchecker = _erratoi(info->argv[1]);
if (exitchecker == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: contains the potential arguments
 * Description: changes the current directory of the process
 * Return: returns 0
 */
int _mycd(info_t *info)
{
char *s, *dir, buffer[1024];
int chdir_r;
s = getcwd(buffer, 1024);
if (!s)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
dir = _getenv(info, "HOME=");
if (!dir)
chdir_r = /* TODO: what should this be? */
chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
else
chdir_r = chdir(dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_r = /* TODO: what should this be? */
chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
chdir_r = chdir(info->argv[1]);
if (chdir_r == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: contains th potential arguments
 * Description: changes the current directory of the process
 * Return: retuns 0
 */
int _myhelp(info_t *info)
{
char **arg_arr;
arg_arr = info->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
_puts(*arg_arr); /* temp att_unused workaround */
return (0);
}
