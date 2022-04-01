/*
** EPITECH PROJECT, 2022
** lib.c
** File description:
** lib.c
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int decompteur = 1;
    int compteur = 1;

    while ( str[decompteur] != '\0'){
        compteur = compteur + 1;
        decompteur = decompteur + 1;
    }
    return (compteur);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int  decompteur = 0;

    while (str[decompteur] != '\0') {
        my_putchar(str[decompteur]);
        decompteur = decompteur + 1;
    }
    return (0);
}
