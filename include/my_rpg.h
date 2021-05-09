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

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

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
    // QUEST
        // GENERATE_QUEST.C
            void generate_random_quest(list_planet *planet);
        // FIND_ID.C
            void target_quest(st_global *ad);
        // QUEST1.C
            void quest_1_initialise(st_global *ad);
            void start_quest1(st_global *ad);
        // QUESTS_CALLER.C
            void check_quest(st_global *ad);
        // QUEST2.C
            void quest_2_initialise(st_global *ad);
            void start_quest2(st_global *ad);
        // QUEST3.C
            void quest_3_initialise(st_global *ad);
            void start_quest3(st_global *ad);
        // QUEST4.C
            void quest_4_initialise(st_global *ad);
            void start_quest4(st_global *ad);
        // QUEST5.C
            void quest_5_initialise(st_global *ad);
            void start_quest5(st_global *ad);
        // QUEST6.C
            void quest_6_initialise(st_global *ad);
            void start_quest6(st_global *ad);
    // UPGRADE
        // UPGRADE.C
            void display_stats_ship(st_global *ad);
            void destroy_upgrade(st_upgrade *up);
            void can_upgrade(st_global *ad);
            int *generate_tab_upgrade(void);
            st_upgrade *generate_upgrade(void);
            void display_upgrade(st_global *ad);
            void choose_upgrade(st_global *ad);
    // ANIMATIONS
        // EXPLODE_ANIM.C
            void print_list_explo(list_timer *li, st_global *ad);
    // INVENTORY
        // GENERATE_INVENTORY.C
            st_object **generate_items(void);
            st_ressources *generate_inventory(st_global *ad);
        // DISPLAY_INVENTORY
            void display_items_inventory(st_global *ad);
        // INV_HANDLING.C
            void is_craftable(st_global *ad);
            void craft_settler(st_global *ad);
    // PARALAX
        // MOVE.C
            void move_ship(st_global *ad);
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
            void plus_key_change(st_global *ad);
            void generate_key_pressed(st_global *ad);
            void generate_last_key_pressed(st_global *ad);
        // INTERACTION.C
            void interaction_input(st_global *ad);
        // MORT_INTERACT.C
            int interact_input6(st_global *ad);
            void interact_input7(st_global *ad, int counter);
    // ENNEMIES
        // PATH_FINDING
            // DROP
                void drop(st_global *ad, list_ennemies en);
                int random_money(void);
                int random_ressources(void);
                int random_nb_ressources(void);
                int random_xp(st_global *ad);
            // LIST DROP
                void destroy_list_drop(list_drop *li);
                void pop_position_drop(list_drop *list, int index);
                void push_back_drop(list_drop *li, st_drop drop);
                void print_list_drop(list_drop *li, st_global *ad);
            // CIRCLE_INTERSECTION
                void calculate_table_notation(sfVector2f start,
                st_ennemies *e, st_global *ad, int r);
                int direction_ennemie(st_ennemies ennemies, sfVector2f target,
                st_global *ad);
                float heuristic(sfVector2f start, sfVector2f end);
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
            sfTexture **enn_textures(void);
        // ENNEMIES_CONDITION.C
            void spawn_boss_condition(st_global *ad);
            bool is_on_planet(st_global *ad, sfVector2f object);
            bool is_on_boss(st_global *ad, sfVector2f object);
            bool is_on_ennemies(list_ennemies ennemies, sfVector2f object);
        // LIST
            void destroy_ennemies_list(list_ennemies *en);
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
    void draw_window_game(st_global *ad);
    void display_back_object(st_global *ad);
    void display_if_not_menu_2(st_global *ad);
    void display_if_not_menu(st_global *ad);
    void print_forground_and_event(st_global *ad);
// SCREEN
    // SCREENS.C
        void screen(st_global *g);
        void screen_game(st_global *ad);
        void fade_update_size(st_global *g, int nb);
    // SWITCH_SCREEN.C
        void switch_screen_one(st_global *g, sfVideoMode mode);
        void switch_screen_two(st_global *g);
        void switch_screen_four(st_global *g);
        void switch_screen_five(st_global *g);
    // FADE.C
        st_fade *generate_fade(void);
        void display_fade(st_global *g);
        void clock_fade(st_global *g);
        void destroy_fade(st_fade *fade);
        void background_space_fade(st_global *g);
    // LOADING
        // LOADING
            st_loading *generate_loading_board(void);
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
            void parallax_menu(st_global *g);
        // EVENTS_SETTINGS
            void events_settings(st_global *g);
            void get_global_bounds_settings(st_global *g);
            int settings_choice(st_global *g);
            void control_volumes_settings(st_global *g);
            void animate_buttons_settings(st_global *g);
        // CONDITIONS_SETTINGS
            void condition_volume_settings(st_global *g, int x, int y);
            void switch_settings_one(st_global *g);
            void switch_settings_two(st_global *g);
        // MORE_EVENTS_SETTINGS.C
            void more_settings_event(st_global *g, int i);
            void more_button_pressed_event(st_global *g, int i);
    // END
        // END
            void end_rect_left_2(st_global *g);
            void end_rect_right_2(st_global *g);
            void position_end_2(st_global *g);
            st_end *generate_end(void);
            void position_end(st_global *g);
            void display_end(st_global *g);
            void position_win(st_global *g);
            void destroy_end(st_end *end);
        // EVENTS_END
            void end_rect_left(st_global *g);
            void end_rect_right(st_global *g);
            void position_bg_end(st_global *g);
            void rect_position_end(st_global *g);
            void text_position_end(st_global *g);

// MAP
    // PARTICLE
        st_global_particle *generate_particle(void);
        void push_back_particle(list_particle *li, st_global_particle *g,
        sfVector2f pos);
        void destroy_list_particle(list_particle *li);
        void add_particles(st_global *ad);
        int size_list_particle(list_particle li);
        void print_list_particle(list_particle *li, st_global *ad);
        void push_back_particle_explo(list_particle *li, st_global_particle *g,
        sfVector2f pos);
        void print_list_particle_explo(list_particle *li, st_global *ad);
        void pop_position_particle(list_particle *list, int index);
        void reindex_particle(list_particle *li);
    // SPACE_OBJ
        st_global_spaceobj *generate_space_obj(void);
        void destroy_list_spaceobj(list_spaceobj *li);
        void push_back_spaceobj(list_spaceobj *li, sfVector2i pos, int id);
        void set_texture_spaceobjs(list_spaceobj *li, st_global_spaceobj *g);
        void set_texture_spaceobjs(list_spaceobj *li, st_global_spaceobj *g);
        void print_spaceobj_list(list_spaceobj li, sfRenderWindow *window,
        st_global *ad);
        void display_on_view_spaceobj(st_global *ad);
        void destroy_spaceobj(st_global_spaceobj *obj);
    // COLONISATION
        // GENERATE_COLONISATION.C
            void generate_random_colonised(list_planet *planet, st_global *ad);
            int random_piped_two(void);
        // PRINT_COLONISATION.C
            void print_colonised_selec(st_global *ad);
        // COLONISE_PLANET.C
            void print_can_colonise(st_global *ad);
            void print_can_trade(st_global *ad);
            void print_can_quest(st_global *ad);
            void colonise_planet(st_global *ad);
        // PRINT_CAN_COLONISE.C
            int check_can_colonise_text(st_global *ad, list_planet pl,
            int print);
    //ANIMATION
        // ANIMATION.C
            void animate_planets(st_global *ad);
            void spatial_object_move(st_global *ad);
            void display_on_view(st_global *ad);
    // INTERACTING
        // COLLISIONS.C
            void check_good_collision(st_global *ad, list_planet planet);
            void good_collision(st_global *ad, bool *c);
            void planet_collision_content(st_global *ad, list_planet *planet,
            bool *c);
            void planet_collision(st_global *ad);
            void ZQ_collisions(st_global *ad);
            void SD_collisions(st_global *ad);
            void renitialise_collisions(st_global *ad);
            void collision_by_first(bool c, st_global *ad);
            int circle_contains(int r, sfVector2f p, sfVector2f s);
            void ZQ_collisions(st_global *ad);
            void SD_collisions(st_global *ad);
            void renitialise_collisions(st_global *ad);
        // INTERACTION.C
            void interaction(st_global *ad);
            void display_planet_text(list_planet planets, st_global *ad);
            void display_selector(st_object *selector, st_global *ad,
            list_planet planets, sfVector2f origin);
        // MAP_LIMIT.C
            void check_good_collision_lim(st_global *ad);
            sfVertexArray **init_limit_map(void);
            void draw_map_limit(st_global *ad);
            void collision_limit(st_global *ad);
    // INFRASTRUCTURE
        // MODULE
            void effect_com_module(st_global *ad);
            void effect_extract_module(st_global *ad);
            void effect_health_module(st_global *ad);
    // GENERATION
        // DESTROY
            void destroy_planet(list_planet pl);
            void destroy_global_planet(st_planet_global *planets);
        // GENERATION_MAP.C
            st_planet_global *generate_all_map(void);
            planet_kind generate_kind(int type);
        // MATH.C
            sfVector2i *scatter_plot(scatter math);
            int random_between(int start, int stop);
            int random_piped(void);
        // GENERATE_PLANET_TYPE.C
            st_planet_stat generate_planet_stat2(st_planet planet);
            st_planet_stat generate_planet_stat(st_planet planet);
            planet_climate climate_from_type(planet_type planet);
            planet_animation animation_from_type(planet_type planet);
            st_planet *general_all_planets(sfVector2i *pos, int size);
            sfTexture **generates_planets_textures(void);
        // STAT_PLANETS.C
            planet_kind generate_kind(int type);
            void selector_colonized_pl(st_planet_global *planets);
            int *generate_mod_price(void);
            st_planet_global *generate_planet_global(void);
            void *generate_list_planets(st_planet_global *planets, scatter math,
            sfVector2i *pos);
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
            void pop_position_planet(list_planet *list, sfVector2f pos);
            int size_list_planet(list_planet li);
            void set_texture_planets(list_planet *li, st_planet_global *g);
            list_planet pop_back_planet(list_planet list);
            list_planet planet_from_index(int index, list_planet li);
            void print_planet_list_stat(list_planet li);
            void print_planet_list_normal(list_planet li,
            sfRenderWindow *window, st_global *ad);
            void print_planet_list_big(list_planet li, sfRenderWindow *window,
            st_global *ad);
            void print_planet_list_little(list_planet li,
            sfRenderWindow *window, st_global *ad);
    // TRADE
        // TRADE.C
            st_ressources **trade(st_global *ad);
            void generate_trade(st_global *ad, list_planet *planets);
            st_ressources **check_double(bool is_good, st_ressources **tab, \
            int i, int j);
            int prices(st_global *ad, int id);
            int stock(st_global *ad, int id);
// STRUCTS
    paralax_t *paralax_ini(void);
    void generate_paths(ship_t *ship);
    void init_ship_by_choosen(st_global *ad);
    void items_menu(st_global *g);
    st_global *ini(void);
    structs_t *all_dat(void);
    st_game_var *ini_var(void);
    void destroy_global(st_global *global);
    keys_t *key_ini(st_global *ad);
    load_t *texture_ini(void);
    moula_t *money_ini(void);
    quest_t *item_ini(void);
// OBJECT.C
    st_object *generate_object(sfVector2f pos, sfIntRect rect,
    char *texturepath);

// UI
    // GENERATE_UI
        // GENERATE_UI
            void destroy_ui(st_ui *ui);
            st_ui *generate_ui(void);
            void generate_ui_bis(st_ui *ui);
    // GAME
        // FIGHT
            // GENERATE
                st_global_shoot *generate_shoot(void);
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
            char *number_and_string(int index, char *str);
            char *create_planet_string(int index);
            list_planet display_interaction_boss_bis(st_global *ad, sfVector2f
            disp, list_planet planets, int max);
        // BOSS
            int circle_intersect(sfVector2f c1, sfVector2f c2, int d1, int d2);
            st_boss *generate_boss_fight(st_global *ad);
            void victory(st_global *ad);
            st_boss *generate_boss(void);
            void boss_appear(st_global *ad);
            void display_boss_bg(st_global *ad);
            void boss_life(st_global *g);
            void destroy_li_shoot_boss(list_timer_b *li);
            void destroy_boss(st_boss *boss);
            void rect_set_boss(st_global *g);
            void atk_queue_boss(st_global *ad);
            void boss_atk(st_global *ad);
            void boss_fight(st_global *ad);
            sfVector2f calculate_target_vector(sfVector2f start, sfVector2f end,
            int velo);
            void attack_1(st_global *ad);
            void attack_2(st_global *ad);
            void attack_2_circle_2(st_global *ad, float second);
            void attack_3(st_global *ad);
            void attack_4(st_global *ad);
            void attack_5(st_global *ad);
            void attack_5_shield(st_global *ad);
            void boss_handling(st_global *ad);
            void boss_red(st_global *ad);
            void display_big_message(char *msg, int delay, st_global *ad, \
            sfColor color);
            void explo_die(st_global *ad);
        // BOSS COLLISION
            void boss_collision(st_global *ad);
            void check_good_collision_boss(st_global *ad);
            int change_radius_if_shield(st_global *ad);
            // LIST_BOSS_QUEUE
                int size_list_boss(list_boss li);
                void push_back_boss(list_boss *li, int duration, int atk_type);
                list_boss pop_front_boss(list_boss li);
                void destroy_list_boss(list_boss *li);
                void destroy_boss_fight(st_global *ad);
            // LIST BOSS SHOOT
                list_timer pop_front_timer(list_timer li);
                void destroy_list_timer(list_timer *li);
                void print_list_explo_lil_boss(list_timer *li, st_global *ad);
                void print_list_explo_boss(list_timer *li, st_global *ad);
                int size_list_timer_b(list_timer_b li);
                void push_back_timer_b(list_timer_b *li, sfVector2f dir, \
                sfVector2f pos);
                void print_list_shoot_b(list_timer_b *li, sfSprite *sprite, \
                st_global *ad);
                void pop_position_timer_b(list_timer_b *list, int index);
                void reindex_timer_b(list_timer_b *li);
    // PLANET_CARD
        // PLANET_CARD
            void display_planet_card(st_global *g);
            void planet_card_display_sprite_text(st_global *g);
            void text_draw_planet_card(st_global *g);
            void display_planet_card_bis(st_global *g, list_planet planets);
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
            void arrow_events_trade_down(st_global *g);
            void arrow_events_trade_down_bis(st_global *g);
            void arrow_events_trade_up(st_global *g);
            void arrow_events_trade_up_bis(st_global *g);
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
            void text_title_credits_trade_card(st_global *g, \
            list_planet planets);
            void check_buy(st_global *g, list_planet planets);
            void check_buy_bis(st_global *g, list_planet planets);
        // ITEM_POSITION_TRADE_CARD
            void item_position_trade_card_one(st_global *g, int i, int x, \
            list_planet planets);
            void item_position_trade_card_two(st_global *g, int i, int x, \
            list_planet planets);
            void item_position_trade_card_three(st_global *g, int i, int x, \
            list_planet planets);
            void items_placement_trade_card(st_global *g, int i, int y, \
            list_planet planets);
    // MODULE_CARD
        // GENERATE_MODULE_CARD
            module_card_s *generate_module_card(void);
            void destroy_module_card(module_card_s *module_card);
        // MODULE_CARD
            void buy_module(st_global *g, list_planet pl);
            void display_module_card(st_global *g);
            void set_init_position_module(st_global *g);
            void display_texts_module_card(st_global *g, list_planet planets);
            void display_planet_module_card(st_global *g);
            void rect_module_position(st_global *g);
            void print_nb(st_global *g, list_planet pl);
        // TEXT_MODULE_CARD
            void text_title_credits_module_card(st_global *g, \
            list_planet planets);
            void text_price_module_card(st_global *g, list_planet pl);
            void text_price_module_card_bis(st_global *g, list_planet pl);
            void display_texts_module_card_bis(st_global *g);
        // ARROWS
            void arrow_events_module_down(st_global *g);
            void arrow_events_module(st_global *g);
            void arrow_up_module_card(st_global *g);
            void arrow_up_module_card(st_global *g);
            void arrow_up_module(st_global *g);
    // UI_GAME
        // GENERATE_UI_GAME
            ui_game_s *generate_ui_game(void);
            void destroy_ui_game(ui_game_s *ui);
            void set_rectangle_ui_game_life(ui_game_s *ui);
            void set_rectangle_ui_game_credits(ui_game_s *ui);
            void set_rectangle_ui_game_xp(ui_game_s *ui);
        // UI_GAME
            void display_lvl(st_global *ad);
            void set_position_ui_game(st_global *g);
            void rectangle_display_ui_game_bis(st_global *g);
            void display_ui_game(st_global *g);
            void rectangle_display_ui_game(st_global *g);
            void item_craft_ui_game(st_global *g);
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
            void switch_volume_settings(st_global *g);
            void events_pause_up_bis(st_global *g);
            void events_pause_down_bis(st_global *g);
        // EVENTS2.C
            void check_pressed_enter_menu(st_global *g);
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
                void events_pause_settings_right_bis(st_global *g);
                void events_pause_settings_left_bis(st_global *g);
            // VOLUME_EVENTS_SETTINGS
                void switch_pause_settings(st_global *g);
                void volume_top_less(st_global *g, int x, int y);
                void volume_top_more(st_global *g, int x, int y);
                void volume_bottom_less(st_global *g, int x, int y);
                void volume_bottom_more(st_global *g, int x, int y);
        // TARGET_INDICATOR
                sfVector2f target_indicator(st_global *ad, sfVector2f obj);
                void print_target_indicator(st_global *ad);
                bool is_on_screen(st_global *ad, sfVector2i pl);

// MESSAGES
    // ADDITIONNAL_MSG
        int backslash_n_counter(st_global *global);
        char *cpy_to_up_text(st_global *g);
    // BACKSLASH_ADD
        cpy_backslash_s *generate_cpy(void);
        void automatically_set_text_max(st_global *g);
        char *manage_copy_n(char *str, st_global *g);
        char *add_backslash_n_to_space(char *str, st_global *g);
        char *add_backslash_n(char *str, st_global *g);
    // DESTROY_MSG
        void destroy_message(st_global *global);
    // DISPLAY_MSG
        st_text *generate_message(void);
        void display_msg(st_global *g);
        void clock_dialogue_text_line1(st_global *g);
        void clock_dialogue_text_line2(st_global *g);
        void clock_dialogue_text_line3(st_global *g);
    // SET_MESSAGE
        void dialogue_text_settings(st_global *global);
        void dialogue_rectangle_settings(st_global *g);
        void dialogue_rectangle_settings_bis(st_global *g);
        void dialogue_text(st_global *global);
        void add_message(st_global *global, char *str, int delay);

// SOUNDS
    // SOUNDS
        st_global_sfx *generate_sound(void);
        void set_volume_sfx(st_global *g, float volume);
        void destroy_sound(st_global_sfx *sound);

#endif /* !MY_RPG_H_ */