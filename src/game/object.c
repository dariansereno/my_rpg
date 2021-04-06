/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_object
*/

#include "my_rpg.h"

st_object *generate_object(sfVector2f pos, sfIntRect rect, char *texturepath)
{
    st_object *object = malloc(sizeof(st_object));

    object->pos = pos;
    object->rect = rect;
    object->texture = sfTexture_createFromFile(texturepath, NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setTextureRect(object->sprite, object->rect);
    object->timer = malloc(sizeof(*object->timer));
    object->timer->clock = sfClock_create();
    return (object);
}

void destroy_object(st_object *object)
{
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
    sfClock_destroy(object->timer->clock);
    free(object->timer);
    object->timer = NULL;
    free(object);
    object = NULL;
}