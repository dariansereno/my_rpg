// /*
// ** EPITECH PROJECT, 2021
// ** GALAXY
// ** File description:
// ** ennemies_generation
// */

// #include "my_rpg.h"

// // CREER ST_GLOBAL ENNEMIES AVEC UN SFTEXTURE

// sfVector2f position_generate_near_planet(list_planet planet, st_global *ad,
// float radius)
// {
//     float angle = ((float)rand()/(float)(RAND_MAX/1)) * M_PI * 2;
//     float x = cos(angle) * radius + (float)planet->planet.pos.x;
//     float y = sin(angle) * radius + (float)planet->planet.pos.y;

//     return ((sfVector2f){x, y});
// }

// st_ennemies generate_ennemies(st_global *ad)
// {
//     st_ennemies ennemies;
    
//     ennemies.pos = position_generate_near_planet(planet, ad);
//     ennemies.rect = sfIntRect
// }

// void clock_ennemies_generation(list_planet li, st_global *ad)
// {
//     st_ennemies *ennemies;

//     li->timer.time = sfClock_getElapsedTime(li->timer.clock);
//     li->timer.seconds = li->timer.time.microseconds / 1000000.0;
//     if (li->spawning.seconds > li->ennemies_spawn) {
//         push_back_ennemies(ad->ennemies, )
//     }
// }

// void ennemies_spawning(st_global *ad)
// {
//     list_planet li = ad->planets->planets;

//     while (li != NULL) {
//         if (li->on_screen == true && li->planet.type >= 21 &&
//         li->planet.type <= 23) {
//             // clock_ennemies_generation(li);
//             sfSprite_setPosition(ad->ui->interacting->sprite, position_generate_near_planet(li, ad, 300));
//             sfRenderWindow_drawSprite(ad->window->window,
//             ad->ui->interacting->sprite, NULL);
//             printf("oui monsieur\n");
//         }
//         li = li->next;
//     }
// }