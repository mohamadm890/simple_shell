#include "shell.h"
extern char** environ;

/*
 * executeCommand - execute command using fork() function
 *
 * @tokens - an array of command tokens
 *
 * @argv - an array of arguments
 *
 * @Return - Exit status of executed-commands
 *
 */
int executeCommand(char **tokens, char **argv)
{
	pid_t child;
	int status;
	child = fork();
	
	// fork a child process
	if (child == -1) 
	{
        	perror("fork");
        	exit(EXIT_FAILURE);
	}
	else if (child == 0) 
	{

	if (execve(tokens[0], tokens, environ))
	{
		// error handling - execve failure
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	else 
	{
		waitpid(child, &status, 0);
	}
	// return the exit the executed command
	return WEXITSTATUS(status);
}
