# SimpleShell

## Overview

SimpleShell is a simple command-line shell, written in C. Users can give commands and they will be executed in a child process. This basic shell provides support for basic command execution, showing fundamental concepts of process management and input parsing in C.

## Features

- Command parsing: The shell parses the user's input into individual command arguments.

- Command execution: The shell uses `fork()` function to create a new child process and `execvp()` function to execute the command.

- Exit command: The user can exit the shell by typing `exit`.

## Usage

1. Compile the program using `gcc`:

    ```bash

    gcc SimpleShell -o simple_shell.c

    ```

2. Run the shell:

    ```bash

    ./SimpleShell

    ```

3. Enter commands at the prompt:

    ```plaintext

    SimpleShell> ls

    SimpleShell> pwd

    SimpleShell> exit

    ```

## Memory Management

- The `parse_input` function allocates memory dynamically for the arguments array using `malloc()`.

- This memory is freed in the `main` function after each command is executed.

## Error Handling

- If `fork()` fails, an error message is printed.

- If `execvp()` fails, an error message is printed, and the child process exits.
