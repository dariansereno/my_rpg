/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generates_planets_textures
*/

#include "my_rpg.h"

sfTexture **generates_planets_textures3(sfTexture **texture)
{
    texture[28] = sfTexture_createFromFile("contents/img/sp/ast5.png", NULL);
    texture[29] = sfTexture_createFromFile("contents/img/sp/bh1.png", NULL);
    texture[30] = sfTexture_createFromFile("contents/img/sp/bh2.png", NULL);
    texture[31] = sfTexture_createFromFile("contents/img/sp/bh3.png", NULL);
    return (texture);
}

sfTexture **generates_planets_textures2(sfTexture **texture)
{
    texture[16] = sfTexture_createFromFile("contents/img/sp/terran_nc1.png",
    NULL);
    texture[17] = sfTexture_createFromFile("contents/img/sp/terran_nc2.png",
    NULL);
    texture[18] = sfTexture_createFromFile("contents/img/sp/terran_c1.png",
    NULL);
    texture[19] = sfTexture_createFromFile("contents/img/sp/terran_c2.png",
    NULL);
    texture[20] = sfTexture_createFromFile("contents/img/sp/ice.png", NULL);
    texture[21] = sfTexture_createFromFile("contents/img/sp/tech1.png", NULL);
    texture[22] = sfTexture_createFromFile("contents/img/sp/tech2.png", NULL);
    texture[23] = sfTexture_createFromFile("contents/img/sp/tech3.png", NULL);
    texture[24] = sfTexture_createFromFile("contents/img/sp/ast1.png", NULL);
    texture[25] = sfTexture_createFromFile("contents/img/sp/ast2.png", NULL);
    texture[26] = sfTexture_createFromFile("contents/img/sp/ast3.png", NULL);
    texture[27] = sfTexture_createFromFile("contents/img/sp/ast4.png", NULL);
    return (generates_planets_textures3(texture));
}

sfTexture **generates_planets_textures(void)
{
    sfTexture **texture = my_malloc(sizeof(sfTexture *) * 32);

    texture[0] = sfTexture_createFromFile("contents/img/sp/sun1.png", NULL);
    texture[1] = sfTexture_createFromFile("contents/img/sp/sun2.png", NULL);
    texture[2] = sfTexture_createFromFile("contents/img/sp/sun3.png", NULL);
    texture[3] = sfTexture_createFromFile("contents/img/sp/sun4.png", NULL);
    texture[4] = sfTexture_createFromFile("contents/img/sp/sun5.png", NULL);
    texture[5] = sfTexture_createFromFile("contents/img/sp/sun6.png", NULL);
    texture[6] = sfTexture_createFromFile("contents/img/sp/sun7.png", NULL);
    texture[7] = sfTexture_createFromFile("contents/img/sp/lava1.png", NULL);
    texture[8] = sfTexture_createFromFile("contents/img/sp/lava2.png", NULL);
    texture[9] = sfTexture_createFromFile("contents/img/sp/lava3.png", NULL);
    texture[10] = sfTexture_createFromFile("contents/img/sp/gas1.png", NULL);
    texture[11] = sfTexture_createFromFile("contents/img/sp/gas2.png", NULL);
    texture[12] = sfTexture_createFromFile("contents/img/sp/gas3.png", NULL);
    texture[13] = sfTexture_createFromFile("contents/img/sp/gas4.png", NULL);
    texture[14] = sfTexture_createFromFile("contents/img/sp/ocean_nc.png",
    NULL);
    texture[15] = sfTexture_createFromFile("contents/img/sp/ocean_c.png", NULL);
    return (generates_planets_textures2(texture));
}