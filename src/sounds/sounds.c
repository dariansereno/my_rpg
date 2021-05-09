/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** sounds
*/

#include "my_rpg.h"

st_global_sfx *generate_sound_2(st_global_sfx *sound)
{
    sound->buff_explo = \
    sfSoundBuffer_createFromFile("contents/sounds/explo.wav");
    sound->explo = sfSound_create();
    sfSound_setBuffer(sound->explo, sound->buff_explo);
    sfSound_setVolume(sound->explo, 100);
    sound->buff_big_explo = \
    sfSoundBuffer_createFromFile("contents/sounds/big_explo.wav");
    sound->big_explo = sfSound_create();
    sfSound_setBuffer(sound->big_explo, sound->buff_big_explo);
    sfSound_setVolume(sound->big_explo, 100);
    return (sound);
}

st_global_sfx *generate_sound(void)
{
    st_global_sfx *sound = my_malloc(sizeof(*sound));

    sound->buff_click_vol = \
    sfSoundBuffer_createFromFile("contents/sounds/clicked.ogg");
    sound->click_vol = sfSound_create();
    sfSound_setBuffer(sound->click_vol, sound->buff_click_vol);
    sfSound_setVolume(sound->click_vol, 100);
    sound->buff_shoot = \
    sfSoundBuffer_createFromFile("contents/sounds/tir.ogg");
    sound->shoot = sfSound_create();
    sfSound_setBuffer(sound->shoot, sound->buff_shoot);
    sfSound_setVolume(sound->shoot, 100);
    return (generate_sound_2(sound));
}

void set_volume_sfx(st_global *g, float volume)
{
    sfSound_setVolume(g->window->sfx->click_vol, volume);
    sfSound_setVolume(g->window->sfx->shoot, volume);
    sfSound_setVolume(g->window->sfx->explo, volume);
    sfSound_setVolume(g->window->sfx->big_explo, volume);
}

void destroy_sound(st_global_sfx *sound)
{
    sfSound_destroy(sound->click_vol);
    sfSoundBuffer_destroy(sound->buff_click_vol);
    sfSound_destroy(sound->shoot);
    sfSoundBuffer_destroy(sound->buff_shoot);
    sfSound_destroy(sound->explo);
    sfSoundBuffer_destroy(sound->buff_explo);
    sfSound_destroy(sound->big_explo);
    sfSoundBuffer_destroy(sound->buff_big_explo);
}