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

    sound->buff_click_vol = \
    sfSoundBuffer_createFromFile("contents/sounds/clicked.ogg");
    sound->click_vol = sfSound_create();
    sfSound_setBuffer(sound->click_vol, sound->buff_click_vol);
    sfSound_setVolume(sound->click_vol, 100);
    return (sound);
}

void set_volume_sfx(st_global *g, float volume)
{
    sfSound_setVolume(g->window->sfx->click_vol, volume);
}

void destroy_sound(st_global_sfx *sound)
{
    sfSoundBuffer_destroy(sound->click_vol);
    sfSound_destroy(sound->click_vol);
}