/*
** EPITECH PROJECT, 2021
** header
** File description:
** my_rpg.h
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#define WIDTH 1920
#define HEIGHT 1080

#include "strings.h"
#include "structs.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <math.h>

// GAME
    // ANIMATIONS
        // EXPLODE_ANIM.C
            void print_list_explo(list_timer *li, st_global *ad);
    // PARALAX
        // MOVE.C
            void go_right(st_global *ad);
            void go_left(st_global *ad);
            void go_down(st_global *ad);
            void go_up(st_global *ad);
            void paralax_move(st_global *ad);
        // MOVE_DIAGONAL.C
            void go_upright(st_global *ad);
            void go_downleft(st_global *ad);
            void go_upleft(st_global *ad);
            void go_downright(st_global *ad);
        // PARALAX_MOVE.C
            void move_up(st_global *ad);
            void move_down(st_global *ad);
            void move_left(st_global *ad);
            void move_right(st_global *ad);
        // PARALAX_MOVE.C
            void move_upright(st_global *ad);
            void move_downleft(st_global *ad);
            void move_upleft(st_global *ad);
            void move_downright(st_global *ad);
        // PARALAX_STAR_MOVE.C
            void move_star_up(st_global *ad);
            void move_star_down(st_global *ad);
            void move_star_left(st_global *ad);
            void move_star_right(st_global *ad);
        // PARALAX_STAR_MOVE_DIAGONAL.C
            void move_star_upright(st_global *ad);
            void move_star_downleft(st_global *ad);
            void move_star_upleft(st_global *ad);
            void move_star_downright(st_global *ad);
        // SET_KEY.C
            void setkeyup(st_global *ad);
            void setkeydown(st_global *ad);
            void setkeyleft(st_global *ad);
            void setkeyright(st_global *ad);
        // SET_KEY_DIAG.C
            void setkeyupleft(st_global *ad);
            void setkeyupright(st_global *ad);
            void setkeydownleft(st_global *ad);
            void setkeydownright(st_global *ad);
        // CHECK_ANGLE.C
            void check_angle(st_global *ad);
    // INPUTS
        // CHANGE_KEY.C
            void more_key_change(st_global *ad);
            void extra_change(st_global *ad);
            void change_key_press(st_global *ad);
            void last_key_pressed(st_global *ad);
        // INTERACTION.C
            void interaction_input(st_global *ad);
    // ENNEMIES
        // PATH_FINDING
            // CIRCLE_INTERSECTION
                void calculate_table_notation(sfVector2f start,
                st_ennemies *e, st_global *ad, int r);
                int direction_ennemie(st_ennemies ennemies, sfVector2f target,
                st_global *ad);
            // MOVE_ENNEMIES
                st_ennemies move_enn_up(st_ennemies e, st_global *ad);
                st_ennemies move_enn_down(st_ennemies e, st_global *ad);
                st_ennemies move_enn_left(st_ennemies e, st_global *ad);
                st_ennemies move_enn_right(st_ennemies e, st_global *ad);
                st_ennemies move_enn_upright(st_ennemies e, st_global *ad);
                st_ennemies move_enn_downright(st_ennemies e, st_global *ad);
                st_ennemies move_enn_downleft(st_ennemies e, st_global *ad);
                st_ennemies move_enn_upleft(st_ennemies e, st_global *ad);
                st_ennemies move_enn_stand(st_ennemies e, st_global *ad);
                void clock_move_ennemies(list_ennemies e, st_global *ad);
                void clock_move_ennemies_to_base(list_ennemies e, st_global
                *ad);
                void calculate_table_notation_base(st_ennemies *e,
                st_global *ad, int r, sfVector2f target);
                float note_case(sfVector2f start, sfVector2f end,
                st_global *ad);
        // ENNEMIES_GENERATION.C
            sfVector2f position_generate_near_planet(list_planet planet,
            st_global *ad, float radius);
            void ennemies_spawning(st_global *ad);
            sfTexture **enn_textures();
        // ENNEMIES_CONDITION.C
            bool is_on_planet(st_global *ad, sfVector2f object);
            bool is_on_ennemies(st_global *ad, list_ennemies ennemies,
            sfVector2f object);
        // LIST
            void push_back_ennemies(list_ennemies *li, st_ennemies ennemies);
            void print_ennemies_list_pos(list_ennemies li);
            int size_list_ennemies(list_ennemies li);
            void print_ennemies_list(list_ennemies li, sfRenderWindow *window,
            st_global *ad, st_planet pl);
            void pop_position_ennemies(list_ennemies *list, int index);
            void print_ennemies_list_index(list_ennemies li);
            void reindex_ennemies(list_ennemies *list);
    // OBJECT
        st_object *generate_object(sfVector2f pos, sfIntRect rect, char
        *texturepath);
        void destroy_object(st_object *object);
    // GAME.C
    void check_status(st_global *ad);
    void check_event(st_global *ad);
    int game_loop(void);

// SCREEN
    // SCREENS.C
        void screen(st_global *g);
        void screen_game(st_global *ad);
        void fade_update_size(st_global *g, int nb);
    // FADE.C
        st_fade *generate_fade(void);
        void display_fade(st_global *g);
        void clock_fade(st_global *g);
        void destroy_fade(st_fade *fade);
        void background_space_fade(st_global *g);
    // LOADING
        // LOADING
            st_loading *generate_loading_board();
            void screen_loading(st_global *g);
            void clock_planet_loading(st_global *g);
            void clock_loading_bar(st_global *g);
            void destroy_loading(st_loading *loading_board);
    // MENU
        // MENU
            st_menu *generate_menu(void);
            void screen_menu(st_global *g);
            void destroy_menu(st_menu *menu);
        // EVENTS_MENU
            void events_menu(st_global *g);
            void get_global_bounds_menu(st_global *g);
            int menu_choice(st_global *g);
    // SETTINGS
        // SETTINGS
            st_settings *generate_settings(void);
            void screen_settings(st_global *g);
            void destroy_settings(st_settings *settings);
            void set_position_settings(st_global *g);
            void parallax_settings(st_global *g);
        // EVENTS_SETTINGS
            void events_settings(st_global *g);
            void get_global_bounds_settings(st_global *g);
            int settings_choice(st_global *g);
            void control_volumes_settings(st_global *g);
            void animate_buttons_settings(st_global *g);
    // END

// MAP
    //ANIMATION
        // ANIMATION.C
            void animate_planets(st_global *ad);
            void spatial_object_move(st_global *ad);
            void display_on_view(st_global *ad);
    // INTERACTING
        // COLLISIONS.C
            void planet_collision(st_global *ad);
            void collision_by_first(bool c, st_global *ad);
            int circle_contains(int r, sfVector2f p, sfVector2f s);
        // INTERACTION.C
            void interaction(st_global *ad);
    // GENERATION
        // DESTROY
            void destroy_planet(list_elem_planet *planet);
            void destroy_global_planet(st_planet_global *planets);
        // GENERATION_MAP.C
            st_planet_global *generate_all_map(void);
            planet_kind generate_kind(int type);
        // MATH.C
            sfVector2i *scatter_plot(scatter math);
            int random_between(int start, int stop);
            int random_piped();
        // GENERATE_PLANET_TYPE.C
            st_planet *general_all_planets(sfVector2i *pos, int size);
            sfTexture **generates_planets_textures();
        // STAT_PLANETS.C
            st_planet_stat stats_for_gas(st_planet_stat planet);
            st_planet_stat stats_for_ocean(st_planet_stat planet);
            st_planet_stat stats_for_terran(st_planet_stat planet);
            st_planet_stat stats_for_lava(st_planet_stat planet);
            st_planet_stat stats_for_sun(st_planet_stat planet);
            st_planet_stat stats_for_tech(st_planet_stat planet);
            st_planet_stat stats_for_asteroid(st_planet_stat planet);
            st_planet_stat stats_for_ice(st_planet_stat planet);
            st_planet_stat stats_for_blackhole(st_planet_stat planet);
    // LIST
        // LIST_ACTION.C
            void push_back_planet(list_planet *li, st_planet planet);
            void print_lil_planet(list_planet li, sfRenderWindow *window,
            st_global *ad);
            void pop_position_planet(list_planet *list, sfVector2f pos);
            int size_list_planet(list_planet li);
            void print_planet_list(list_planet li, sfRenderWindow *window,
            st_global *ad);
            void set_texture_planets(list_planet *li, st_planet_global *g);
            list_planet pop_back_planet(list_planet list);
            list_planet planet_from_index(int index, list_planet li);
            void print_planet_list_stat(list_planet li);
    // TRADE
        // TRADE.C
            st_ressources **trade(st_global *ad);
            void generate_trade(st_global *ad);
            st_ressources **check_double(bool is_good, st_ressources **tab, int i, int j);
            int prices(st_global *ad, int id);
            int stock(st_global *ad, int id);
// STRUCTS
    st_global *ini(void);
    structs_t *all_dat(void);
    void destroy_global(st_global *global);
    keys_t *key_ini(st_global *ad);
    load_t *texture_ini(void);
    moula_t *money_ini(void);
// OBJECT.C
    st_object *generate_object(sfVector2f pos, sfIntRect rect,
    char *texturepath);

// UI
    // GENERATE_UI
        // GENERATE_UI
            void destroy_ui(st_ui *ui);
            st_ui *generate_ui(void);
    // GAME
        // FIGHT
            // GENERATE
                st_global_shoot *generate_shoot();
                int deduct_dir(st_global *ad);
                void ship_shoot(st_global *ad);
                sfVector2f change_pos_by_dir(int dir, sfVector2f pos);
            // LIST
                void push_back_timer(list_timer *li, sfVector2f pos, int dir);
                void reindex_timer(list_timer *li);
                void pop_position_timer(list_timer *list, int index);
                int size_list_timer(list_timer li);
                list_timer timer_from_index(int index, list_timer li);
                void print_list_shoot(list_timer *li, sfSprite **sprite,
                st_global *ad);
                void print_list_shoot_enn(list_timer *li, sfSprite **sprite,
                st_global *ad);
            // COLLISION SHOOT
                void collision_shoot(st_global *ad, list_timer *shoot);
        // INTERACTION.C
            void display_interaction(st_global *ad);
            char *int_to_str(int nb);
            char *create_planet_string(int index);
    // PLANET_CARD
        // PLANET_CARD
            void display_planet_card(st_global *g);
            void planet_card_display_sprite_text(st_global *g);
            void text_draw_planet_card(st_global *g);
        // GENERATE_PLANET_CARD
            planet_card_s *generate_planet_card(void);
            void create_planet_card(st_global *g, sfVector2f position_view, \
            list_planet planets);
            void rectangle_shape_text_planet_card_creation(st_global *g);
            void destroy_planet_card(planet_card_s *planet_card);
        // RECTANGLE_SHAPE
            void rectangle_shape_planet_card_set(st_global *g, \
            list_planet planets);
            void rectangle_shape_planet_card_position(st_global *g);
        // TEXT
            void texts_planet_card_set(st_global *g);
            void text_planet_card_set_string(st_global *g, list_planet planets);
            void text_planet_card_temperature(st_global *g, \
            list_planet planets);
            void text_planet_card_position(st_global *g);
    // TRADE_CARD
        // GENERATE_TRADE_CARD
            trade_card_s *generate_trade_card(void);
            trade_card_s *generate_trade_card_bools(trade_card_s *trade_card);
            void destroy_trade_card(trade_card_s *trade_card);
        // ARROWS
            void count_items();
            void arrow_events_trade(st_global *g);
            void arrow_texture(st_global *g);
        // TRADE_CARD
            void rect_trade_position(st_global *g);
            void set_init_position_trade(st_global *g);
            void display_planet_trade_card(st_global *g);
            void display_trade_card(st_global *g);
            void display_texts_trade_card(st_global *g, list_planet planets);
        // TEXT_TRADE_CARD
            char *int_to_str_credits(int money);
            char *int_to_str_price(int money);
            void items_text_trade_card(st_global *g, int y);
            void text_title_credits_trade_card(st_global *g, list_planet planets);
    // MODULE_CARD
        // GENERATE_MODULE_CARD
            module_card_s *generate_module_card(void);
            void destroy_module_card(module_card_s *module_card);
        // MODULE_CARD
            void display_module_card(st_global *g);
            void set_init_position_module(st_global *g);
            void display_texts_module_card(st_global *g, list_planet planets);
            void display_planet_module_card(st_global *g);
            void rect_module_position(st_global *g);
        // TEXT_MODULE_CARD
            void text_title_credits_module_card(st_global *g, list_planet planets);
            void text_price_module_card(st_global *g);
        // ARROWS
            void arrow_events_module(st_global *g);
    // UI_GAME
        // GENERATE_UI_GAME
            ui_game_s *generate_ui_game(void);
            void destroy_ui_game(ui_game_s *ui);
            void set_rectangle_ui_game(ui_game_s *ui);
        // UI_GAME
            void set_position_ui_game(st_global *g);
            void display_ui_game(st_global *g);
            void rectangle_display_ui_game(st_global *g);
    // PAUSE
        // GENERATE_PAUSE
            pause_s *generate_pause(void);
            void destroy_pause(pause_s *pause);
        // PAUSE
            void display_pause(st_global *g);
            void rect_position_pause(st_global *g);
        // EVENTS
            void events_pause_down(st_global *g);
            void events_pause_up(st_global *g);
            void events_redirect_pause(st_global *g);
            void text_pause(st_global *g);
        // HOVER
            void hover(st_global *g);
        // SETTINGS
            // GENERATE_PAUSE_SETTINGS
                pause_set_s *generate_pause_settings(void);
                void destroy_pause_settings(pause_set_s *settings);
            // PAUSE_SETTINGS
                void rect_set_position_pause_settings(st_global *g);
                void display_pause_settings(st_global *g);
                void set_rect_texture_pause_settings(st_global *g);
            // EVENTS_PAUSE_SETTINGS
                void text_rect_pause_settings(st_global *g);
                void events_pause_settings(st_global *g);
                void events_pause_settings_left(st_global *g);
                void events_pause_settings_right(st_global *g);
                void set_width_volume_pause_settings(st_global *g);

// MESSAGES
    // ADDITIONNAL_MSG
        int backslash_n_counter(st_global *global);
        char *cpy_to_up_text(st_global *g);
    // BACKSLASH_ADD
        cpy_backslash_s *generate_cpy(void);
        char *automatically_set_text_max(st_global *g);
        char *manage_copy_n(char *str, st_global *g);
        char *add_backslash_n_to_space(char *str, st_global *g);
        char *add_backslash_n(char *str, st_global *g);
    // DESTROY_MSG
        void destroy_message(st_global *global);
    // DISPLAY_MSG
        void display_msg(sfRenderWindow *window, st_global *global);
        void clock_dialogue_text_line1(st_global *g);
        void clock_dialogue_text_line2(st_global *g);
        void clock_dialogue_text_line3(st_global *g);
    // SET_MESSAGE
        void dialogue_text_settings(st_global *global);
        void dialogue_rectangle_settings(st_global *g);
        void dialogue_rectangle_settings_bis(st_global *g);
        void dialogue_text(st_global *global);
        void add_message(st_global *global, char *str, int delay);

int game_loop_2();
void dialogue_text(st_global *global);
void display_msg(sfRenderWindow *window, st_global *global);
void clock_dialogue_text_line1(st_global *global);
void clock_dialogue_text_line2(st_global *global);
void clock_dialogue_text_line3(st_global *global);
char *automatically_set_text_max(st_global *g);
cpy_backslash_s *generate_cpy();
char *manage_copy_n(char *str, st_global *g);
char *add_backslash_n_to_space(char *str, st_global *g);
char *add_backslash_n(char *str, st_global *g);
char *cpy_to_up_text(st_global *global);
void dialogue_text_settings(st_global *global);
int backslash_n_counter(st_global *global);
void add_message(st_global *global, char *str, int delay);
void destroy_message(st_global *global);
void dialogue_rectangle_settings_bis(st_global *g);

#endif /* !MY_RPG_H_ */