/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_boss
*/

#include "my_rpg.h"

// sfVector2f boss_spawning(st_global *ad)
// {
//     sfVector2f pos = {0, 0};
//     bool is_good = false;

//     while (!is_good) {
//         pos.x = (float)random_between(0, 80000);
//         pos.y = (float)random_between(0, 80000);
//         if (!(is_on_planet(ad, pos)))
//             is_good = true;
//     }
//     return (pos);
// }

// st_boss *generate_boss(st_global *ad)
// {
//     st_boss *boss = malloc(sizeof(*boss));
//     sfVector2f pos = boss_spawning(ad);

//     boss->life = 10000;
//     boss->boss = generate_object(pos, (sfIntRect){0, 0, 48, 48},
//     "contents/img/sp/boss.png");
//     boss->atk_mode = 0;
//     boss->bg = generate_object(pos, (sfIntRect){0, 0, 960, 540}, 
//     "ressources/bossbg.png");
//     return (boss);
// }
