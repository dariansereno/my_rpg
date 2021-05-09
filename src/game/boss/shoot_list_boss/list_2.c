/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_2
*/

#include "my_rpg.h"

void check_collision_ship_b(st_global *ad, list_timer_b *shoot)
{
    if (circle_contains(15, ad->ship->bshippos, (*shoot)->pos)) {
        ad->var_game->life -= ad->enn_damage;
        if (ad->var_game->life <= 0) {
            ad->win = false;
            ad->ui->end->existing = true;
        }
        (*shoot)->destroy = true;
    }
    if (is_on_planet(ad, (*shoot)->pos))
        (*shoot)->destroy = true;
}

void print_list_shoot_b_2(list_timer_b *temp, sfSprite *sprite, st_global *ad)
{
    if ((*temp)->timer.seconds > 0.01) {
        (*temp)->pos.x += (float)(*temp)->dir.x;
        (*temp)->pos.y += (float)(*temp)->dir.y;
        (*temp)->it += 1;
        sfClock_restart((*temp)->timer.clock);
    }
    sfSprite_setOrigin(sprite, (sfVector2f){16, 16});
    sfSprite_setScale(sprite, (sfVector2f){1.5, 1.5});
    sfSprite_setPosition(sprite, (*temp)->pos);
    sfRenderWindow_drawSprite(ad->window->window, sprite, NULL);
}

void print_list_shoot_b(list_timer_b *li, sfSprite *sprite, st_global *ad)
{
    list_timer_b temp = *li;
    list_timer_b buff = *li;

    if (temp == NULL)
        return ;
    while (temp != NULL) {
        temp->timer.time = sfClock_getElapsedTime(temp->timer.clock);
        temp->timer.seconds = temp->timer.time.microseconds / 1000000.0;
        print_list_shoot_b_2(&temp, sprite, ad);
        if (is_on_planet(ad, temp->pos))
            temp->destroy = true;
        if (temp->it >= 40)
            temp->destroy = true;
        check_collision_ship_b(ad, &temp);
        if (temp->destroy == true)
            pop_position_timer_b(li, temp->index);
        reindex_timer_b(li);
        temp = temp->next;
    }
}