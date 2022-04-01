/*
** EPITECH PROJECT, 2022
** find bin & my_env
** File description:
** find bin & my_env
*/

#include "../include/my.h"

char *find_opt(char *buffer, char **env)
{
    int check = 0;
    int pos_path = path(env);
    char **tab = NULL;
    int check_name = test_chack(buffer);

    if (pos_path == -1)
        tab = separ_tab("PATH=/usr/local/bin:/usr/bin:/bin:/home/nmouhamadou/bin:/usr/local/sbin:/usr/sbin:/var/lib/snapd/snap/bin");
    if (pos_path != -1)
        tab = separ_tab(env[pos_path]);
    if (check_name == -1) {
        free_array(tab, 1, -1);
	return "NO";
    }
    for (int i = 0; i < 6; i++) {
        tab[i] = concat(tab[i], buffer);
        check = access(tab[i], F_OK);
        if (check == 0) {
            return tab[i];
        }
    }
    return "NO";
}

void my_env(char **env, st_env *set_env)
{
    if (set_env->check == 0) {
        for (int i = 0; env[i] != NULL; i++) {
            my_putstr(env[i]);
            my_putchar('\n');
        }
    }
    if (set_env->check == 1) {
        for (int a = 0; set_env->eenv[a] != NULL; a++) {
            my_putstr(set_env->eenv[a]);
            my_putchar('\n');
        }
    }
}
