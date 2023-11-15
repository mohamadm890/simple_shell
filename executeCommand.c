#include "shell.h"
extern char** environ;

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
if (execve(tokens[0], tokens, environ))
{
perror(argv[0]);
exit(EXIT_FAILURE);
}
} 
else 
{
waitpid(child, &status, 0);
}
return WEXITSTATUS(status);
}
