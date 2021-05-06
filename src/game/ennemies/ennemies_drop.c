/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** ennemies_drop
*/

#include "my_rpg.h"

int drop_id(st_global *ad)
{
    int rand = random_between(0, 10);

    if (rand <= 7)
        return (0);
    if (rand > 7)
        return (1);
}

void drop_money(st_global *ad, list_ennemies en)
{
    st_drop drop;
    drop.xp = random_xp();
    drop.amount = random_money();

    drop.mode = 1;
    drop.pos = (sfVector2f){en->ennemies.pos.x + 10, en->ennemies.pos.y};
    ad->money->money += drop.amount;
    ad->var_game->xp += drop.xp;
    push_back_drop(&ad->drop, drop);
}

void drop_ressources(st_global *ad, list_ennemies en)
{
    st_drop drop;
    drop.id = random_ressources();
    drop.nb = random_nb_ressources();
    drop.xp = random_xp();

    ad->ressources[drop.id].nb += drop.nb;
    drop.mode = 0;
    ad->var_game->xp += drop.xp;
    drop.pos = (sfVector2f){en->ennemies.pos.x + 10, en->ennemies.pos.y};
    push_back_drop(&ad->drop, drop);
}

void drop(st_global *ad, list_ennemies en)
{
    int rand = random_between(0, 10);
    int drop = drop_id(ad);

    if (drop)
        drop_ressources(ad, en);
    else
        drop_money(ad, en);
}