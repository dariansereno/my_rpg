/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generates_planets_textures
*/

#include "my_rpg.h"

sfTexture **generates_planets_textures2(sfTexture **texture, sfIntRect *a)
{
    texture[16] = sfTexture_createFromFile("contents/img/sp/terran_nc1.png", a);
    texture[17] = sfTexture_createFromFile("contents/img/sp/terran_nc2.png", a);
    texture[18] = sfTexture_createFromFile("contents/img/sp/terran_c1.png", a);
    texture[19] = sfTexture_createFromFile("contents/img/sp/terran_c2.png", a);
    texture[20] = sfTexture_createFromFile("contents/img/sp/tech1.png", a);
    texture[21] = sfTexture_createFromFile("contents/img/sp/tech2.png", a);
    texture[22] = sfTexture_createFromFile("contents/img/sp/tech3.png", a);
    texture[23] = sfTexture_createFromFile("contents/img/sp/ice.png", a);
    texture[24] = sfTexture_createFromFile("contents/img/sp/ast1.png", a);
    texture[25] = sfTexture_createFromFile("contents/img/sp/ast2.png", a);
    texture[26] = sfTexture_createFromFile("contents/img/sp/ast3.png", a);
    texture[27] = sfTexture_createFromFile("contents/img/sp/ast4.png", a);
    texture[28] = sfTexture_createFromFile("contents/img/sp/ast5.png", a);
    texture[29] = sfTexture_createFromFile("contents/img/sp/bh1.png", a);
    texture[30] = sfTexture_createFromFile("contents/img/sp/bh2.png", a);
    texture[31] = sfTexture_createFromFile("contents/img/sp/bh3.png", a);

    return (texture);
}

sfTexture **generates_planets_textures()
{
    sfTexture **texture = malloc(sizeof(sfTexture *) * 32);
    sfIntRect a = (sfIntRect){.height = 48, .width = 48, .left = 0, .top = 0};

    texture[0] = sfTexture_createFromFile("contents/img/sp/sun1.png", &a);
    texture[1] = sfTexture_createFromFile("contents/img/sp/sun2.png", &a);
    texture[2] = sfTexture_createFromFile("contents/img/sp/sun3.png", &a);
    texture[3] = sfTexture_createFromFile("contents/img/sp/sun4.png", &a);
    texture[4] = sfTexture_createFromFile("contents/img/sp/sun5.png", &a);
    texture[5] = sfTexture_createFromFile("contents/img/sp/sun6.png", &a);
    texture[6] = sfTexture_createFromFile("contents/img/sp/sun7.png", &a);
    texture[7] = sfTexture_createFromFile("contents/img/sp/lava1.png", &a);
    texture[8] = sfTexture_createFromFile("contents/img/sp/lava2.png", &a);
    texture[9] = sfTexture_createFromFile("contents/img/sp/lava3.png", &a);
    texture[10] = sfTexture_createFromFile("contents/img/sp/gas1.png", &a);
    texture[11] = sfTexture_createFromFile("contents/img/sp/gas2.png", &a);
    texture[12] = sfTexture_createFromFile("contents/img/sp/gas3.png", &a);
    texture[13] = sfTexture_createFromFile("contents/img/sp/gas4.png", &a);
    texture[14] = sfTexture_createFromFile("contents/img/sp/ocean_nc.png", &a);
    texture[15] = sfTexture_createFromFile("contents/img/sp/ocean_c.png", &a);
    return(generates_planets_textures2(texture, &a));
}