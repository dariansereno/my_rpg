/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** additionnal_msg
*/

#include "my_rpg.h"

int backslash_n_counter(st_global *global)
{
    int j = 0;

    for (int i = 0; global->text->str[i]; i++)
        if (global->text->str[i] == '\n')
            j++;
    return (j);
}

char *cpy_to_up_text(st_global *g)
{
    int j = 0;
    char *result = NULL;

    for (int i = 0; g->text->str[i]; i++) {
        if (g->text->str[i] == '\n')
            j++;
        if (j == 3) {
            result = \
            my_malloc(sizeof(char) * (my_strlen(g->text->str) - i + 1));
            my_strncpy(result, g->text->str + i + 1, \
            my_strlen(g->text->str) - i);
            result[my_strlen(g->text->str) - i] = 0;
            return (result);
        }
    }
    return (NULL);
}