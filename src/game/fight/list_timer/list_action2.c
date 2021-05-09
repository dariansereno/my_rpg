/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_action2
*/

#include "my_rpg.h"

sfVector2f change_pos_by_dir(int dir, sfVector2f pos)
{
    switch (dir) {
        case 0:
            return ((sfVector2f){pos.x, pos.y - 20});
        case 1:
            return ((sfVector2f){pos.x + 16, pos.y - 16});
        case 2:
            return ((sfVector2f){pos.x + 20, pos.y});
        case 3:
            return ((sfVector2f){pos.x + 16, pos.y + 16});
        case 4:
            return ((sfVector2f){pos.x, pos.y + 20});
        case 5:
            return ((sfVector2f){pos.x - 16, pos.y + 16});
        case 6:
            return ((sfVector2f){pos.x - 20, pos.y});
        case 7:
            return ((sfVector2f){pos.x - 16, pos.y - 16});
    }
}

list_timer pop_front_timer(list_timer li)
{
    list_elem_timer *elem;

    if (li == NULL)
        return (li);

    elem = my_malloc(sizeof(*elem));

    elem = li->next;
    li = NULL;

    return (elem);
}

void destroy_list_timer(list_timer *li)
{
    while (*li != NULL)
        *li = pop_front_timer(*li);
    if (*li != NULL) {
        sfClock_destroy((*li)->timer.clock);
        *li = NULL;
    }
}