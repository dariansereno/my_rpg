/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** map_limit
*/

#include "my_rpg.h"

sfVertexArray *generate_line(sfVector2f pos1, sfVector2f pos2, sfColor color)
{
    sfVertexArray *array = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(array, sfLines);
    sfVertex vertex1;
    sfVertex vertex2;

    vertex1.position = pos1;
    vertex1.color  = color;
    vertex2.position = pos2;
    vertex2.color = color;
    sfVertexArray_append(array, vertex1);
    sfVertexArray_append(array, vertex2);
    return (array);
}

sfVertexArray **init_limit_map()
{
    sfVertexArray **lines = my_malloc(sizeof(sfVertexArray *) * 4);

    lines[0] = generate_line((sfVector2f){0, 0}, (sfVector2f){50000, 0}, sfRed);
    lines[1] = generate_line((sfVector2f){0, 0}, (sfVector2f){0, 50000}, sfRed);
    lines[2] = generate_line((sfVector2f){50000, 50000}, (sfVector2f){50000, 0}, sfRed);
    lines[3] = generate_line((sfVector2f){50000, 50000}, (sfVector2f){0, 50000}, sfRed);
    return (lines);
}

void draw_map_limit(st_global *ad)
{
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawVertexArray(ad->window->window, ad->planets->limit[i],
        NULL);
    }
}