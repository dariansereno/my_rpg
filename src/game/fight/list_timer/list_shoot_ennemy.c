/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_shoot_ennemy
*/

#include "my_rpg.h"

void ciao_nous(st_global *ad)
{
    if (ad->var_game->life <= 0) {
        ad->ui->end->existing = true;
        ad->win = false;
    }
}

void check_collision_ship(st_global *ad, list_timer *shoot)
{
    if (circle_contains(15, ad->ship->bshippos, (*shoot)->pos)) {
        ad->var_game->life -= ad->enn_damage;
        ciao_nous(ad);
        (*shoot)->destroy = true;
    }
    if (is_on_planet(ad, (*shoot)->pos))
        (*shoot)->destroy = true;
}

void collision_shoot_enn(st_global *ad, list_timer *shoot)
{
    list_planet pl = ad->planets->planets;

    check_collision_ship(ad, shoot);
    while (pl != NULL) {
        if (pl->on_screen == true && pl->planet.kind == TECH)
            check_collision_ship(ad, shoot);
        pl = pl->next;
    }
}

void print_list_shoot_enn_contents(list_timer *temp, st_global *ad, sfSprite
**sprite)
{
    (*temp)->timer.time = sfClock_getElapsedTime((*temp)->timer.clock);
    (*temp)->timer.seconds = (*temp)->timer.time.microseconds / 1000000.0;
    if ((*temp)->timer.seconds > 0.01) {
        (*temp)->pos = change_pos_by_dir((*temp)->dir, (*temp)->pos);
        (*temp)->it += 1;
        sfClock_restart((*temp)->timer.clock);
    }
    sfSprite_setPosition(sprite[(*temp)->dir], (*temp)->pos);
    sfRenderWindow_drawSprite(ad->window->window, sprite[(*temp)->dir], NULL);
}

void print_list_shoot_enn(list_timer *li, sfSprite **sprite, st_global *ad)
{
    list_timer temp = *li;
    list_timer buff = *li;

    if (temp == NULL)
        return ;
    while (temp != NULL) {
        print_list_shoot_enn_contents(&temp, ad, sprite);
        if (temp->it >= 50)
            temp->destroy = true;
        collision_shoot_enn(ad, &temp);
        if (temp->destroy == true)
            pop_position_timer(li, temp->index);
        reindex_timer(li);
        temp = temp->next;
    }
}