/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** interaction
*/

#include "my_rpg.h"

void display_selector(st_object *selector, st_global *ad, list_planet planets,
sfVector2f origin)
{
    sfSprite_setPosition(selector->sprite, (sfVector2f)
    {(float)planets->planet.pos.x, (float)planets->planet.pos.y});
    sfSprite_setOrigin(selector->sprite, origin);
    sfSprite_setScale(selector->sprite, (sfVector2f){5, 5});
    sfRenderWindow_drawSprite(ad->window->window, selector->sprite
    ,NULL);
}

char *create_planet_string(int index)
{
    char *str = "Entity n.";
    char *nb = int_to_str(index);
    char *res = my_malloc(sizeof(char) * (my_strlen(str) + my_strlen(nb) + 1));

    res[0] = '\0';
    if (index == 0)
        return ("Planet n.0");
    res = my_strcat(res, str);
    res = my_strcat(res, nb);
    return (res);
}

void display_planet_text(list_planet planets, st_global *ad)
{
    create_planet_string(planets->index);
    sfText_setPosition(ad->other->planet_text,
    (sfVector2f){(float)planets->planet.pos.x - (planets->planet.rect.width * 2)
    , (float)(planets->planet.pos.y + (planets->planet.rect.height) * 2 + 80)});
    sfText_setString(ad->other->planet_text,
    create_planet_string(planets->index));
    sfText_setCharacterSize(ad->other->planet_text, 20);
    sfText_setFillColor(ad->other->planet_text, sfWhite);
    sfRenderWindow_drawText(ad->window->window, ad->other->planet_text, NULL);
}

void selector_interaction(list_planet planets, st_global *ad)
{
    if (planets == NULL)
        return ;
    if (planets->planet.type >= 0 && planets->planet.type <= 6)
        display_selector(ad->ui->selector[1], ad, planets,
        (sfVector2f){39, 39});
    if (planets->planet.type >= 7 && planets->planet.type <= 23)
        display_selector(ad->ui->selector[0], ad, planets,
        (sfVector2f){27, 27});
    if (planets->planet.type >= 24)
        display_selector(ad->ui->selector[2], ad, planets,
        (sfVector2f){31.5, 32});
    display_planet_text(planets, ad);
}

void change_interact(st_global *ad, list_planet in)
{
    list_planet pl = ad->planets->planets;

    if (in == NULL)
        return ;
    while (pl != NULL) {
        if (pl->planet.pos.x == in->planet.pos.x &&
        pl->planet.pos.y == in->planet.pos.y) {
            pl->interact = true;
        }
        else
            pl->interact = false;
        pl = pl->next;
    }
}

void display_interaction(st_global *ad)
{
    list_planet planets = ad->planets->planets;
    sfVector2f disp = {0, 0};
    int max = 10000;
    list_planet selected = NULL;

    while (planets != NULL) {
        if (planets->can_interact == true) {
            disp.x = ad->ship->viewrect.left + 1750;
            disp.y = ad->ship->viewrect.top + 50;
            sfSprite_setPosition(ad->ui->interacting->sprite, disp);
            sfSprite_setScale(ad->ui->interacting->sprite, (sfVector2f){7, 7});
            sfRenderWindow_drawSprite(ad->window->window,
            ad->ui->interacting->sprite, NULL);
            if (abs(planets->planet.pos.x - (int)ad->ship->bshippos.x) +
            abs(planets->planet.pos.y - (int)ad->ship->bshippos.y) < max){
                max = abs(planets->planet.pos.x - (int)ad->ship->bshippos.x) +
                abs(planets->planet.pos.y - (int)ad->ship->bshippos.y);
                selected = planets;
            }
        }
        else {
            planets->can_interact = false;
            planets->interact = false;
        }
        planets = planets->next;
    }
    change_interact(ad, selected);
    selector_interaction(selected, ad);
}