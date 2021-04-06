/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** ennemies_generation
*/

#include "my_rpg.h"

sfVector2f position_generate_near_planet(list_planet planet, st_global *ad,
float radius)
{
    float angle = 0;
    float x = 0;
    float y = 0;

    do {
    angle = ((float)rand()/(float)(RAND_MAX/1)) * M_PI * 2;
    x = cos(angle) * radius + (float)planet->planet.pos.x;
    y = sin(angle) * radius + (float)planet->planet.pos.y;
    } while (is_on_planet(ad, (sfVector2f){x, y}) && is_on_ennemies(ad,
    planet->planet.ennemies, (sfVector2f){x, y}));

    return ((sfVector2f){x, y});
}

st_ennemies generate_ennemies(st_global *ad, list_planet planet)
{
    st_ennemies ennemies;
    
    ennemies.pos = position_generate_near_planet(planet, ad,
    random_between(170, 260));
    ennemies.rect = (sfIntRect){0, 0, 48, 48};
    ennemies.sprite = sfSprite_create();
    sfSprite_setTexture(ennemies.sprite, ad->enn_texture, NULL);
    return (ennemies);
}

void clock_ennemies_generation(list_planet li, st_global *ad)
{
    st_ennemies *ennemies;

    li->spawning.time = sfClock_getElapsedTime(li->spawning.clock);
    li->spawning.seconds = li->spawning.time.microseconds / 1000000.0;
    if (li->spawning.seconds > li->ennemies_spawn) {
        push_back_ennemies(&li->planet.ennemies, generate_ennemies(ad, li));
        print_ennemies_list_pos(li->planet.ennemies);
        sfClock_restart(li->spawning.clock);
    }
}

void ennemies_spawning(st_global *ad)
{
    list_planet li = ad->planets->planets;

    while (li != NULL) {
        if (li->on_screen == true && li->planet.kind == TECH &&
        size_list_ennemies(li->planet.ennemies) < ad->var->max_ennemies)
            clock_ennemies_generation(li, ad);
        if (li->on_screen == false && li->planet.kind == TECH)
            sfClock_restart(li->spawning.clock);
        li = li->next;
    }
}