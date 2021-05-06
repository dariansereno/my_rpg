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

    ad->texture->th = my_malloc(sizeof(sfTexture *) * 8);
    key->up = 0;
    key->upleft = 0;
    key->upright = 0;
    key->left = 0;
    key->right = 0;
    key->downright = 0;
    key->downleft = 0;
    key->down = 0;
    ad->texture->th[0] = sfTexture_createFromFile("contents/img/t1.png", NULL);
    ad->texture->th[1] = sfTexture_createFromFile("contents/img/t2.png", NULL);
    ad->texture->th[2] = sfTexture_createFromFile("contents/img/t3.png", NULL);
    ad->texture->th[3] = sfTexture_createFromFile("contents/img/t4.png", NULL);
    ad->texture->th[4] = sfTexture_createFromFile("contents/img/t5.png", NULL);
    ad->texture->th[5] = sfTexture_createFromFile("contents/img/t6.png", NULL);
    ad->texture->th[6] = sfTexture_createFromFile("contents/img/t7.png", NULL);
    ad->texture->th[7] = sfTexture_createFromFile("contents/img/t8.png", NULL);
    return (key);
}

load_t *texture_ini(void)
{
    load_t *texture = my_malloc(sizeof(load_t));

    texture->load = my_malloc(sizeof(sfTexture *) * 8);
    texture->load[0] = sfTexture_createFromFile("contents/sbr/b0.png", NULL);
    texture->load[1] = sfTexture_createFromFile("contents/sbr/b45.png", NULL);
    texture->load[2] = sfTexture_createFromFile("contents/sbr/b90.png", NULL);
    texture->load[3] = sfTexture_createFromFile("contents/sbr/b135.png", NULL);
    texture->load[4] = sfTexture_createFromFile("contents/sbr/b180.png", NULL);
    texture->load[5] = sfTexture_createFromFile("contents/sbr/b225.png", NULL);
    texture->load[6] = sfTexture_createFromFile("contents/sbr/b270.png", NULL);
    texture->load[7] = sfTexture_createFromFile("contents/sbr/b315.png", NULL);
    return (texture);
}

moula_t *money_ini(void)
{
    moula_t *money = malloc(sizeof(moula_t));

    money->money = 10000;
    money->coinpos = (sfVector2f){1700, 50};
    money->moneytext = sfText_create();
    money->moneyfont = sfFont_createFromFile("contents/fonts/myfont.otf");
    money->moneyval = sfText_create();
    return (money);
}

items_t *item_ini(void)
{
    items_t *items = malloc(sizeof(items_t));

    items->ingot = sfSprite_create();
    items->bm = sfSprite_create();
    items->crystal = sfSprite_create();
    items->ingott = sfTexture_createFromFile("contents/ui/items/space_ingot.png"
    , NULL);
    items->crystalt = sfTexture_createFromFile
    ("contents/ui/items/crystal_01j.png", NULL);
    items->bmt = sfTexture_createFromFile("contents/ui/items/black_matter.png",
    NULL);
    sfSprite_setScale(items->bm, (sfVector2f){0.22, 0.22});
    sfSprite_setScale(items->crystal, (sfVector2f){1.1, 1.1});
    sfSprite_setScale(items->ingot, (sfVector2f){0.25, 0.25});
    return (items);
}