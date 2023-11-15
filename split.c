#include "shell.h"
#define INITIAL_BUFFER_SIZE 1040
#define BUFFER_INCREMENT 1040
/**
 * split a string into tokens based on whitespace characters.
 *
 * This function takes a string as input and tokenizes it using whitespace characters
 * (space, tab, newline, carriage return, and alarm). It dynamically allocates memory
 * for an array of strings to store the tokens.
 *
 * @param line The input string to be tokenized.
 * @return A dynamically allocated array of strings containing the tokens.
 *         Returns NULL in case of memory allocation failure.
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
        tokens[position] = strdup(token);
        position++;

        if (position >= buffer) {
            buffer += BUFFER_INCREMENT; 
            temp = realloc(tokens, buffer * sizeof(char *));
            if (!temp) {
                for (size_t i = 0; i < position; i++) {
                    free(tokens[i]);
                }
                free(tokens);
                return NULL;
            }
            tokens = temp;
        }

        token = strtok(NULL, " \t\r\n\a");
    }

    tokens[position] = NULL;
    return tokens;
}
