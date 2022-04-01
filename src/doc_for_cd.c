²/*
** EPITECH PROJECT, 2022
** cd
** File description:
** cd doc
*/

#include "../include/my.h"

char *find_path(char *buffer)
{
    int a = 0;
    int len = my_strlen(buffer);
    char *str = NULL;

    if (len < 4)
        return buffer;
    str = malloc(sizeof(char) * (len + 1));
    while(buffer[a] != ' ')
	a++;
    a++;
    for(int i = 0; buffer[a] != '\n' && buffer[a] != '\0'; i++) {
        str[i] = buffer[a];
	a++;
        str[i+1] = '\0';
    }
    return str;
}

void my_cd(char *path)
{
    path = find_path(path);
    if (chdir(path) == -1)
        my_putstr("cd: flekhf: No such file or directory\n");
    free(path);
}
