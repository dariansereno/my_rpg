/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** ennemies_drop
*/

#include "my_rpg.h"

int drop_id(st_global *ad)
{
    int rand = random_between(0, 10);

    if (rand <= 7)
        return (0);
    if (rand > 7)
        return (1);
}

void drop_money(st_global *ad, list_ennemies en)
{
    int rand = random_between(0, 10);
    int amount = 0;
    st_drop drop;

    if (rand < 5)
        amount = random_between(10, 50);
    else if(rand >= 5 && rand <= 8)
        amount = random_between(50, 100);
    else
        amount = random_between(100, 150);
    drop.mode = 1;
    drop.amount = amount;
    drop.pos = (sfVector2f){en->ennemies.pos.x + 10, en->ennemies.pos.y};
    ad->money->money += amount;
    push_back_drop(&ad->drop, drop);
    // sfText_setString(ad->ressources[0].text, number_and_string(amount, "credits +"));
    // sfText_setPosition(ad->ressources[0].text, (sfVector2f){en->ennemies.pos.x
    // + 10, en->ennemies.pos.y});
    // sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);
}

void drop_ressources(st_global *ad, list_ennemies en)
{
    int res = random_between(0, 2);
    int rand = random_between(0, 10);
    int nb = 0;
    st_drop drop;

    if (rand < 5)
        nb = 1;
    else if(rand >= 5 && rand <= 8)
        nb = 2;
    else
        nb = 3;
    ad->ressources[res].nb += nb;
    drop.mode = 0;
    drop.id = res;
    drop.nb = nb;
    drop.pos = (sfVector2f){en->ennemies.pos.x + 10, en->ennemies.pos.y};
    push_back_drop(&ad->drop, drop);
    // sfText_setString(ad->ressources[0].text, itoa(nb, ad->nb_inv, 10));
    // sfText_setPosition(ad->ressources[0].text, (sfVector2f){en->ennemies.pos.x
    // + 10, en->ennemies.pos.y});
    // sfRenderWindow_drawText(ad->window->window, ad->ressources[0].text, NULL);
    // sfSprite_setPosition(ad->items[res]->sprite, (sfVector2f){en->ennemies.pos.x
    // + 13, en->ennemies.pos.y});
    // sfRenderWindow_drawSprite(ad->window->window, ad->items[res]->sprite, NULL);
}

void drop(st_global *ad, list_ennemies en)
{
    int rand = random_between(0, 10);
    int drop = drop_id(ad);

    if (drop)
        drop_ressources(ad, en);
    else
        drop_money(ad, en);
}