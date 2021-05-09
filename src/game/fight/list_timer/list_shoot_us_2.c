/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_shoot_us_2
*/

#include "my_rpg.h"

void print_list_shoot_contents(list_timer *temp, st_global *ad, sfSprite
**sprite)
{
    (*temp)->timer.time = sfClock_getElapsedTime((*temp)->timer.clock);
    (*temp)->timer.seconds = (*temp)->timer.time.microseconds / 1000000.0;
    if ((*temp)->timer.seconds > 0.01) {
        (*temp)->pos = change_pos_by_dir((*temp)->dir, (*temp)->pos);
        (*temp)->it += 1;
        sfClock_restart((*temp)->timer.clock);
    }
    sfSprite_setScale(sprite[(*temp)->dir], (sfVector2f){1.5, 1.5});
    sfSprite_setPosition(sprite[(*temp)->dir], (*temp)->pos);
    sfRenderWindow_drawSprite(ad->window->window, sprite[(*temp)->dir], NULL);
}

void print_list_shoot(list_timer *li, sfSprite **sprite, st_global *ad)
{
    list_timer temp = *li;
    list_timer buff = *li;

    if (temp == NULL)
        return ;
    while (temp != NULL) {
        print_list_shoot_contents(&temp, ad, sprite);
        if (is_on_planet(ad, temp->pos))
            temp->destroy = true;
        if (temp->it >= ad->var_game->range)
            temp->destroy = true;
        collision_shoot(ad, &temp);
        if (temp->destroy == true)
            pop_position_timer(li, temp->index);
        reindex_timer(li);
        temp = temp->next;
    }
}