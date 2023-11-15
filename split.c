#include "shell.h"
#define INITIAL_BUFFER_SIZE 1040
#define BUFFER_INCREMENT 1040

/**
* @brief - splits a line into tokens
*
* @param - line The input line to be tokenized
*
* @return - return an array of tokens
*/

char **split(char *line) {
	int buffer = INITIAL_BUFFER_SIZE;
	int position = 0;
	char **tokens;
   char **temp;
    char *token;
    tokens = malloc(buffer * sizeof(char *));
    if (!tokens) {
        return NULL;
    }
    token = strtok(line, " \t\r\n\a");
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= buffer) {
            buffer += BUFFER_INCREMENT; 
            temp = realloc(tokens, buffer * sizeof(char *));
            if (!temp) {
                free(tokens);
                return NULL;
            }
            tokens = temp;
        }

        token = strtok(NULL, " \t\r\n\a");
    }

    tokens[position] = NULL;
    return (tokens);
}
