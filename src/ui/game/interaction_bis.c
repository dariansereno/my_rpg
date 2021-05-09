/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** interaction_bis
*/

#include "my_rpg.h"

void display_selector(st_object *selector, st_global *ad, list_planet planets,
sfVector2f origin)
{
    sfSprite_setPosition(selector->sprite, (sfVector2f)
    {(float)planets->planet.pos.x, (float)planets->planet.pos.y});
    sfSprite_setOrigin(selector->sprite, origin);
    sfSprite_setScale(selector->sprite, (sfVector2f){5, 5});
    sfRenderWindow_drawSprite(ad->window->window, selector->sprite
    , NULL);
}

char *create_planet_string(int index)
{
    char *str = "Entity n.";
    char *nb = int_to_str(index);
    char *res = my_malloc(sizeof(char) * (my_strlen(str) + my_strlen(nb) + 1));

    res[0] = '\0';
    if (index == 0)
        return ("Entity n.0");
    res = my_strcat(res, str);
    res = my_strcat(res, nb);
    return (res);
}