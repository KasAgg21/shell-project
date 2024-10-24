// Shell - Kashish

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Exit/Bye Function
void k_exit(char **agr)
{
    exit(0);
}

// Bye
void k_bye(char **agr)
{
    system("eog bye.png");
    exit(0);
}

// Date func

void k_date(char **agr)
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Date: %d-%d-%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

// Time Func

void k_time(char **agr)
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    if (tm.tm_hour >= 12)
    {
        if (tm.tm_hour == 12)
            printf("12");
        else
            printf("%d", tm.tm_hour - 12);
        printf(":%d:%d PM\n", tm.tm_min, tm.tm_sec);
    }
    else
        printf("%d:%d:%d AM\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
}

// info

void k_info(char **agr)
{
    printf("This is a basic shell programmed in C Language\n for Course Practical Computing\n");
}

// pwd

void k_pwd(char **agr)
{
    char *buf;
    buf = (char *)malloc(100 * sizeof(char));
    getcwd(buf, 100);
    printf("\n %s \n", buf);
}

// current username

void k_user(char *agr)
{
    char *buf;
    buf = (char *)malloc(10 * sizeof(char));
    buf = getlogin();
    printf("\n %s \n", buf);
}

// flip

void k_flip(char **agr)
{
    int f = rand() % 10;
    if (f % 2 == 0)
    {
        printf("Tails\n");
    }
    else if (f % 2 != 0)
    {
        printf("Heads\n");
    }
}

// Cd function

void k_cd(char **agr)
{
    if (agr[1] == NULL)
    {
        fprintf(stderr, "Kashish: cd: missing argument\n");
    }
    else
    {
        if (chdir(agr[1]) != 0)
        {
            perror("kashish: cd");
        }
    }
}

// Clear func

void k_clear(char **agr)
{
    system("clear");
}

// Help function

void k_help(char **agr)
{
    char *txt =
        "Kashish - KASHISH AGGARWAL 102103490 SHELL\n"
        "info - display basic info about this project\n"
        "The followng commands are built in this\n"
        "cd - change working dir\n"
        "exit - exit the shell\n"
        "bye - bye bye from the shell\n"
        "help - prints this text\n"
        "date - display current date\n"
        "time - display current time in 12hr format\n"
        "pwd - displays pesent working directory\n"
        "clear - clear the screen/terminal window\n"
        "flip - flips a coin\n"
        "user - displays name of the user\n"
        "ls - list all contents\n";
    printf("%s", txt);
}

// It helps in assigning the cmd name to the handler func

struct bults
{
    char *name;
    void (*func)(char **agr);
};

// List of built cmds

struct bults bult[] =
    {
        {"help", k_help},
        {"exit", k_exit},
        {"bye", k_bye},
        {"cd", k_cd},
        {"date", k_date},
        {"time", k_time},
        {"pwd", k_pwd},
        {"clear", k_clear},
        {"info", k_info},
        {"flip", k_flip},
        {"user", k_user},
};

// Other Functions

int k_num_bult()
{
    return sizeof(bult) / sizeof(struct bults);
}

// Executer Bit

void k_exe(char **agr)
{
    for (int i = 0; i < k_num_bult(); i++)
    {
        if (strcmp(agr[0], bult[i].name) == 0)
        {
            bult[i].func(agr);
            return;
        }
    }

    pid_t child_pid = fork();
    if (child_pid == 0)
    {
        execvp(agr[0], agr);
        perror("Kashish");
        exit(1);
    }
    else if (child_pid > 0)
    {
        int stat;
        do
        {
            waitpid(child_pid, &stat, WUNTRACED);
        } while (!WIFEXITED(stat) && !WIFEXITED(stat));
    }
    else
    {
        perror("Kashish");
    };
}

// Line Splitter and Praizer

char **k_split(char *line)
{
    int len = 0;
    int cap = 16;
    char **tokens = malloc(cap * sizeof(char *));
    if (!tokens)
    {
        perror("Kashish");
        exit(1);
    }
    char *delmiters = "\t\r\n";
    char *token = strtok(line, delmiters);

    while (token != NULL)
    {
        tokens[len] = token;
        len++;
        if (len >= cap)
        {
            cap = (int)(cap * 1.6);
            tokens = realloc(tokens, cap * sizeof(char *));
            if (!tokens)
            {
                perror("Kashish");
                exit(1);
            }
        }
        token = strtok(NULL, delmiters);
    }
    tokens[len = NULL];
    return tokens;
}

// Reading the Line using getline

char *k_read_line()
{
    char *line = NULL;
    size_t buflen = 0;
    errno = 0;
    ssize_t stlen = getline(&line, &buflen, stdin);
    if (stlen < 0)
    {
        if (errno)
        {
            perror("Kashish");
        }
        exit(1);
    }
    return line;
}

int main() // Main Function handling the loop to read and break the line to understand the commands
{
    while (true)
    {
        printf(" > ");
        char *line = k_read_line();
        char **tokens = k_split(line);
        if (tokens[0] != NULL)
        {
            k_exe(tokens);
        }
        free(tokens);
        free(line);
    }
}
