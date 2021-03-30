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

typedef enum planet_type {
    GAS1,
    GAS2,
    GAS3,
    GAS4,
    ICE,
    LAVA1,
    LAVA2,
    LAVA3,
    OCEAN_N_C,
    OCEAN_C,
    TERRAN_N_C1,
    TERRAN_N_C2,
    TERRAN_N_C3,
    TERRAN_C1,
    TERRAN_C2,
    TECH1,
    TECH2,
    TECH3,
    BLACKHOLE1,
    BLACKHOLE2,
    BLACKHOLE3,
    ASTEROID1,
    ASTEROID2,
    ASTEROID3,
    ASTEROID4,
    ASTEROID5,
    SUN1,
    SUN2,
    SUN3,
    SUN4,
    SUN5,
    SUN6,
    SUN7
} planet_type;

typedef enum planet_animation {
    ANIMATED,
    NON_ANIMATED
} planet_animation;

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
    sfVector2i pos;
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
