/*
** EPITECH PROJECT, 2022
** comande
** File description:
** commande
*/

#include "../include/my.h"

int my_unsetenv(char *buffer, char **env, st_env *set_env)
{
    return 0;
}

int my_code_next(char *buffer, char **env, st_env *set_env)
{
    if (buffer[0] == 'e' && buffer[1] == 'n' && buffer[2] == 'v') {
        my_env(env, set_env);
        return 0;
    }
    if (buffer[0] == 'u' && buffer[1] == 'n' && buffer[2] == 's'        \
        && buffer[3] == 'e' && buffer[4] == 't'&& buffer[5] == 'e' \
        && buffer[6] == 'n'&& buffer[7] == 'v') {
        my_unsetenv(buffer, env, set_env);
        return 0;
    }
    return 1;
}

int my_code(char *buffer, char **env, st_env *set_env)
{
    int check = 0;

    if (buffer[0] == 'c' && buffer[1] == 'd') {
        my_cd(buffer);
        return 0;
    }
    if (buffer[0] == 's' && buffer[1] == 'e' && buffer[2] == 't' \
        && buffer[3] == 'e' && buffer[4] == 'n'&& buffer[5] == 'v') {
        if (set_env->check != 1) {
            set_env->check = 1;
            set_env->eenv = my_set_env(set_env->eenv, buffer, env);
            return 0;
        }
        if (set_env->check == 1)
            my_set_env_v2(set_env, buffer);
        return 0;
    }
    else  {
        check = my_code_next(buffer, env, set_env);
        return check;
    }
}

int excev(char *buffer, char **envp, int test, st_env *set_env)
{
    pid_t pid;
    int stat = 0;
    char **tab = separ_tab_str(buffer);

    tab[0] = find_opt(tab[0], envp);
    if (tab[0][0] == 'N' && tab[0][1] == 'O') {
	test = my_code(buffer, envp, set_env);
        if (test == 0){
            return 0;
        }
    }
    pid = fork();
    if (pid == - 1)
        perror("fork");
    else if (pid > 0) {
        waitpid(pid, &stat, 0);
        kill(pid, SIGTERM);
    } else  {
        if (execve(tab[0], tab, envp) == -1) {
            perror("bash");
            execve("/bin/wait", tab, envp);
        }
        else 
            free_array_2(tab, 0);
    }
    free(tab);
    free(buffer);
    return 0;
}
