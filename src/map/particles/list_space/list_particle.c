/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_particle
*/

#include "my_rpg.h"

int size_list_particle(list_particle li)
{
    list_particle node = li;
    int i = 0;

    for (; node != NULL; ++i)
        node = node->next;
    return (i);
}

void push_back_particle(list_particle *li, st_global_particle *g,
sfVector2f pos)
{
    list_particle node = my_malloc(sizeof(*node));
    list_particle lastnode = *li;

    node->particle.lifetime = 5;
    node->particle.color = (sfColor){random_between(100, 150),
    random_between(100, 150), random_between(100, 150), 255};
    node->particle.radius = 4;
    node->particle.alpha = 255;
    node->particle.emitter = pos;
    node->particle.clock = sfClock_create();
    node->particle.start_time = sfClock_getElapsedTime(g->clock).microseconds
    / 1000000.0;
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

void pop_position_particle(list_particle *list, int index)
{
    list_particle temp = *list;
    list_particle next = NULL;

    if (*list == NULL)
        return;
    if (index >= size_list_particle(*list))
        return ;
    if (index == 0) {
        *list = temp->next;
        return ;
    }
    for (; temp != NULL && temp->next->index != index ;)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    next = temp->next->next;
    temp->next = next;
}

void reindex_particle(list_particle *li)
{
    list_particle temp = *li;

    if (temp == NULL)
        return ;
    for (int i = 0; temp != NULL; i++) {
        temp->index = i;
        temp = temp->next;
    }
    return ;
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
        if (second > 0.05) {
            temp->particle.elapsed = sfClock_getElapsedTime(ad->particle->clock).
            microseconds / 1000000.0;
            temp->particle.emitter.x += 0.5;
            temp->particle.emitter.y += 0.3;
            temp->particle.alpha -= 2.5;
            temp->particle.color = (sfColor){temp->particle.color.r, \
            temp->particle.color.g, temp->particle.color.b, \
            temp->particle.alpha};
            if (temp->particle.elapsed - temp->particle.start_time >
            temp->particle.lifetime)
                temp->destroy = true;
            if (temp->destroy == true)
                pop_position_particle(li, temp->index);
            reindex_particle(li);
            sfClock_restart(temp->particle.clock);
        }
        sfCircleShape_setPosition(ad->particle->circle, temp->particle.emitter);
        sfCircleShape_setFillColor(ad->particle->circle, temp->particle.color);
        sfCircleShape_setRadius(ad->particle->circle ,temp->particle.radius);
        sfRenderWindow_drawCircleShape(ad->window->window, ad->particle->circle,
            NULL);
        temp = temp->next;
    }
}