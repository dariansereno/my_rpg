/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** attack_4
*/

#include "my_rpg.h"

sfVector2f position_generate_boss(st_global *ad, sfVector2f pos, float radius)
{
    float angle = 0;
    float x = 0;
    float y = 0;

    angle = ((float)rand()/(float)(RAND_MAX/1)) * M_PI * 2;
    x = cos(angle) * radius + (float)pos.x;
    y = sin(angle) * radius + (float)pos.y;

    return ((sfVector2f){x, y});
}

st_ennemies generate_ennemies_boss(st_global *ad)
{
    st_ennemies ennemies;

    ennemies.pos = position_generate_boss(ad, ad->boss->boss->pos,
    random_between(240, 300));
    ennemies.rect = (sfIntRect){0, 0, 48, 48};
    ennemies.sprite = sfSprite_create();
    sfSprite_setTexture(ennemies.sprite, ad->enn_texture[0], sfTrue);
    return (ennemies);
}

void attack_4_contains(st_global *ad, float second, float second_s)
{
    if (second < ad->boss->current->duration &&
    size_list_ennemies(ad->boss->enn) < 15) {
        if (second_s > 1) {
            push_back_ennemies(&ad->boss->enn, generate_ennemies_boss(ad));
            sfClock_restart(ad->boss->reload);
        }
    }
    else  {
        sfClock_restart(ad->boss->clock->clock);
        ad->boss->current = NULL;
    }
}

void attack_4(st_global *ad)
{
    sfTime time;
    float second;
    sfTime time_s;
    float second_s;

    if (ad->boss->current == NULL || ad->boss->current->type != 4)
        return;
    time = sfClock_getElapsedTime(ad->boss->current->time->clock);
    second = time.microseconds / 1000000.0;
    time_s = sfClock_getElapsedTime(ad->boss->reload);
    second_s = time_s.microseconds / 1000000.0;
    attack_4_contains(ad, second, second_s);
}