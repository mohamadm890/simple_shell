#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stddef.h>
extern char **environ;
#define INITIAL_BUFFER_SIZE 1040
#define BUFFER_INCREMENT 1040
char *getlineinput(void);
int executeCommand(char **tokens, char **argv);
int main(int argc, char **argv);
char **split(char *line);
