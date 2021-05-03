/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** ship_shoot
*/

#include "my_rpg.h"

void ship_shoot(st_global *ad)
{
    push_back_timer(&ad->shoot->li_shoot, ad->ship->bshippos, deduct_dir(ad));
}

void ciao_ennemy(list_ennemies en, st_global *ad, list_planet *pl)
{
    if (en->ennemies.life <= 0)
        pop_position_ennemies(&(*pl)->planet.ennemies, en->index);
}

void check_all_ennemies_from_planet(st_global *ad, list_timer *shoot,
list_planet *pl)
{
    list_ennemies en = (*pl)->planet.ennemies;

    while (en != NULL) {
        if (circle_contains(30, (*shoot)->pos, en->ennemies.pos)) {
            en->ennemies.life -= ad->ship->attack;
            ciao_ennemy(en, ad, pl);
                (*shoot)->destroy = true;
        }
        en = en->next;
    }
}

void collision_shoot(st_global *ad, list_timer *shoot)
{
    list_planet pl = ad->planets->planets;

    while (pl != NULL) {
        if (pl->on_screen == true && pl->planet.kind == TECH) {
            check_all_ennemies_from_planet(ad, shoot, &pl);
        }
        pl = pl->next;
    }
}