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
// MAP
    // GENERATION_MAP.C
    // MATH.C
        sfVector2i *scatter_plot(scatter math);
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
