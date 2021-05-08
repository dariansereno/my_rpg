/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** boss_atk
*/

#include "my_rpg.h"

int random_piped_five(void)
{
    int rand = random_between(1, 25);
    int x = 0;

    switch (x) {
    case 0:
        if (rand <= 6)
            return (1);
        x++;
    case 1:
        if (rand > 6 && rand <= 12)
            return (2);
        x++;
    case 2:
        if (rand > 12 && rand <= 18)
            return (3);
        x++;
    case 3:
        if (rand > 18 && rand <= 24)
            return (4);
        x++;
    case 4:
        if (rand > 24)
            return (5);
        x++;
    }
}

void boss_atk(st_global *ad)
{
    if (!ad->var_game->boss_generated)
        return;
    sfTime time;
    float second;

    time = sfClock_getElapsedTime(ad->boss->atk_timer->clock);
    second = time.microseconds / 1000000.0;
    if (second > 1) {
        push_back_boss(&ad->boss->atk_li, random_between(3, 6),
        random_piped_five());
        sfClock_restart(ad->boss->atk_timer->clock);
    }
}