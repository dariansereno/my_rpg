/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** structs
*/

#include "my_rpg.h"

void ship_ini_2(ship_t *ship)
{
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
    generate_paths(ship);
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
    ship_ini_2(ship);
    return (ship);
}

void ini_3(st_global *all)
{
    all->var_game = ini_var();
    all->circle = sfCircleShape_create();
    all->big_msg_generated = false;
    all->text = generate_message();
    sfCircleShape_setRadius(all->circle, 500);
    sfCircleShape_setOrigin(all->circle, (sfVector2f){500, 500});
    sfCircleShape_setFillColor(all->circle, sfTransparent);
    sfCircleShape_setOutlineThickness(all->circle, 10);
    all->circle_health;
    all->circle_health = sfCircleShape_create();
    all->particle = generate_particle();
    sfCircleShape_setRadius(all->circle_health, 500);
    sfCircleShape_setOrigin(all->circle_health, (sfVector2f){500, 500});
    sfCircleShape_setFillColor(all->circle_health, sfTransparent);
    sfCircleShape_setOutlineThickness(all->circle_health, 10);
}

void ini_2(st_global *all)
{
    generate_key_pressed(all);
    generate_last_key_pressed(all);
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
    ini_3(all);
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
    ini_2(all);
    return (all);
}