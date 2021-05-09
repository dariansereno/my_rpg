/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_particle_2
*/

#include "my_rpg.h"

void print_list_particle_content(list_particle *temp, list_particle *li,
st_global *ad)
{
    (*temp)->particle.elapsed = sfClock_getElapsedTime
    (ad->particle->clock).microseconds / 1000000.0;
    (*temp)->particle.emitter.x += 0.5;
    (*temp)->particle.emitter.y += 0.3;
    (*temp)->particle.alpha -= 2.5;
    (*temp)->particle.color = (sfColor){(*temp)->particle.color.r, \
    (*temp)->particle.color.g, (*temp)->particle.color.b, \
    (*temp)->particle.alpha};
    if ((*temp)->particle.elapsed - (*temp)->particle.start_time >
    (*temp)->particle.lifetime)
        (*temp)->destroy = true;
    if ((*temp)->destroy == true)
        pop_position_particle(li, (*temp)->index);
    reindex_particle(li);
    sfClock_restart((*temp)->particle.clock);
}

void print_list_particle(list_particle *li, st_global *ad)
{
    list_particle temp = *li;
    list_particle buff = *li;
    sfTime time;
    float second;
    sfVector2f pos;

    if (temp == NULL)
        return ;
    while (temp != NULL) {
        time = sfClock_getElapsedTime(temp->particle.clock);
        second = time.microseconds / 1000000.0;
        if (second > 0.05)
            print_list_particle_content(&temp, li, ad);
        sfCircleShape_setPosition(ad->particle->circle, temp->particle.emitter);
        sfCircleShape_setFillColor(ad->particle->circle, temp->particle.color);
        sfCircleShape_setRadius(ad->particle->circle, temp->particle.radius);
        sfRenderWindow_drawCircleShape(ad->window->window, ad->particle->circle,
        NULL);
        temp = temp->next;
    }
}

list_particle pop_front_particle(list_particle li)
{
    list_elem_particle *elem;

    if (li == NULL)
        return (li);

    elem = my_malloc(sizeof(*elem));

    elem = li->next;
    sfClock_destroy(li->timer.clock);
    sfClock_destroy(li->particle.clock);
    li = NULL;

    return (elem);
}

void destroy_list_particle(list_particle *li)
{
    while (*li != NULL)
        *li = pop_front_particle(*li);
    if (*li != NULL) {
        sfClock_destroy((*li)->timer.clock);
        sfClock_destroy((*li)->particle.clock);
        *li = NULL;
    }
}