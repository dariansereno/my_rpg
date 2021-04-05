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
    // INPUTS
        // CHANGE_KEY.C
            void more_key_change(st_global *ad);
            void extra_change(st_global *ad);
            void change_key_press(st_global *ad);
        // INTERACTION.C
            void interaction_input(st_global *ad);
    // ENNEMIES
        // ENNEMIES_GENERATION.C
            sfVector2f position_generate_near_planet(list_planet planet, st_global *ad,
            float radius);
            void ennemies_spawning(st_global *ad);
        // ENNEMIES_CONDITION.C
            bool is_on_planet(st_global *ad, sfVector2f object);
            bool is_on_ennemies(st_global *ad, list_ennemies ennemies, sfVector2f object);
        // LIST
            void push_back_ennemies(list_ennemies *li, st_ennemies ennemies);
            void print_ennemies_list_pos(list_ennemies li);
            int size_list_ennemies(list_ennemies li);
            void print_ennemies_list(list_ennemies li, sfRenderWindow *window);
    // OBJECT
        st_object *generate_object(sfVector2f pos, sfIntRect rect, char *texturepath);
        void destroy_object(st_object *object);
    // GAME.C
    int game_loop(void);

// GAME.C
int game_loop_2();
void dialogue_text(st_global *global, const char *str, int delay);
void display_dialogue_text(sfRenderWindow *window, st_global *global);
void clock_dialogue_text_line1(st_global *global);
void clock_dialogue_text_line2(st_global *global);
void clock_dialogue_text_line3(st_global *global);

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
            void pop_position_planet(list_planet *list, sfVector2f pos);
            int size_list_planet(list_planet li);
            void print_planet_list(list_planet li, sfRenderWindow *window);
            void set_texture_planets(list_planet *li, st_planet_global *g);
            list_planet pop_back_planet(list_planet list);
            list_planet planet_from_index(int index, list_planet li);
// STRUCTS
    st_global *ini(void);
    structs_t *all_dat(void);
    void destroy_global(st_global *global);
// OBJECT.C
    st_object *generate_object(sfVector2f pos, sfIntRect rect,
    char *texturepath);

// UI
    // GENERATE_UI.C
        void destroy_ui(st_ui *ui);
        st_ui *generate_ui();
    // GAME
        // INTERACTION.C
            void display_interaction(st_global *ad);
            char *int_to_str(int nb);

#endif /* !MY_RPG_H_ */
