/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_shoot
*/

#include "my_rpg.h"

sfSprite **generate_enn_shoot()
{
    sfTexture **tex = malloc(sizeof(sfTexture *) * 8);
    sfSprite **spr = malloc(sizeof(sfSprite *) * 8);

    tex[0] = sfTexture_createFromFile("contents/ships/proj/prt.png", NULL);
    tex[1] = sfTexture_createFromFile("contents/ships/proj/prtr.png", NULL);
    tex[2] = sfTexture_createFromFile("contents/ships/proj/prr.png", NULL);
    tex[3] = sfTexture_createFromFile("contents/ships/proj/prdr.png", NULL);
    tex[4] = sfTexture_createFromFile("contents/ships/proj/prd.png", NULL);
    tex[5] = sfTexture_createFromFile("contents/ships/proj/prdl.png", NULL);
    tex[6] = sfTexture_createFromFile("contents/ships/proj/prl.png", NULL);
    tex[7] = sfTexture_createFromFile("contents/ships/proj/prtl.png", NULL);
    for (int i = 0; i < 8; i++) {
        spr[i] = sfSprite_create();
        sfSprite_setTexture(spr[i], tex[i], sfTrue);
        sfSprite_setOrigin(spr[i], (sfVector2f){16, 16});
    }
    return (spr);
}

sfSprite **generate_ship_shoot()
{
    sfTexture **tex = malloc(sizeof(sfTexture *) * 8);
    sfSprite **spr = malloc(sizeof(sfSprite *) * 8);

    tex[0] = sfTexture_createFromFile("contents/ships/proj/pbt.png", NULL);
    tex[1] = sfTexture_createFromFile("contents/ships/proj/pbtr.png", NULL);
    tex[2] = sfTexture_createFromFile("contents/ships/proj/pbr.png", NULL);
    tex[3] = sfTexture_createFromFile("contents/ships/proj/pbdr.png", NULL);
    tex[4] = sfTexture_createFromFile("contents/ships/proj/pbd.png", NULL);
    tex[5] = sfTexture_createFromFile("contents/ships/proj/pbdl.png", NULL);
    tex[6] = sfTexture_createFromFile("contents/ships/proj/pbl.png", NULL);
    tex[7] = sfTexture_createFromFile("contents/ships/proj/pbtl.png", NULL);
    for (int i = 0; i < 8; i++) {
        spr[i] = sfSprite_create();
        sfSprite_setTexture(spr[i], tex[i], sfTrue);
        sfSprite_setOrigin(spr[i], (sfVector2f){16, 16});
    }
    return (spr);
}

st_global_shoot *generate_shoot()
{
    st_global_shoot *shoot = malloc(sizeof(*shoot));
    sfTexture *texture = sfTexture_createFromFile(
    "contents/ships/explo/sps.png", NULL);

    shoot->li_shoot = NULL;
    shoot->li_explo = NULL;
    shoot->explo_sp = sfSprite_create();
    shoot->explo_rect = (sfIntRect){.height = 46, .width = 46, .left = 0,
    .top = 0};
    sfSprite_setTexture(shoot->explo_sp, texture, sfTrue);
    shoot->explo_tmr = malloc(sizeof(*shoot->explo_tmr));
    shoot->explo_tmr->clock = sfClock_create();
    shoot->sprite_ship = generate_ship_shoot();
    shoot->sprite_enn = generate_enn_shoot();
    return (shoot);
}