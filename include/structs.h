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
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct st_talk_text_s {
    sfRectangleShape *black_outline;
    sfRectangleShape *purple_outline;
    sfRectangleShape *white_rectangle;
    sfText *talk_text;
    sfFont *talk_font;
    sfSprite *speed_text_sprite_line1;
    sfTexture *speed_text_texture_line1;
    sfSprite *speed_text_sprite_line2;
    sfTexture *speed_text_texture_line2;
    sfSprite *speed_text_sprite_line3;
    sfTexture *speed_text_texture_line3;
    sfIntRect speed_text_rect_line1;
    sfIntRect speed_text_rect_line2;
    sfIntRect speed_text_rect_line3;
    sfBool existing;
    sfClock *clock;
} st_talk_text;



typedef enum planet_type {
    SUN1,
    SUN2,
    SUN3,
    SUN4,
    SUN5,
    SUN6,
    SUN7,
    LAVA1,
    LAVA2,
    LAVA3,
    GAS1,
    GAS2,
    GAS3,
    GAS4,
    OCEAN_N_C,
    OCEAN_C,
    TERRAN_N_C1,
    TERRAN_N_C2,
    TERRAN_C1,
    TERRAN_C2,
    ICE,
    TECH1,
    TECH2,
    TECH3,
    ASTEROID1,
    ASTEROID2,
    ASTEROID3,
    ASTEROID4,
    ASTEROID5,
    BLACKHOLE1,
    BLACKHOLE2,
    BLACKHOLE3
} planet_type;

typedef enum planet_kind {
    SUN,
    LAVA,
    GAS,
    OCEAN,
    TERRAN,
    ICEP,
    TECH,
    ASTEROID,
    BLACKHOLE
} planet_kind;

typedef enum planet_climate
{
    ARDENT,
    WARM,
    NORMAL,
    COLD,
    FROSTEN
} planet_climate;

typedef struct st_timer
{
    sfClock *clock;
    sfTime time;
    float seconds;
} st_timer;

typedef struct st_object {
    sfTexture *texture;
    sfSprite *sprite;
    st_timer *timer;
    sfVector2f pos;
    sfIntRect rect;
} st_object;

typedef struct key_pressed {
    bool Z;
    bool D;
    bool S;
    bool Q;
} key_pressed;

typedef enum planet_animation {
    NON_ANIMATED,
    ANIMATED
} planet_animation;

typedef struct st_planet_stat_s {
    int o;
    int h;
    int h2o;
    int co2;
    int N;
    int n2;
    int pressure;
} st_planet_stat;

typedef struct structs_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
    sfMusic *music;
}structs_t;

typedef struct ship_s {
    sfSprite *bship;
    sfTexture *bshipt;
    sfVector2f bshippos;
    sfFloatRect viewrect;
    bool collisionS;
    bool collisionD;
    bool collisionQ;
    bool collisionZ;
    bool firstcollisionS;
    bool firstcollisionD;
    bool firstcollisionQ;
    bool firstcollisionZ;
    sfView *view;
}ship_t;

typedef struct st_ennemies
{
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} st_ennemies;

typedef struct list_elem_ennemies
{
    st_ennemies ennemies;
    bool on_screen;
    int index;
    struct list_elem_ennemies *next;
} list_elem_ennemies, *list_ennemies;

typedef struct keys_s {
    int up;
    int down;
    int left;
    int right;
    int upleft;
    int upright;
    int downleft;
    int downright;
} keys_t;

typedef struct load_s {
    sfTexture **load;
} load_t;

typedef struct paralax_s {
    sfSprite *nebula;
    sfTexture *nebulat;
    sfIntRect paralaxr;
    sfSprite *star;
    sfTexture *start;
    sfIntRect starr;
    sfClock *paralo;
    sfClock *staro;
    sfClock *clock;
    sfVector2i move;
    sfVector2f nebulapos;
    sfVector2f starpos;
    int i;
    int j;
    int k;
    int l;
} paralax_t;

typedef struct scatter {
    int kmax;
    int interval;
    int p;
    int germ;
    int q;
} scatter;

typedef struct st_planet_s {
    st_planet_stat stats;
    planet_kind kind;
    sfVector2i pos;
    planet_type type;
    planet_animation animated;
    planet_climate climate;
    sfSprite *sprite;
    sfIntRect rect;
    list_ennemies ennemies;
    bool habitable;
} st_planet;

typedef struct list_elem_planet
{
    st_planet planet;
    st_timer timer;
    st_timer move;
    st_timer spawning;
    bool interact;
    bool on_screen;
    int direction;
    int index;
    int ennemies_spawn;
    struct list_elem_planet *next;
} list_elem_planet, *list_planet;

typedef struct st_global_planet_s {
    list_planet planets;
    sfTexture **textures;
} st_planet_global;

typedef struct st_ui {
    st_object *interacting;
    st_object **selector;
} st_ui;

typedef struct st_variable_s {
    int max_ennemies;
} st_variable;

typedef struct st_useful {
    sfText *planet_text;
    sfFont *font;
} st_useful;

typedef struct st_global_s {
    st_talk_text *talk_text;
    structs_t *window;
    paralax_t *paralax;
    key_pressed key_pressed;
    ship_t *ship;
    st_planet_global *planets;
    st_ui *ui;
    sfTexture *enn_texture;
    st_variable *var;
    st_useful *other;
    keys_t *key;
    load_t *texture;
} st_global;

#endif /* !STRUCTS_H_ */