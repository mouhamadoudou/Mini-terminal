/*
** EPITECH PROJECT, 2022
** strelen array && my_strcp && my_scp
** File description:
** strelen array && my_strcp && my_scp
*/

#include "../include/my.h"

int strlen_array(char **tab)
{
    int result = 0;

    for (int i = 0; tab[i] != NULL; i++)
        result++;
    return result;
}

char *my_strcp(char *dest, char const *src)
{
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    return dest;
}

char *my_scp(char *dest, char *src)
{
    int i = 0;
    char **tab_mot = separ_tab_str(src);

    while(tab_mot[1][i] != '\0') {
        dest[i] = tab_mot[1][i];
        i++;
    }
    dest[i] = '=';
    i++;
    for(int a = 0; tab_mot[2][a] != '\0'; a++) {
        dest[i] = tab_mot[2][a];
        i++;
    }
    dest[i] = '\0';
    free(tab_mot);
    return dest;
}
