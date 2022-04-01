/*
** EPITECH PROJECT, 2022
** separator.c
** File description:
** separator.c
*/

#include "../include/my.h"

int my_strlen_str(char *str)
{
    int decompteur = 1;
    int compteur = 1;

    while (str[decompteur] != '\0') {
        if(str[decompteur] == ':')
            compteur = compteur + 1;
        decompteur = decompteur + 1;
    }
    return (compteur);
}

int len_mot(char *buffer, int pos_d)
{
    int compteur = 0;
    int i = pos_d;

    while (buffer[i] != ':') {
        compteur ++;
	i ++;
    }
    return compteur;
}

char *my_strcpy(char *dest, char *src, int pos, int len_pos)
{
    int i = pos;
    int comp = 0;

    len_pos = len_pos + pos;
    while (i < len_pos && src[i] != ':') {
        dest[comp] = src[i];
        i ++;
        comp ++;
    }
    dest[comp] = '\0';
    return dest;
}

char **convert_to_tab(char **tab_mot, char *buffer, int len_buf)
{
    int comp = 0;
    int comp_1 = 1;
    int len_m = 0;
    int b = len_mot(buffer, 0);

    while(buffer[comp] != '=')
        comp ++;
    comp++;
    tab_mot[0] = malloc(sizeof(char) * (b + 1));
    tab_mot[0] = my_strcpy(tab_mot[0], buffer, comp, b);
    while(comp <= len_buf) {
	if(buffer[comp] == ':') {
            len_m = len_mot(buffer, comp+1);
            tab_mot[comp_1] = malloc(sizeof(char) * len_m + 1);
            tab_mot[comp_1] = my_strcpy(tab_mot[comp_1], buffer, comp + 1, len_m);
            comp_1 ++;
        }
        comp ++;
    }
    return tab_mot;
}

int len_point(char *str)
{
    int result = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == ':')
            result = result + 1;
    }
    return result;
}

char **separ_tab(char *str)
{
    int len_p = len_point(str);
    int len_buf = my_strlen(str);
    char **tab = malloc(sizeof(char*) * (len_p + 1));

    tab[len_p] = NULL;
    tab = convert_to_tab(tab, str, len_buf);

    return tab;
}
