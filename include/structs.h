/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** structs
*/

#ifndef STRUCTS_H_
#define STRUCTS_H_

#define WIDTH 1920
#define HEIGHT 1080
#include "my_rpg.h"

typedef struct st_planet_stat_s {
    float o;
    float he;
    float h;
    float h2o;
    float co2;
    float n2;
    float tmp;
    float pr;
} st_planet_stat;

typedef struct structs_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
}structs_t;

typedef struct paralax_s {
    sfSprite *nebula;
    sfTexture *nebulat;
    sfIntRect paralaxr;
    sfSprite *star;
    sfTexture *start;
    sfIntRect starr;
    sfClock *paralo;
    sfClock *staro;
}paralax_t;

typedef struct scatter {
    int kmax;
    int interval;
    int p;
    int germ;
    int q;
} scatter;

typedef struct st_planet_s {
    st_planet_stat stats;
    sfVector2f pos;
} st_planet;

typedef struct list_elem_planet
{
    st_planet planet;
    struct list_elem_planet *next;
} list_elem_planet, *list_planet;

typedef struct st_global_s {
    structs_t *window;
    paralax_t *paralax;
} st_global;

#endif /* !STRUCTS_H_ */
