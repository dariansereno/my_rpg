/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_particle
*/

#include "my_rpg.h"

void push_particle_explo_copy_node(list_particle node, list_particle *li,
st_global_particle *g, sfVector2f pos)
{
    float angle = ((float)rand()/(float)(RAND_MAX)) * ((M_PI * 2) - 0) + 0;

    node->particle.lifetime = 3;
    node->particle.color = (sfColor){random_between(170, 1255),
    random_between(0, 50), random_between(0, 50), 255};
    node->particle.radius = 2;
    node->particle.alpha = 255;
    node->particle.emitter = pos;
    node->particle.vel.x = cos(angle);
    node->particle.vel.y = sin(angle);
    node->particle.clock = sfClock_create();
    node->particle.start_time = sfClock_getElapsedTime(g->clock).microseconds
    / 1000000.0;
}

void push_back_particle_explo(list_particle *li, st_global_particle *g,
sfVector2f pos)
{
    list_particle node = my_malloc(sizeof(*node));
    list_particle lastnode = *li;

    push_particle_explo_copy_node(node, li, g, pos);
    node->index = size_list_particle(*li);
    node->destroy = false;
    node->next = NULL;
    if (*li == NULL)
        *li = node;
    else {
        while (lastnode->next != NULL)
            lastnode = lastnode->next;
        lastnode->next = node;
    }
}

void print_list_particle_explo_contents(list_particle *li, st_global *ad,
list_particle *temp)
{
    (*temp)->particle.elapsed = sfClock_getElapsedTime(ad->particle->clock).
    microseconds / 1000000.0;
    (*temp)->particle.emitter.x += (*temp)->particle.vel.x;
    (*temp)->particle.emitter.y += (*temp)->particle.vel.y;
    (*temp)->particle.alpha -= 0.425;
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

void print_list_particle_explo(list_particle *li, st_global *ad)
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
        if (second > 0.005)
            print_list_particle_explo_contents(li, ad, &temp);
        sfCircleShape_setPosition(ad->particle->circle, temp->particle.emitter);
        sfCircleShape_setFillColor(ad->particle->circle, temp->particle.color);
        sfCircleShape_setRadius(ad->particle->circle, temp->particle.radius);
        sfRenderWindow_drawCircleShape(ad->window->window, ad->particle->circle,
        NULL);
        temp = temp->next;
    }
}