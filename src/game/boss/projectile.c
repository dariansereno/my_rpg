/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** projectile
*/

#include "my_rpg.h"

sfVector2f calculate_target_vector(sfVector2f start, sfVector2f end, int velo)
{
    return ((sfVector2f){(end.x - start.x) / velo, (end.y - start.y) / velo});
}