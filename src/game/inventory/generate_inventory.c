/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_inventory
*/

#include "my_rpg.h"

st_object **generate_items()
{
    st_object **items = my_malloc(sizeof(**items) * 4);

    items[0] = generate_object((sfVector2f){0, 0}, (sfIntRect){0, 0, 199, 208}, 
    "contents/ui/items/black_matter.png");
    sfSprite_setScale(items[0]->sprite, (sfVector2f){0.22, 0.22});
    items[1] = generate_object((sfVector2f){0, 0}, (sfIntRect){0, 0, 35, 44},
    "contents/ui/items/space_ingot.png");
    items[2] = generate_object((sfVector2f){0, 0}, (sfIntRect){0, 0, 32, 32},
    "contents/ui/items/crystal_01j.png");
    sfSprite_setOrigin(items[2]->sprite, (sfVector2f){0, -3});
    sfSprite_setScale(items[2]->sprite, (sfVector2f){1.1, 1.1});
    items[3] = generate_object((sfVector2f){0, 0}, (sfIntRect){0, 0, 128, 138},
    "contents/ui/items/houseitem.png");
    sfSprite_setScale(items[3]->sprite, (sfVector2f){0.25, 0.25});
    sfSprite_setOrigin(items[3]->sprite, (sfVector2f){0, -6});
    return (items);
}

st_ressources generate_ressource(int id, st_global *ad)
{
    st_ressources res;
    
    res.id = id;
    res.nb = 0;
    res.stack = 32;
    res.text = sfText_create();
    sfText_setFont(res.text, ad->font_inv);
    sfText_setCharacterSize(res.text, 25);
    return (res);
}

st_ressources *generate_inventory(st_global *ad)
{
    st_ressources *inv = malloc(sizeof(*inv) * 4);
    ad->nb_inv = malloc(sizeof(char) * 10);

    inv[0] = generate_ressource(0, ad);
    inv[0].nb = 7;
    inv[1] = generate_ressource(1, ad);
    inv[1].nb = 7;
    inv[2] = generate_ressource(2, ad);
    inv[2].nb = 7;
    inv[3] = generate_ressource(3, ad);
    return (inv);
}