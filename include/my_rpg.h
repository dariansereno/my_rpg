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

// GAME
    // GAME.C
        int game_loop(void);
void dialogue_text(st_global *global, const char *str, int delay);
void display_dialogue_text(sfRenderWindow *window, st_global *global);
void clock_dialogue_text_line1(st_global *global);
void clock_dialogue_text_line2(st_global *global);
void clock_dialogue_text_line3(st_global *global);

#endif /* !MY_RPG_H_ */
