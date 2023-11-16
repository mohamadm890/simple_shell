#include "shell.h"
/**
 * executeCommand - it will take functions then will print output
 * @tokens: is commend will use by function
 * @argv: it is all argv function will be using
 *
 * Return: state
 */
int executeCommand(char **tokens, char **argv)
{
pid_t child;
int status;
child = fork();
if (child == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (child == 0)
{
if (execve(tokens[0], tokens, environ) == -1)
{
perror(argv[0]);
exit(EXIT_FAILURE);
}
}
else
{
waitpid(child, &status, 0);
}
return (WEXITSTATUS(status));
}
