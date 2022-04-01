/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** includer
*/

#ifndef _MY_H_
    #define _MY_H_
    #include <sys/wait.h>
    #include <string.h>
    #include <sys/types.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>

typedef struct st_env
{
    char **eenv;
    char **env_copie;
    int check;
} st_env;

char **separ_tab_str(char *str);
char **separ_tab(char *str);
int my_strlen(char *str);
void my_putchar(char c);
int my_putstr(char const *str);
char *find_path(char *buffer);
void my_cd(char *path);
char *find_opt(char *buffer, char **env);
int excev(char *buffer, char **envp, int test, st_env *set_env);

char *find_path(char *buffer);
void my_cd(char *path);

int check_help(char *str, char *str_2);
int path(char **env);
char *concat(char *str1, char *str2);
int test_chack(char *buffer);
void free_array(char **tab, int check, int check2);
void free_array_2(char **tab, int check);

char *find_opt(char *buffer, char **env);
void my_env(char **env, st_env *set_env);

int strlen_array(char **tab);
char *my_strcp(char *dest, char const *src);
char *my_scp(char *dest, char *src);

char **my_tabcpy(char **dest, char **src);
char **my_set_env(char **set_env, char *buffer, char **env);
char **my_set_env_v2(st_env *set_env, char *buffer);

#endif /* _MY_H_ */
