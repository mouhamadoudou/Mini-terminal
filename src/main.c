/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/
#include "../include/my.h"

int start(char **envp, st_env *set_env)
{
    size_t len = 0;
    int test = 0;
    char *buffer = NULL;
    write(1, "$> ", 3);

    while (1) {
        buffer = NULL;
        len = 0;
        if (getline(&buffer, &len, stdin) != -1) {
            if (buffer[0] == 'e' && buffer[1] == 'x' \
                && buffer[2] == 'i' && buffer[3] == 't')
                break; 
            excev(buffer, envp, test, set_env);
            write(1, "$> ", 3);
        } else {
            return 0;
        }
    }
    return 0;
}

int main(int argc, char **argv, char **envp)
{
    (void)(argv);
    st_env set_env;
    set_env.check = 0;

    if (argc != 1)
        return 84;
    start(envp, &set_env);
    if (set_env.check == 1)
        free(set_env.eenv);
    return 0;
}
