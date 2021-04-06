// typedef struct cpy_backslash_t {
//     int end;
//     int begin;
//     float len;
//     bool space;
// } cpy_backslash_s;

// typedef struct st_text_s {
//     sfSprite *arrow_s;
//     sfTexture *arrow_t;
//     sfRectangleShape *whi_r;
//     sfRectangleShape *whi_r2;
//     sfRectangleShape *text_r1;
//     sfRectangleShape *text_r2;
//     sfRectangleShape *text_r3;
//     sfRectangleShape *text_r4;
//     sfText *text;
//     sfFont *font;
//     sfBool existing;
//     sfClock *clock;
//     cpy_backslash_s *c;
//     char *str;
//     int delay;
// } st_text;

// int game_loop_2();
// void dialogue_text(st_global *global);
// void display_msg(sfRenderWindow *window, st_global *global);
// void clock_dialogue_text_line1(st_global *global);
// void clock_dialogue_text_line2(st_global *global);
// void clock_dialogue_text_line3(st_global *global);
// char *automatically_set_text_max(st_global *g);
// cpy_backslash_s *generate_cpy();
// char *manage_copy_n(char *str, st_global *g);
// char *add_backslash_n_to_space(char *str, st_global *g);
// char *add_backslash_n(char *str, st_global *g);
// char *cpy_to_up_text(st_global *global);
// void dialogue_text_settings(st_global *global);
// int backslash_n_counter(st_global *global);
// void add_message(st_global *global, char *str, int delay);
// void destroy_message(st_global *global);
// void dialogue_rectangle_settings_bis(st_global *g);

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
//     sfVideoMode mode = {1920, 1080, 32};

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
//             display_dialogue_text(window, global);
//             sfRenderWindow_display(window);
//         }
//         sfRenderWindow_destroy(window);
//     }
//     return (0);
// }