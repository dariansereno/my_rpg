/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** ennemies_generation
*/

#include "my_rpg.h"

sfTexture **enn_textures(void)
{
    sfTexture **textures = my_malloc(sizeof(sfTexture *) * 8);

    textures[0] = sfTexture_createFromFile("contents/sbr/et.png", NULL);
    textures[1] = sfTexture_createFromFile("contents/sbr/etr.png", NULL);
    textures[2] = sfTexture_createFromFile("contents/sbr/er.png", NULL);
    textures[3] = sfTexture_createFromFile("contents/sbr/edr.png", NULL);
    textures[4] = sfTexture_createFromFile("contents/sbr/ed.png", NULL);
    textures[5] = sfTexture_createFromFile("contents/sbr/edl.png", NULL);
    textures[6] = sfTexture_createFromFile("contents/sbr/el.png", NULL);
    textures[7] = sfTexture_createFromFile("contents/sbr/etl.png", NULL);
    return (textures);
}

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
    sfSprite_setTexture(ennemies.sprite, ad->enn_texture[0], sfTrue);
    return (ennemies);
}

void clock_ennemies_generation(list_planet li, st_global *ad)
{
    st_ennemies *ennemies;

    li->spawning.time = sfClock_getElapsedTime(li->spawning.clock);
    li->spawning.seconds = li->spawning.time.microseconds / 1000000.0;
    if (li->spawning.seconds > li->ennemies_spawn) {
        push_back_ennemies(&li->planet.ennemies, generate_ennemies(ad, li));
        sfClock_restart(li->spawning.clock);
    }
}

void ennemies_spawning(st_global *ad)
{
    list_planet li = ad->planets->planets;

    while (li != NULL) {
        if (li->on_screen == true && li->planet.kind == TECH &&
        size_list_ennemies(li->planet.ennemies) < ad->var->max_ennemies
        && li->size == 2)
            clock_ennemies_generation(li, ad);
        if (li->on_screen == false && li->planet.kind == TECH
        && li->size == 2)
            sfClock_restart(li->spawning.clock);
        li = li->next;
    }
}