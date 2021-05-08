/*
** EPITECH PROJECT, 2021
** nebAXY
** File description:
** generate_space_obj
*/

#include "my_rpg.h"

sfTexture **generate_space_obj_texture()
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * 16);

    textures[0] = sfTexture_createFromFile("contents/spaceobj/gal1.png", NULL);
    textures[1] = sfTexture_createFromFile("contents/spaceobj/gal2.png", NULL);
    textures[2] = sfTexture_createFromFile("contents/spaceobj/gal3.png", NULL);
    textures[3] = sfTexture_createFromFile("contents/spaceobj/gal4.png", NULL);
    textures[4] = sfTexture_createFromFile("contents/spaceobj/moon1.png", NULL);
    textures[5] = sfTexture_createFromFile("contents/spaceobj/moon2.png", NULL);
    textures[6] = sfTexture_createFromFile("contents/spaceobj/moon3.png", NULL);
    textures[7] = sfTexture_createFromFile("contents/spaceobj/moon4.png", NULL);
    textures[8] = sfTexture_createFromFile("contents/spaceobj/neb1.png", NULL);
    textures[9] = sfTexture_createFromFile("contents/spaceobj/neb2.png", NULL);
    textures[10] = sfTexture_createFromFile("contents/spaceobj/neb3.png", NULL);
    textures[11] = sfTexture_createFromFile("contents/spaceobj/neb4.png", NULL);
    textures[12] = sfTexture_createFromFile("contents/spaceobj/neb5.png", NULL);
    textures[13] = sfTexture_createFromFile("contents/spaceobj/neb6.png", NULL);
    textures[14] = sfTexture_createFromFile("contents/spaceobj/neb7.png", NULL);
    textures[15] = sfTexture_createFromFile("contents/spaceobj/neb8.png", NULL);
    return (textures);
}

void generate_space_obj_li(list_spaceobj *li, st_global_spaceobj *objs)
{
    scatter math = {.germ = 469880, .interval = 50000, .kmax =
    random_between(50, 100), .p = 1288, .q = 1664713};
    sfVector2i *pos = scatter_plot(math);

    for (int i = 0; i < math.kmax; i++) {
        push_back_spaceobj(li, pos[i], random_between(0, 15));
    }
    set_texture_spaceobjs(li, objs);
}

st_global_spaceobj *generate_space_obj()
{
    st_global_spaceobj *space_obj = malloc(sizeof(*space_obj));

    space_obj->textures = generate_space_obj_texture();
    space_obj->li = NULL;
    generate_space_obj_li(&space_obj->li, space_obj);
    return (space_obj);
}