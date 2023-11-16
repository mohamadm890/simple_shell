#include "shell.h"

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
		free(line);
		continue;
	}
	executeCommand(commands, argv);
	free(line);
	free(commands);

	}

	return 0;
}

char *getlineinput(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
	{
	write(STDOUT_FILENO, "$ ", 2);
	}

	n = getline(&line, &len, stdin);

	if (n == -1)
	{
	free(line);
	return (NULL);
	}

	return (line);
}
