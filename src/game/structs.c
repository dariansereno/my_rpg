/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** structs
*/

#include "my_rpg.h"

paralax_t *paralax_ini(void)
{
    paralax_t *paralax = malloc(sizeof(paralax_t));

    paralax->nebula = sfSprite_create();
    paralax->nebulat = sfTexture_createFromFile("ressources/space.png", NULL);
    paralax->paralaxr = (sfIntRect) {.height = HEIGHT, .left = WIDTH, .top = HEIGHT,
    .width = WIDTH};
    paralax->paralo = sfClock_create();
    paralax->star = sfSprite_create();
    paralax->start = sfTexture_createFromFile("ressources/stars.png", NULL);
    paralax->starr = (sfIntRect) {.height = HEIGHT, .left = WIDTH, .top = HEIGHT,
    .width = WIDTH};
    paralax->staro = sfClock_create();
    paralax->clock = sfClock_create();
    paralax->nebulapos = (sfVector2f) {0, 0};
    paralax->starpos = (sfVector2f) {0, 0};
    paralax->i = 0;
    paralax->j = 0;
    paralax->k = 0;
    paralax->l = 0;
    return (paralax);
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
    window->screen = 4;
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
    return (window);
}

st_game_var *ini_var()
{
    st_game_var *var = malloc(sizeof(*var));

    var->special_atk = false;
    var->range = 15;
    var->speed = 5;
    var->max_health = 200;
    var->attack = 10;
    var->life = 100;
    var->lvl = 0;
    var->max_xp = 100;
    var->price_sett = 3;
    var->xp = 90;
    var->craft = false;
    var->reload_time = 0.18;
    var->quests = 1;
    var->mul_xp = 1.0;
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
    return (var);
}

ship_t *ship_ini(void)
{
    ship_t *ship = malloc(sizeof(ship_t));

    ship->bship = sfSprite_create();
    ship->bshipt = sfTexture_createFromFile("contents/sbr/b0.png", NULL);
    sfSprite_setOrigin(ship->bship, (sfVector2f){22.5, 22.5});
    ship->bshippos = (sfVector2f) {.x = 960, .y = 540};
    ship->viewrect = (sfFloatRect) {.height = HEIGHT, .left = 0, .top = 0,
    .width = WIDTH};
    ship->view = sfView_createFromRect(ship->viewrect);
    ship->reload = malloc(sizeof(*ship->reload));
    ship->reload->clock = sfClock_create();
    ship->collisionZ = false;
    ship->collisionD = false;
    ship->collisionS = false;
    ship->collisionQ = false;
    ship->firstcollisionZ = false;
    ship->firstcollisionD = false;
    ship->firstcollisionS = false;
    ship->firstcollisionQ = false;
    ship->collisionZlim = false;
    ship->collisionDlim = false;
    ship->collisionSlim = false;
    ship->collisionQlim = false;
    ship->firstcollisionZlim = false;
    ship->firstcollisionDlim = false;
    ship->firstcollisionSlim = false;
    ship->firstcollisionQlim = false;
    ship->acceleration = (sfVector2f){0, 0};
    ship->velocity = (sfVector2f){0, 0};
    return (ship);
}

st_global *ini(void)
{
    st_global *all = malloc(sizeof(st_global));

    all->upgrade = generate_upgrade();
    all->window = all_dat();
    all->space_obj = generate_space_obj();
    all->mul_price = 1.0;
    all->paralax = paralax_ini();
    all->ship = ship_ini();
    all->shoot = generate_shoot();
    all->ui = generate_ui();
    all->other = malloc(sizeof(*all->other));
    all->other->planet_text = sfText_create();
    all->other->font = sfFont_createFromFile
    ("contents/fonts/dogica/TTF/dogica.ttf");
    sfText_setFont(all->other->planet_text, all->other->font);
    all->var = malloc(sizeof(*all->var));
    all->var->max_ennemies = 3;
    all->var->drop_cl = my_malloc(sizeof(*all->var->drop_cl));
    all->var->drop_cl->clock = sfClock_create();
    all->enn_texture = enn_textures();
    all->texture = texture_ini();
    all->key = key_ini(all);
    all->enn_damage = 5;
    all->money = money_ini();
    all->win = false;
    all->quest = item_ini();
    all->items = generate_items();
    all->font_inv = sfFont_createFromFile("contents/fonts/Minecraft.ttf");
    all->ressources = generate_inventory(all);
    all->drop = NULL;
    all->var_game = ini_var();
    all->circle = sfCircleShape_create();
    all->big_msg_generated = false;
    all->text = generate_message();
    sfCircleShape_setRadius(all->circle, 500);
    sfCircleShape_setOrigin(all->circle, (sfVector2f){500, 500});
    sfCircleShape_setFillColor(all->circle, sfTransparent);
    sfCircleShape_setOutlineThickness(all->circle, 10);
    return (all);
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