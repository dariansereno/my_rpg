/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** random_drop
*/

#include "my_rpg.h"

int random_money(void)
{
    int rand = random_between(0, 10);

    if (rand < 5)
        return (random_between(10, 50));
    else if (rand >= 5 && rand <= 8)
        return (random_between(50, 100));
    else
        return (random_between(100, 150));
}

int random_ressources(void)
{
    int rand = random_between(0, 10);

    if (rand < 6)
        return (0);
    else if (rand >= 6 && rand < 9)
        return (1);
    else
        return (2);
}

int random_nb_ressources(void)
{
    int rand = random_between(0, 10);

    if (rand < 8)
        return (1);
    else if (rand >= 8 && rand <= 9)
        return (2);
    else
        return (3);
}

int random_xp(st_global *ad)
{
    int rand = random_between(0, 10);
    int res = 0;

    if (rand < 7){
        res = (int)(random_between(5, 10) * ad->var_game->mul_xp);
        return (res);
    }
    else if (rand >= 7 && rand <= 9) {
        res = (int)(random_between(10, 15) * ad->var_game->mul_xp);
        return (res);
    }
    else {
        res = (int)(random_between(15, 25) * ad->var_game->mul_xp);
        return (res);
    }
}