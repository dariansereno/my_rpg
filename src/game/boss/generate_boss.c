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

void generate_boss_fight_4(st_global *ad, st_boss *boss)
{
    boss->outline = sfRectangleShape_create();
    boss->duration = my_malloc(sizeof(*boss->duration));
    boss->duration->clock = sfClock_create();
    sfRectangleShape_setSize(boss->life, (sfVector2f){400, 10});
    sfRectangleShape_setSize(boss->outline, (sfVector2f){400, 10});
    sfRectangleShape_setPosition(boss->life, (sfVector2f){500, 10});
    sfRectangleShape_setPosition(boss->outline, (sfVector2f){500, 10});
    sfRectangleShape_setFillColor(boss->life, sfRed);
    sfRectangleShape_setOutlineColor(boss->outline, \
    sfColor_fromRGB(179, 130, 188));
    sfRectangleShape_setOutlineThickness(boss->outline, 6);
    sfRectangleShape_setFillColor(boss->outline, sfTransparent);
}

void generate_boss_fight_3(st_global *ad, st_boss *boss)
{
    boss->shield = false;
    boss->incr_speed_atk = 0.5;
    boss->red = false;
    boss->take_dmg = 1;
    boss->shield_sp = sfSprite_create();
    boss->shield_tex = sfTexture_createFromFile("ressources/boss_shield.png",
    NULL);
    sfSprite_setTexture(boss->shield_sp, boss->shield_tex, sfTrue);
    boss->red_sp = sfSprite_create();
    boss->damage = 30;
    boss->red_tex = sfTexture_createFromFile("ressources/bossred.png", NULL);
    sfSprite_setTexture(boss->red_sp, boss->red_tex, sfTrue);
    boss->li_big_explo = NULL;
    boss->li_lil_explo = NULL;
    boss->is_die = false;
    boss->big_explo = false;
    boss->lil_explo = false;
    boss->it = 0;
    boss->life = sfRectangleShape_create();
    generate_boss_fight_4(ad, boss);
}

void generate_boss_fight_2(st_global *ad, st_boss *boss)
{
    boss->decr_speed_atk = 1;
    boss->mid_decr_speed_atk = 0.5;
    boss->mid_incr_speed_atk = 0.5;
    boss->enn = NULL;
    boss->shoot = NULL;
    boss->reload = sfClock_create();
    boss->reload_normal = 0.5;
    boss->reload_fast_atk = 0.1;
    boss->shoot = NULL;
    boss->clock_g = sfClock_create();
    boss->sprite = sfSprite_create();
    boss->texture = sfTexture_createFromFile("ressources/boss_pr.png", NULL);
    sfSprite_setTexture(boss->sprite, boss->texture, sfTrue);
    boss->shake = 4;
    boss->radius = 240;
    boss->circle = true;
    generate_boss_fight_3(ad, boss);
}

st_boss *generate_boss_fight(st_global *ad)
{
    st_boss *boss = my_malloc(sizeof(*boss));
    sfVector2f pos = boss_spawning(ad);

    pos = ad->ship->bshippos;
    pos.x += 400;
    boss->life_f = 10;
    boss->boss = generate_object(pos, (sfIntRect){0, 0, 48, 48},
    "contents/img/sp/boss.png");
    boss->atk_mode = 0;
    boss->bg = generate_object(pos, (sfIntRect){0, 0, 960, 540},
    "ressources/bossbg.png");
    boss->atk_li = NULL;
    boss->current = NULL;
    boss->radius_col = 255;
    boss->clock = my_malloc(sizeof(*boss->clock));
    boss->clock->clock = sfClock_create();
    boss->atk_timer = my_malloc(sizeof(*boss->atk_timer));
    boss->atk_timer->clock = sfClock_create();
    generate_boss_fight_2(ad, boss);
    return (boss);
}
