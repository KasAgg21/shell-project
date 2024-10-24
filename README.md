# Basic Shell in C Language

## 1. Introduction
This project implements a basic shell in C language with several built-in commands. Developing this shell has provided a great learning experience, helping me understand the use of header files, shell commands, and their functionality.

A shell provides an interface to the Unix system, allowing users to input commands and execute programs. Once a program finishes execution, it returns the output to the user. Shells serve as an environment where we can run commands, programs, and shell scripts. There are many variations of shells, each with its own recognized commands and features.

## 2. Built-in Commands

Here are the built-in commands supported by this shell:

- **help**: Displays a list of all commands available in the shell and gives a brief description of each.
- **date**: Shows the current date in `dd:mm:yyyy` format (uses `time.h`).
- **time**: Displays the current time in `hh:mm:ss` format (uses `time.h`).
- **pwd**: Prints the present working directory.
- **clear**: Clears the terminal screen.
- **flip**: Flips a coin and outputs either "heads" or "tails" randomly.
- **user**: Displays the current user's name.
- **ls**: Lists the contents of the current directory.
- **cd**: Changes the current working directory.
- **info**: Provides basic information about this project.
- **bye**: Exits the shell with a fun message.
- **exit**: Exits the shell and returns control to the terminal.

## 3. Significance of Header Files

- **stdio.h**: Provides input/output operations (e.g., `printf`, `scanf`).
- **sys/wait.h**: Used in process control, mainly for waiting on child processes (e.g., `WIFEXITED`, `WUNTRACED`, `pid_t`).
- **unistd.h**: Contains miscellaneous constants and types, also provides system call wrappers.
- **stdbool.h**: Defines boolean data types (`true`, `false`).
- **errno.h**: Provides error codes to diagnose errors.
- **time.h**: Used to extract and manipulate date and time.
- **stdlib.h**: Provides standard functions like `perror` for printing error messages.

## 4. Screenshots of the Working Prototype

- **help**: Shows the list of available commands.
- ![Screenshot_2022-12-20_14-28-15](https://github.com/user-attachments/assets/6fc5e78c-a592-4294-a7c2-5fef549d3434)
- **info**: Provides project-related information.
- **cd**: Demonstrates directory change functionality.
- **date**: Displays the current date.
- **time**: Displays the current time.
- **pwd**: Displays the present working directory.
- **flip**: Simulates a coin flip.
- ![Screenshot_2022-12-20_14-30-38](https://github.com/user-attachments/assets/96cd3dc7-9650-416f-ac73-7173bce6555e)
- **user**: Shows the current user.
- **ls**: Lists the directory contents.
- ![Screenshot_2022-12-20_14-30-55](https://github.com/user-attachments/assets/b88ab578-46b8-4c00-be78-2c9b2117d91c)
- **bye/exit**: Exits the shell.
- ![Screenshot_2022-12-20_14-33-16](https://github.com/user-attachments/assets/0e687a84-8bf7-4773-a274-aee728ee5bd9)


## 5. Code

The code for this project is available in the repository. Please feel free to explore and modify the code according to your requirements.
