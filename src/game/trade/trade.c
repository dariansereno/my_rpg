/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** trade
*/

#include "my_rpg.h"

int prices(st_global *ad, int id)
{
    int price = 0;

    if (id == 0)
        price = random_between(20, 40);
    if (id == 1)
        price = random_between(30, 50);
    if (id == 2)
        price = random_between(75, 100);
    return (price);
}

int stock(st_global *ad, int id)
{
    int stock = 0;

    if (id == 0)
        stock = random_between(1, 5);
    if (id == 1)
        stock = random_between(1, 3);
    if (id == 2)
        stock = 1;
    return (stock);
}

st_ressources **check_double(bool is_good, st_ressources **tab, int i, int j)
{
    while (is_good == false) {
        if (tab[i]->id == tab[j]->id)
            tab[i]->id = random_between(0, 2);
        if (tab[i]->id != tab[j]->id)
            j++;
        if (j == i)
            is_good = true;
    }
    return (tab);
}

void fill_tab_ressources(st_global *ad, int nb_ressources, st_ressources **tab)
{
    bool is_good = false;
    int i = 0;
    int j = 0;

    for (i = 0; i < nb_ressources; i++)
    {
        tab[i] = my_malloc(sizeof(*tab[i]));
        tab[i]->id = random_between(0, 2);
        j = 0;
        check_double(is_good, tab, i, j);
        tab[i]->price = prices(ad, tab[i]->id);
        tab[i]->nb = stock(ad, tab[i]->id);
    }
    for (; i < 4 - nb_ressources; i++) {
        tab[i] = my_malloc(sizeof(*tab[i]));
        tab[i]->id = -1;
        tab[i]->price = -1;
    }
}

st_ressources **trade(st_global *ad)
{
    int nb_ressources = random_between(1, 3);
    st_ressources **tab = my_malloc(sizeof(st_ressources *) * (4));
    int j = 0;

    fill_tab_ressources(ad, nb_ressources, tab);
    tab[nb_ressources] = malloc(sizeof(*tab[nb_ressources]));
    tab[nb_ressources]->id = -1;
    tab[nb_ressources]->price = -1;
    return (tab);
}