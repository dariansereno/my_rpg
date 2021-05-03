/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** int_to_str
*/

#include "my_rpg.h"

int nb_len(int nb)
{
    int i = 0;

    if (nb == 0)
        return (1);
    while (nb > 0) {
        i++;
        nb /= 10;
    }
    return (i);
}

char *int_to_str(int nb)
{
    char *result = my_malloc(sizeof(char) * (nb_len(nb) + 1));
    int i = 0;

    if (nb == 0)
        return ("0");
    while (nb > 0) {
        result[i] = (nb % 10) + '0';
        nb /= 10;
        i++;
    }
    result[i] = 0;
    my_revstr(result);
    return (result);
}