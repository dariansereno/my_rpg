/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** ship_shoot
*/

#include "my_rpg.h"

void ship_shoot(st_global *ad)
{
    sfTime time = sfClock_getElapsedTime(ad->ship->reload->clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > ad->var_game->reload_time) {
        push_back_timer(&ad->shoot->li_shoot, ad->ship->bshippos,
        deduct_dir(ad));
        reindex_timer(&ad->shoot->li_shoot);
        sfClock_restart(ad->ship->reload->clock);
    }
}

void ciao_ennemy(list_ennemies en, st_global *ad, list_planet *pl)
{
    if (en->ennemies.life <= 0){
        for (int i = 0; i < 10; i++)
            push_back_particle_explo(&ad->particle->particles, ad->particle,
            en->ennemies.pos);
        drop(ad, en);
        push_back_timer(&ad->shoot->li_explo,  en->ennemies.pos, -1);
        pop_position_ennemies(&(*pl)->planet.ennemies, en->index);
        reindex_ennemies(&(*pl)->planet.ennemies);
        reindex_ennemies(&(*pl)->planet.ennemies);
        if (ad->var_game->quests == 1 && ad->quest->is_on_quest == true)
            ad->var_game->kills += 1;
    }
}

void check_all_ennemies_from_planet(st_global *ad, list_timer *shoot,
list_planet *pl)
{
    list_ennemies en = (*pl)->planet.ennemies;

    while (en != NULL) {
        if (circle_contains(30, (*shoot)->pos, en->ennemies.pos)) {
            en->ennemies.life -= ad->var_game->attack;
            ciao_ennemy(en, ad, pl);
            (*shoot)->destroy = true;
        }
        en = en->next;
    }
}

void ciao_ennemy_boss(list_ennemies en, st_global *ad)
{
    if (en->ennemies.life <= 0){
        drop(ad, en);
        for (int i = 0; i < 30; i++)
            push_back_particle_explo(&ad->particle->particles, ad->particle,
            en->ennemies.pos);
        push_back_timer(&ad->shoot->li_explo, en->ennemies.pos, -1);
        pop_position_ennemies(&ad->boss->enn, en->index);
        reindex_ennemies(&ad->boss->enn);
        if (ad->var_game->quests == 1)
            ad->var_game->kills += 1;
    }
}

void check_boss(st_global *ad, list_timer *shoot)
{
    list_ennemies en = ad->boss->enn;

    if (circle_contains(ad->boss->radius_col, (*shoot)->pos,
    ad->boss->boss->pos)) {
        ad->boss->life_f -= (ad->var_game->attack * (float)ad->boss->take_dmg);
        (*shoot)->destroy = true;
    }
    while (en != NULL) {
        if (circle_contains(30, (*shoot)->pos, en->ennemies.pos)) {
            en->ennemies.life -= ad->var_game->attack;
            ciao_ennemy_boss(en, ad);
            (*shoot)->destroy = true;
        }
        en = en->next;
    }
}

void collision_shoot(st_global *ad, list_timer *shoot)
{
    list_planet pl = ad->planets->planets;

    if (!ad->var_game->destroy_boss)
        check_boss(ad, shoot);
    while (pl != NULL) {
        if (pl->on_screen == true && pl->planet.kind == TECH)
            check_all_ennemies_from_planet(ad, shoot, &pl);
        pl = pl->next;
    }
}