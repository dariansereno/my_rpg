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

    while (nb != 0) {
        i++;
        nb /= 10;
    }
    return (i);
}

char *int_to_str(int nb)
{
    char *result = malloc(sizeof(char) * (nb_len(nb) + 1));
    int nb_res = 0;
    int i = 0;

    while (nb != 0) {
        nb_res = nb_res * 10 + (nb % 10);
        nb /= 10;
    }
    while (nb_res != 0) {
        result[i] = (nb_res % 10) + '0';
        nb_res /= 10;
        i++;
    }
    result[i] = '\0';
    return (result);
}