/*
** EPITECH PROJECT, 2022
** concat et checkfile
** File description:
** concat et checkfile
*/

#include "../include/my.h"

int check_help(char *str, char *str_2)
{
    for(int i = 0; str[i] != '='; i ++) {
        if (str[i] != str_2[i])
            return 0;
    }
    return 1;
}

int path(char **env)
{
    int result = 0;

    for (int a = 0; env[a] != NULL; a++) {
        if(env[a][0] == 'P' && env[a][1] == 'A' && env[a][0] == 'T') {
            result = a;
            return result;
        }
    }
    return -1;
}

char *concat(char *str1, char *str2)
{
    int a = my_strlen(str1);
    int b = my_strlen(str2);
    int len = a + b + 1;
    char *str = malloc(sizeof(char) * (len + 1));
    int x = 0;

    str[len] = '\0';
    for (int val = 0; str1[val] != '\0'; val++) {
        str[x] = str1[val];
	x++;
    }
    str[x] = '/';
    x++;
    for (int val = 0; str2[val] != '\0'; val++) {
        str[x] = str2[val];
        x++;
    }
    return str;
}

int test_chack(char *buffer)
{
    if (buffer[0] == 'c' && buffer[1] == 'd')
        return -1;
    if (buffer[0] == 'e' && buffer[1] == 'n' && buffer[2] == 'v')
        return -1;
     if (buffer[0] == 's' && buffer[1] == 'e' && buffer[2] == 't')
        return -1;
     return 0;
}
