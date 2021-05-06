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

typedef enum modules_id_s {
    module_housing,
    module_commercial,
    module_health,
    module_extraction
} modules_id;

typedef enum ressources_id_s {
    black_matter,
    ingot,
    crystal,
    settler_module
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

typedef struct st_drop_s {
    int mode;
    int id;
    int nb;
    int amount;
    int xp;
    sfVector2f pos;
} st_drop;

typedef struct list_elem_timer_s {
    st_timer timer;
    int index;
    sfVector2f pos;
    int dir;
    int it;
    bool destroy;
    struct list_elem_timer_s *next;
} *list_timer, list_elem_timer;

typedef struct list_elem_drop_s {
    st_drop drop;
    st_timer timer;
    int index;
    int it;
    bool destroy;
    struct list_elem_drop_s *next;
} *list_drop, list_elem_drop;

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
    bool J;
    bool Enter;
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
    float music_volume;
    int width_volume;
    float sfx_volume;
    int width_sfx;
    int screen;
    bool created;
    bool second_created;
    bool bool_load;
    bool bool_game;
    bool bool_menu;
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
    bool collisionSlim;
    bool collisionDlim;
    bool collisionQlim;
    bool collisionZlim;
    bool firstcollisionSlim;
    bool firstcollisionDlim;
    bool firstcollisionQlim;
    bool firstcollisionZlim;
    sfView *view;
    sfVector2f velocity;
    sfVector2f acceleration;
    st_timer *reload;
    float reload_time;
    float life;
    float attack;
    bool craft;
    bool clicked;
    float xp;
    int lvl;
    int max_xp;
}ship_t;

typedef struct st_ennemies_s
{
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f spawn_pos;
    sfIntRect rect;
    float *path_table;
    float life;
    int dir;
} st_ennemies;

typedef struct list_elem_ennemies_s
{
    st_ennemies ennemies;
    st_timer *timer;
    list_timer li_shoot;
    st_timer *shootcl;
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

typedef struct st_ressources_s {
    int id;
    int nb;
    int stack;
    int price;
    sfText *text;
} st_ressources;

typedef struct list_elem_ressources_s {
    st_ressources ressource;
    struct list_elem_ressources *next;
} list_elem_ressources, *list_ressources;

typedef struct list_elem_spaceobj_s {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect *rect;
    st_timer *timer;
    int id;
    bool on_screen;
    struct list_elem_spaceobj_s *next;
} list_elem_spaceobj, *list_spaceobj;

typedef struct st_global_spaceobj_s {
    list_spaceobj li;
    sfTexture **textures;
} st_global_spaceobj;

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
    bool tradable;
    list_ennemies ennemies;
    bool colonized;
    int *mod_price;
    int *modules;
    int mul_housing;
} st_planet;

typedef struct list_elem_planet_s {
    st_planet planet;
    st_timer timer;
    st_timer move;
    st_timer spawning;
    st_ressources **trade;
    bool interact;
    bool can_interact;
    st_interaction_type interact_type;
    bool on_screen;
    int direction;
    int index;
    int ennemies_spawn;
    int size;
    int sc;
    struct list_elem_planet_s *next;
} list_elem_planet, *list_planet;

typedef struct st_global_planet_s {
    list_planet planets;
    sfTexture **textures;
    sfSprite *colonized_pl;
    sfTexture *texture_colonized;
    sfVertexArray **limit;
    bool col_lim;
    st_timer *gen_mod;
    st_timer *health_mod;
    st_timer *ext_mod;
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
} planet_card_s;

typedef struct st_trade_card_t {
    sfFont *font;
    sfText *text;
    st_object *ui[6];
    bool existing;
    bool pressed;
    int first_cell;
    int pos_rect;
    int counter;
} trade_card_s;

typedef struct st_module_card_t {
    sfFont *font;
    sfText *text;
    st_object *ui[4];
    bool existing;
    bool pressed;
    int pos_rect;
    bool buy;
    int mod_mul;
} module_card_s;

typedef struct st_ui_game {
    st_object *map;
    st_object *craft[2];
    st_object *item;
    sfRectangleShape *life;
    sfRectangleShape *life_outline;
    sfRectangleShape *credits;
    sfRectangleShape *credits_outline;
    sfRectangleShape *xp;
    sfRectangleShape *xp_outline;
    sfText *text;
    sfFont *font;
    st_object *upgrade;
} ui_game_s;

typedef struct st_pause_t {
    st_object *ui[2];
    sfText *text;
    sfFont *font;
    bool existing;
    bool pressed;
    int pos_rect;
} pause_s;

typedef struct st_pause_settings_t {
    st_object *ui[4];
    sfText *text;
    sfFont *font;
    int pos_rect;
    bool existing;
    bool pressed;
} pause_set_s;

typedef struct st_loading_t {
    st_object *planet;
    st_object *rect[2];
    bool close;
} st_loading;

typedef struct st_menu_t {
    sfView *view;
    st_object *cursor;
    st_object *items[4];
    sfFloatRect bounds[3];
    int menu;
} st_menu;

typedef struct st_end_t {
    st_object *ui[4];
    sfText *text;
    sfFont *font;
    bool existing;
    bool pressed;
    int pos_rect;
} st_end;

typedef struct st_fade_t {
    sfRectangleShape *rect[2];
    st_timer timer;
    bool fade;
} st_fade;

typedef struct st_settings_t {
    st_object *save;
    st_object *cancel;
    st_object *cross;
    st_object *background;
    st_object *music;
    st_object *sfx;
    sfFloatRect bounds[3];
    int settings;
} st_settings;

typedef struct st_ui {
    st_object *interacting;
    st_object **selector;
    planet_card_s *planet_card;
    trade_card_s *trade_card;
    module_card_s *module_card;
    ui_game_s *ui;
    pause_s *pause;
    pause_set_s *pause_settings;
    st_loading *loading_board;
    st_menu *menu;
    st_end *end;
    st_fade *fade;
    st_settings *settings;
} st_ui;

typedef struct st_variable_s {
    int max_ennemies;
    int mod_price_add;
    st_timer *drop_cl;
} st_variable;

typedef struct st_useful_s {
    sfText *planet_text;
    sfFont *font;
} st_useful;

typedef struct st_global_ressources_s {
    list_ressources ressources;
    int max;
} st_global_ressources;

typedef struct moula_s {
    int money;
    sfText *moneytext;
    sfFont *moneyfont;
    sfText *moneyval;
    sfVector2f coinpos;
} moula_t;

typedef struct st_global_shoot_s
{
    list_timer li_shoot;
    sfTexture *tex_ship;
    sfTexture *tex_enn;
    sfSprite **sprite_ship;
    sfSprite **sprite_enn;
    sfSprite *explo_sp;
    st_timer *explo_tmr;
    sfIntRect explo_rect;
    list_timer li_explo;
} st_global_shoot;

typedef struct st_global_sfx_s
{
    sfSound *explosion;
} st_global_sfx;

typedef struct items_s {
    sfSprite *ingot;
    sfSprite *bm;
    sfSprite *crystal;
    sfTexture *ingott;
    sfTexture *bmt;
    sfTexture *crystalt;
} items_t;

typedef struct st_upgrade_s {
    int *upgrade_tab;
    bool can_upgrade;
} st_upgrade;

typedef struct st_global_s {
    st_text *text;
    st_planet_global *planets;
    structs_t *window;
    paralax_t *paralax;
    key_pressed key_pressed;
    key_pressed last_key_pressed;
    ship_t *ship;
    st_ui *ui;
    sfTexture **enn_texture;
    st_variable *var;
    st_useful *other;
    keys_t *key;
    load_t *texture;
    moula_t *money;
    st_ressources *ressources;
    st_global_shoot *shoot;
    float mul_price;
    st_object **items;
    float enn_damage;
    bool win;
    sfFont *font_inv;
    char *nb_inv;
    st_global_spaceobj *space_obj;
    list_drop drop;
    sfCircleShape *circle;
    items_t *itemsss;
    st_upgrade *upgrade;
} st_global;

#endif /* !STRUCTS_H_ */