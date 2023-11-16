#include "shell.h"
/**
 * main - all function will be working together it
 * @argc: first argu
 * @argv: list of argu to be used
 *
 * Return: 1 if true, 0 otherwise
 */

int main(int argc, char **argv)
{
char *line = NULL;
char **commands = NULL;
(void) argc;
while (1)
{
line = getlineinput();
if (line == NULL)
{
break;
}
commands = split(line);
if (!commands)
{
continue;
}
executeCommand(commands, argv);
free(commands);
}
return (0);
}
/**
 * getlineinput - it will print line for user
 * Return: 1 if true, 0 otherwise
 *
 */
char *getlineinput(void)
{
char *line = NULL;
size_t len = 0;
ssize_t n;
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
n = getline(&line, &len, stdin);
if (n == -1)
{
free(line);
return (NULL);
}
return (line);
}
