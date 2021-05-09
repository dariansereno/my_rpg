/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** direction
*/

#include "my_rpg.h"

int deduct_dir_from_last_key(st_global *ad)
{
    int x = 0;

    switch (x) {
        case 0:
            if (ad->last_key_pressed.Z == true)
                return (0);
            x++;
        case 1:
            if (ad->last_key_pressed.D == true)
                return (2);
            x++;
        case 2:
            if (ad->last_key_pressed.S == true)
                return (4);
            x++;
        case 3:
            if (ad->last_key_pressed.Q == true)
                return (6);
    }
    return (0);
}

int deduct_dir_3(st_global *ad)
{
    int x = 6;

    switch (x) {
        case 6:
            if (ad->key_pressed.Q == true && ad->key_pressed.Z == false
            && ad->key_pressed.D == false && ad->key_pressed.S == false)
                return (6);
            x++;
        case 7:
            if (ad->key_pressed.Z == true && ad->key_pressed.Q == true
            && ad->key_pressed.S == false && ad->key_pressed.D == false)
                return (7);
    }
    return (deduct_dir_from_last_key(ad));
}

int deduct_dir_2(st_global *ad)
{
    int x = 3;

    switch (x) {
        case 3:
            if (ad->key_pressed.S == true && ad->key_pressed.D == true
            && ad->key_pressed.Z == false && ad->key_pressed.Q == false)
                return (3);
            x++;
        case 4:
            if (ad->key_pressed.S == true && ad->key_pressed.Z == false
            && ad->key_pressed.D == false && ad->key_pressed.Q == false)
                return (4);
            x++;
        case 5:
            if (ad->key_pressed.S == true && ad->key_pressed.Q == true
            && ad->key_pressed.Z == false && ad->key_pressed.D == false)
                return (5);
            x++;
    }
    return (deduct_dir_3(ad));
}

int deduct_dir(st_global *ad)
{
    int x = 0;

    switch (x) {
        case 0:
            if (ad->key_pressed.Z == true && ad->key_pressed.Q == false
                && ad->key_pressed.S == false && ad->key_pressed.D == false)
                return (0);
            x++;
        case 1:
            if (ad->key_pressed.Z == true && ad->key_pressed.D == true
            && ad->key_pressed.S == false && ad->key_pressed.Q == false)
                return (1);
            x++;
        case 2:
            if (ad->key_pressed.D == true && ad->key_pressed.Z == false
            && ad->key_pressed.S == false && ad->key_pressed.Q == false)
                return (2);
            x++;
    }
    return (deduct_dir_2(ad));
}