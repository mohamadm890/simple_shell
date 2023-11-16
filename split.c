#include "shell.h"
/**
 * split - it responsable for tokenize a line
 * @line: input enter by user
 *
 * Return: tokens on success, NULL
 */
char **split(char *line)
{
int buffer = INITIAL_BUFFER_SIZE;
int position = 0;
char **temp;
char *token;
char **tokens;
tokens = malloc(buffer * sizeof(char *));
if (!tokens)
{
return (NULL);
}
token = strtok(line, " \t\r\n\a");
while (token != NULL)
{
tokens[position] = token;
position++;
if (position >= buffer)
{
buffer += BUFFER_INCREMENT;
temp = realloc(tokens, buffer *sizeof(char *));
if (!temp)
{
free(tokens);
return (NULL);
}
tokens = temp;
}
token = strtok(NULL, " \t\r\n\a");
}
tokens[position] = NULL;
return (tokens);
}
