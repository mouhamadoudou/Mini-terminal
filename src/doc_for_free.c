/*
** EPITECH PROJECT, 2022
** for freee malloc
** File description:
** for freee malloc
*/

#include "../include/my.h"

void free_array(char **tab, int check, int check2)
{
    for (int a = 0; a < 6; a++) {
        if (a != check2)
            free(tab[a]);
    }
    if (check == 1)
        free(tab);
}

void free_array_2(char **tab, int check)
{
    for (int a = 0; tab[a] != NULL; a++)
        free(tab[a]);
    if (check == 1)
	free(tab);
}
