/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** sounds
*/

#include "my_rpg.h"

st_global_sfx *generate_sound(void)
{
    st_global_sfx *sound = my_malloc(sizeof(*sound));

    sound->buff_explosion = \
    sfSoundBuffer_createFromFile("contents/sounds/test.ogg");
    sound->explosion = sfSound_create();
    sfSound_setBuffer(sound->explosion, sound->buff_explosion);
    sfSound_setVolume(sound->explosion, 100);
    return (sound);
}

void set_volume_sfx(st_global *g, float volume)
{
    sfSound_setVolume(g->window->sfx->explosion, volume);
}

void destroy_sound(st_global_sfx *sound)
{
    sfSound_destroy(sound->explosion);
    sfSoundBuffer_destroy(sound->buff_explosion);
}