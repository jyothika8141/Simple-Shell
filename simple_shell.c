#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64

void execute_command(char **args);
char **parse_input(char *input);

int main() {
    char input[MAX_INPUT_SIZE];
    char **args;

    while (1) {
        printf("SimpleShell> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline

        if (strcmp(input, "exit") == 0) {
            break;
        }

        args = parse_input(input);
        execute_command(args);

        // Free allocated memory
        free(args);
    }

    return 0;
}

char **parse_input(char *input) {
    char **args = malloc(MAX_ARG_SIZE * sizeof(char*));
    char *token = strtok(input, " ");
    int i = 0;

    while (token != NULL && i < MAX_ARG_SIZE - 1) {
        args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL;

    return args;
}

void execute_command(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("SimpleShell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error handling
        perror("SimpleShell");
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, WUNTRACED);
    }
}