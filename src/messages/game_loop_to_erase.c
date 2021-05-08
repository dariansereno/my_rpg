// #include "my_rpg.h"

// st_global *generate_global(void)
// {
//     st_global *global = malloc(sizeof(*global));

//     global->text = my_malloc(sizeof(*global->text));
//     global->text->delay = 0;
//     global->text->existing = sfFalse;
//     return (global);
// }

// int game_loop_2()
// {
//     sfEvent event;
//     sfRenderWindow *window;
//     sfVideoMode mode = {WIDTH, HEIGHT, 32};

//     window = sfRenderWindow_create(mode, "my_defender", sfResize | sfClose, \
//     NULL);
//     sfRenderWindow_setFramerateLimit(window, 60);
//     sfRenderWindow_setMouseCursorVisible(window, sfTrue);
//     st_global *global = generate_global();

//     if (window != NULL) {
//         while (sfRenderWindow_isOpen(window)) {
//             sfRenderWindow_clear(window, sfWhite);
//             while (sfRenderWindow_pollEvent(window, &event)) {
//                 if (event.type == sfEvtClosed)
//                     sfRenderWindow_close(window);
//                 else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
//                     sfRenderWindow_close(window);
//                 if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD)
//                     // dialogue_text(global, "Bonjour à toi jeune entrepreneur, pour ta première quête..A", 100);
//                     add_message(global, "Bonjour à toi jeune entrepreneur, pour ta première quête... Tu vas devoir trouver le joyau qui est dispoBonjour à toi jeune entrepreneur, pour ta première quête... Tu vas devoir trouver le joyau qui est disposé être au fond de la chaîne des Andesen Amérique LatineBonjour à toi jeune entrepreneur, pour ta première quête... Tu vas devoir trouver le joyau qui est disposé être au fond de la chaîne des Andesen Amérique LatineBonjour à toi jeune entrepreneur, pour ta première quête... Tu vas devoir trouver le joyau qui est disposé être au fond de la chaîne des Andesen Amérique LatineBonjour à toi jeune entrepreneur, pour ta première quête... Tu vas devoir trouver le joyau qui est disposé être au fond de la chaîne des Andesen Amérique LatineBonjour à toi jeune entrepreneur, pour ta première quête... Tu vas devoir trouver le joyau qui est disposé être au fond de la chaîne des Andesen Amérique Latinesé être au fond de la chaîne des Andesen Amérique Latine", 9000);
//                 if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter) {
//                     if (global->text->existing == sfTrue) {
//                         int counter = backslash_n_counter(global);
//                         if (counter >= 3 && sfRectangleShape_getSize(global->text->text_r3).x <= 0) {
//                             sfRectangleShape_setSize(global->text->text_r1, (sfVector2f){1160, -40});
//                             sfRectangleShape_setSize(global->text->text_r2, (sfVector2f){1160, -40});
//                             sfRectangleShape_setSize(global->text->text_r3, (sfVector2f){1160, -40});
//                             global->text->str = cpy_to_up_text(global);
//                             sfText_setString(global->text->text, global->text->str);
//                         }
//                         if (counter < 3 && sfRectangleShape_getSize(global->text->text_r3).x <= 0)
//                             destroy_message(global);
//                     }
//                 }
//             }
//             display_msg(window, global);
//             sfRenderWindow_display(window);
//         }
//         sfRenderWindow_destroy(window);
//     }
//     return (0);
// }