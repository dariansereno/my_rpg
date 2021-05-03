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