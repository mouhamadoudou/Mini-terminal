/*
** EPITECH PROJECT, 2022
** separator.c
** File description:
** separator.c
*/

#include "../include/my.h"

int llen_point(char *str)
{
    int result = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == ' ' || str[a] == '\n')
            result = result + 1;
    }
    return result;
}

char *mmy_strcpy(char *dest, char *src, int pos)
{
    int i = pos;
    int comp = 0;

    while (src[i] != ' ' && src[i] != '\n' && src[i] != '\0') {
        dest[comp] = src[i];
        i ++;
        comp ++;
    }
    dest[comp] = '\0';
    return dest;
}

int llen_mot(char *buffer, int pos_d)
{
    int compteur = 0;
    int i = pos_d;

    while (buffer[i] !=  ' ' && buffer[i] !=  '\n' && buffer[i] !=  '\0') {
        compteur ++;
        i ++;
    }
    return compteur;
}

char **separ_tab_str(char *str)
{
    int len_p = llen_point(str);
    int comp = 0;
    char **tab = malloc(sizeof(char*) * (len_p + 1));
    int len_m = 0;

    tab[len_p] = NULL;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ') {
            len_m = llen_mot(str, i+1);
            tab[comp] = malloc(sizeof(char) * len_m + 1);
            mmy_strcpy(tab[comp], str, i+1);
            comp ++;
        }
        if(i == 0) {
            len_m = llen_mot(str, i);
            tab[comp] = malloc(sizeof(char) * len_m + 1);
            mmy_strcpy(tab[comp], str, i);
            comp++;
        }   
    }
    return tab;
}
