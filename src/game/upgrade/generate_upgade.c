/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** upgade
*/

#include "my_rpg.h"

int *generate_tab_upgrade(void)
{
    int *tab = my_malloc(sizeof(int) * 4);

    for (int i = 0; i < 4; i++)
        tab[i] = 0;
    return (tab);
}

st_object **generate_icon(void)
{
    st_object **obj = my_malloc(sizeof(**obj) * 4);

    obj[0] = generate_object((sfVector2f){0, 0}, \
    (sfIntRect){0, 0, 32, 32}, "contents/upgrade/damage.png");
    obj[1] = generate_object((sfVector2f){0, 0}, \
    (sfIntRect){0, 0, 32, 32}, "contents/upgrade/reload.png");
    obj[2] = generate_object((sfVector2f){0, 0}, \
    (sfIntRect){0, 0, 60, 60}, "contents/upgrade/speed.png");
    obj[3] = generate_object((sfVector2f){0, 0}, \
    (sfIntRect){0, 0, 60, 60}, "contents/upgrade/health.png");
    return (obj);
}

st_upgrade *generate_upgrade(void)
{
    st_upgrade *upgrade = my_malloc(sizeof(*upgrade));

    upgrade->upgrade_tab = generate_tab_upgrade();
    upgrade->can_upgrade = false;
    upgrade->upgrade_icon = generate_icon();
    return (upgrade);
}