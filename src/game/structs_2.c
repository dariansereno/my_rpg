/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** structs_2
*/

#include "my_rpg.h"

void all_dat_2(structs_t *window)
{
    window->music_volume = 100.0;
    window->width_volume_pause = 253;
    window->width_volume = 506;
    window->sfx_volume = 100;
    window->width_sfx_pause = 253;
    window->width_sfx = 506;
    window->bool_load = true;
    window->bool_game = true;
    window->bool_menu = true;
    window->sfx = generate_sound();
}

structs_t *all_dat(void)
{
    structs_t *window = malloc(sizeof(structs_t));

    window->mode.width = WIDTH;
    window->mode.height = HEIGHT;
    window->mode.bitsPerPixel = 32;
    window->window = sfRenderWindow_create(window->mode, "my_rpg",
    sfTitlebar | sfClose, NULL);
    sfRenderWindow_setPosition(window->window, \
    (sfVector2i){(sfVideoMode_getDesktopMode().width / 2) - \
    (window->mode.width / 2), ((sfVideoMode_getDesktopMode().height / 2) - \
    (window->mode.height / 2))});
    window->music = sfMusic_createFromFile("ressources/loop.ogg");
    window->screen = 1;
    all_dat_2(window);
    return (window);
}

void ini_var_2(st_game_var *var)
{
    var->is_boss = true;
    var->boss_generated = false;
    var->created = false;
    var->msg = false;
    var->msg2 = false;
    var->kills = 0;
    var->quest2_completed = false;
    var->msg3 = false;
    var->quest3_completed = false;
    var->msg4 = false;
    var->quest4_completed = false;
    var->msg5 = false;
    var->quest5_completed = false;
    var->msg6 = false;
    var->quest6_completed = false;
    var->destroy_boss = false;
}

st_game_var *ini_var(void)
{
    st_game_var *var = malloc(sizeof(*var));

    var->special_atk = false;
    var->range = 30;
    var->speed = 5;
    var->max_health = 200;
    var->attack = 10;
    var->life = 200;
    var->max_money = 10000;
    var->lvl = 0;
    var->max_xp = 100;
    var->price_sett = 3;
    var->xp = 90;
    var->craft = false;
    var->reload_time = 0.18;
    var->quests = 1;
    var->mul_xp = 1.0;
    ini_var_2(var);
    return (var);
}

void destroy_global(st_global *global)
{
    sfMusic_destroy(global->window->music);
    destroy_ui(global->ui);
    destroy_global_planet(global->planets);
    if (global->var_game->boss_generated)
        destroy_boss_fight(global);
    destroy_sound(global->window->sfx);
    destroy_message(global);
    global = NULL;
}