/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** move_diagonal
*/

#include "my_rpg.h"


void go_downleft(st_global *ad)
{
    if (ad->key_pressed.S == true && ad->key_pressed.Q == true) {
        printf("moule\n");
        move_downleft(ad);
    }
}

void go_upright(st_global *ad)
{
    if (ad->key_pressed.Z == true && ad->key_pressed.D == true) {
        printf("huitre\n");
        move_upright(ad);}
}

void go_upleft(st_global *ad)
{
    if (ad->key_pressed.Q == true && ad->key_pressed.Z == true) {
        printf("chatte\n");
        move_upleft(ad);
    }
}

void go_downright(st_global *ad)
{
    if (ad->key_pressed.S == true && ad->key_pressed.D == true) {
        printf("urêtre de chinois en convalescence");
        move_downright(ad);
    }
}