/*
** EPITECH PROJECT, 2022
** set env 
** File description:
** set env 
*/

#include "../include/my.h"

char **my_tabcpy(char **dest, char **src)
{
    int len = strlen_array(src);
    int len_mot = 0;

    dest = malloc(sizeof(char*) * (len + 1));
    dest[len] = NULL;
    for(int a = 0; src[a] != NULL; a++) {
        len_mot = my_strlen(src[a]);
        dest[a] = malloc(sizeof(char) * (len_mot + 1));
        dest[a][len_mot] = '\0';
    }
    for(int i = 0; src[i] != NULL; i++)
        my_strcp(dest[i], src[i]);
    return dest;
}

char **my_set_env(char **set_env, char *buffer, char **env)
{
    int len = strlen_array(env);
    int len_mot = 0;

    set_env = malloc(sizeof(char*) * (len + 2));
    set_env[len + 1] = NULL;
    for (int a = 0; env[a] != NULL; a++) {
        len_mot = my_strlen(env[a]);
        set_env[a] = malloc(sizeof(char) * (len_mot + 1));
        set_env[a][len_mot] = '\0';
    }
    for (int i = 0; env[i] != NULL; i++)
        my_strcp(set_env[i], env[i]);
    len_mot = my_strlen(buffer);
    set_env[len] = malloc(sizeof(char) * (len_mot + 1));
    my_scp(set_env[len], buffer);
    env = set_env;
    return set_env;
}

int check_buff(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ' && str[i+1] != '\0' && str[i+1] != '\n' && str[i+1] != ' ')
            return 0;
    }
    return -1;
}

char **my_set_env_v2(st_env *set_env, char *buffer)
{
    char **tab = NULL;

    set_env->eenv = my_set_env(tab, buffer, set_env->eenv);
    return tab;
}
