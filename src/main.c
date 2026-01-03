#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024

int main() {
    char line[MAX_LINE];

    while (1) {
        printf("minishell$ ");
        if (!fgets(line, MAX_LINE, stdin)) break;

        line[strcspn(line, "\n")] = 0; // убираем \n

        if (strcmp(line, "exit") == 0) break;

        if (strncmp(line, "cd ", 3) == 0) {
            if (chdir(line + 3) != 0) {
                perror("cd failed");
            }
            continue;
        }

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            continue;
        }

        if (pid == 0) {
            // Разбиваем команду на аргументы для execvp
            char *args[64];
            char *token = strtok(line, " ");
            int i = 0;
            while (token != NULL) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL;

            execvp(args[0], args); // запускаем команду
            perror("execvp failed"); // если команда не найдена
            exit(1);
        } else {
            wait(NULL); // ждём завершения команды
        }
    }

    printf("\nBye!\n");
    return 0;
}

