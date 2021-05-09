/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** structs
*/

#include "my_rpg.h"

keys_t *key_ini(st_global *ad)
{
    keys_t *key = my_malloc(sizeof(keys_t));

    ad->texture->th =  sfTexture_createFromFile("contents/img/t1.png", NULL);
    key->up = 0;
    key->upleft = 0;
    key->upright = 0;
    key->left = 0;
    key->right = 0;
    key->downright = 0;
    key->downleft = 0;
    key->down = 0;
    return (key);
}

load_t *texture_ini(void)
{
    load_t *texture = my_malloc(sizeof(load_t));

    texture->load = sfTexture_createFromFile("contents/sbr/b0.png", NULL);
    return (texture);
}

moula_t *money_ini(void)
{
    moula_t *money = my_malloc(sizeof(moula_t));

    money->money = 100;
    money->coinpos = (sfVector2f){1700, 50};
    money->moneytext = sfText_create();
    money->moneyfont = sfFont_createFromFile("contents/fonts/myfont.otf");
    money->moneyval = sfText_create();
    return (money);
}

quest_t *item_ini(void)
{
    quest_t *quest = my_malloc(sizeof(quest_t));

    quest->quest_advancement = sfText_create();
    quest->is_on_quest = false;
    return (quest);
}