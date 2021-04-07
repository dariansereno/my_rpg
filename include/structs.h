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
#include <stdbool.h>

typedef struct cpy_backslash_t {
    int end;
    int begin;
    float len;
    bool space;
} cpy_backslash_s;

typedef struct st_text_s {
    sfSprite *arrow_s;
    sfTexture *arrow_t;
    sfRectangleShape *whi_r;
    sfRectangleShape *whi_r2;
    sfRectangleShape *text_r1;
    sfRectangleShape *text_r2;
    sfRectangleShape *text_r3;
    sfRectangleShape *text_r4;
    sfText *text;
    sfFont *font;
    sfBool existing;
    sfClock *clock;
    cpy_backslash_s *c;
    char *str;
    int delay;
} st_text;

typedef enum ressources_id_s {
    item1,
    item2,
    item3
} ressources_id;

typedef enum planet_type_s {
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

typedef enum relation_s {
    ALLY,
    NEUTRAL,
    HOSTILE,
    ENEMY
} st_relation;

typedef enum planet_kind_s {
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

typedef enum planet_climate_s {
    ARDENT,
    WARM,
    NORMAL,
    COLD,
    FROSTEN
} planet_climate;

typedef enum st_interaction_type_s {
    MENU,
    FIGHT,
    TRADE,
    INFO,
    TALK
} st_interaction_type;

typedef struct st_timer_s {
    sfClock *clock;
    sfTime time;
    float seconds;
} st_timer;

typedef struct st_object_s {
    sfTexture *texture;
    sfSprite *sprite;
    st_timer *timer;
    sfVector2f pos;
    sfIntRect rect;
} st_object;

typedef struct key_pressed_s {
    bool Z;
    bool D;
    bool S;
    bool Q;
} key_pressed;

typedef enum planet_animation_s {
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
    sfVector2f velocity;
    sfVector2f acceleration;
}ship_t;

typedef struct st_ennemies_s
{
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} st_ennemies;

typedef struct list_elem_ennemies_s
{
    st_ennemies ennemies;
    int index;
    struct list_elem_ennemies_s *next;
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
    sfTexture **th;
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

typedef struct scatter_s {
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
    st_relation relation;
    planet_climate climate;
    sfSprite *sprite;
    sfIntRect rect;
    list_ennemies ennemies;
    bool habitable;
} st_planet;

typedef struct list_elem_planet_s
{
    st_planet planet;
    st_timer timer;
    st_timer move;
    st_timer spawning;
    bool interact;
    st_interaction_type interact_type;
    bool on_screen;
    int direction;
    int index;
    int ennemies_spawn;
    struct list_elem_planet_s *next;
} list_elem_planet, *list_planet;

typedef struct st_global_planet_s {
    list_planet planets;
    sfTexture **textures;
} st_planet_global;

typedef struct st_planet_card_t {
    sfSprite *mockup_s;
    sfTexture *mockup_t;
    sfRectangleShape *r_o_2;
    sfRectangleShape *r_h;
    sfRectangleShape *r_h_2_o;
    sfRectangleShape *r_co_2;
    sfRectangleShape *r_n;
    sfRectangleShape *r_n_2;
    sfFont *font;
    sfText *t_o_2;
    sfText *t_h;
    sfText *t_h_2_o;
    sfText *t_co_2;
    sfText *t_n;
    sfText *t_n_2;
    sfText *t_temp;
    sfText *t_pres;
    sfText *title;
    bool existing;
    bool displaying;
    bool closing;
} planet_card_s;

typedef struct st_ui {
    st_object *interacting;
    st_object **selector;
    planet_card_s *planet_card;
} st_ui;

typedef struct st_variable_s {
    int max_ennemies;
} st_variable;

typedef struct st_useful_s{
    sfText *planet_text;
    sfFont *font;
} st_useful;

typedef struct st_ressources
{
    int id;
    int nb;
    int stack;
} st_ressources;

typedef struct list_elem_ressources_s
{
    st_ressources ressource;
    struct list_elem_ressources *next;
} list_elem_ressources, *list_ressources;

typedef struct st_global_ressources_s
{
    list_ressources ressources;
    int max;
} st_global_ressources;

typedef struct st_global_s {
    st_text *text;
    st_planet_global *planets;
    structs_t *window;
    paralax_t *paralax;
    key_pressed key_pressed;
    ship_t *ship;
    st_ui *ui;
    sfTexture *enn_texture;
    st_variable *var;
    st_useful *other;
    keys_t *key;
    load_t *texture;
} st_global;

#endif /* !STRUCTS_H_ */