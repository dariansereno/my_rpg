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
    while(is_good == false) {
        if (tab[i]->id == tab[j]->id)
            tab[i]->id = random_between(0, 2);
        if (tab[i]->id != tab[j]->id)
            j++;
        if (j == i)
            is_good = true;
    }
    return (tab);
}

st_ressources **trade(st_global *ad)
{
    bool is_good = false;
    int nb_ressources = random_between(1, 3);
    st_ressources **tab = malloc(sizeof(st_ressources *) * (nb_ressources + 1));
    int j = 0;

    for (int i = 0; i < nb_ressources; i++)
    {
        tab[i] = malloc(sizeof(*tab[i]));
        tab[i]->id = random_between(0, 2);
        j = 0;
        check_double(is_good, tab, i, j);
        tab[i]->price = prices(ad, tab[i]->id);
        tab[i]->nb = stock(ad, tab[i]->id);
    }
    tab[nb_ressources] = malloc(sizeof(st_ressources *));
    tab[nb_ressources]->id = -1;
    tab[nb_ressources]->price = -1;
    return (tab);
}

void generate_trade(st_global *ad)
{
    list_planet pl = ad->planets->planets;

    while (pl != NULL) {
        if (pl->planet.tradable == true)
            pl->trade = trade(ad);
        pl = pl->next;
    }
}