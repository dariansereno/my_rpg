/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_boss
*/

#include "my_rpg.h"

sfVector2f boss_spawning(st_global *ad)
{
    sfVector2f pos = {0, 0};
    bool is_good = false;

    while (!is_good) {
        pos.x = (float)random_between(0, 80000);
        pos.y = (float)random_between(0, 80000);
        if (!(is_on_planet(ad, pos)))
            is_good = true;
    }
    return (pos);
}

st_boss *generate_boss_fight(st_global *ad)
{
    st_boss *boss = my_malloc(sizeof(*boss));
    sfVector2f pos = boss_spawning(ad);
    pos = ad->ship->bshippos;

    boss->life_f = 10000;
    boss->boss = generate_object(pos, (sfIntRect){0, 0, 48, 48},
    "contents/img/sp/boss.png");
    boss->atk_mode = 0;
    boss->bg = generate_object(pos, (sfIntRect){0, 0, 960, 540}, 
    "ressources/bossbg.png");
    boss->atk_li = NULL;
    boss->current = NULL;
    boss->clock = malloc(sizeof(*boss->clock));
    boss->clock->clock = sfClock_create();
    boss->atk_timer = malloc(sizeof(*boss->atk_timer));
    boss->atk_timer->clock = sfClock_create();
    boss->shoot = NULL;
    boss->reload = sfClock_create();
    boss->reload_normal = 0.5;
    boss->reload_fast_atk = 0.1;
    boss->shoot = NULL;
    boss->sprite = sfSprite_create();
    boss->texture = sfTexture_createFromFile("ressources/boss_pr.png", NULL);
    sfSprite_setTexture(boss->sprite, boss->texture, sfTrue);
    boss->shake = 4;
    boss->radius = 240;
    boss->circle = true;
    boss->red_sp = sfSprite_create();
    boss->red_tex = sfTexture_createFromFile("ressources/bossred.png", NULL);
    return (boss);
}
