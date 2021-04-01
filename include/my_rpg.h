/*
** EPITECH PROJECT, 2021
** header
** File description:
** my_rpg.h
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <math.h>
#include "structs.h"
#include <stdio.h>


// GAME
    // GAME.C
        int game_loop(void);
    // MOVE.C
        void go_right(st_global *ad);
        void go_left(st_global *ad);
        void go_down(st_global *ad);
        void go_up(st_global *ad);
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
// MAP
    // GENERATION_MAP.C
        list_planet generate_all_map(void);
    // MATH.C
        sfVector2i *scatter_plot(scatter math);
        int random_between(int start, int stop);
    // GENERATE_PLANET_TYPE.C
        st_planet *general_all_planets(sfVector2i *pos, int size);
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
            void print_planet_list(list_planet li);
// STRUCTS
    st_global *ini(void);
    structs_t *all_dat(void);


#endif /* !MY_RPG_H_ */
