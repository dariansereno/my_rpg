/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** end
*/

#include "my_rpg.h"

st_end *generate_end(void)
{
    st_end *end = my_malloc(sizeof(*end));

    end->font = sfFont_createFromFile("contents/fonts/myfont.otf");
    end->text = sfText_create();
    end->ui[0] = generate_object((sfVector2f){409, 327}, \
    (sfIntRect){0, 0, 1102, 478}, "contents/ui/end/bg.png");
    end->ui[1] = generate_object((sfVector2f){487, 225}, \
    (sfIntRect){0, 0, 953, 202}, "contents/ui/end/victory.png");
    end->ui[2] = generate_object((sfVector2f){645, 231}, \
    (sfIntRect){0, 0, 635, 373}, "contents/ui/end/game_over.png");
    end->ui[3] = generate_object((sfVector2f){1024, 675}, \
    (sfIntRect){0, 0, 299, 64}, "contents/ui/end/rect.png");
    sfText_setFont(end->text, end->font);
    end->existing = false;
    end->pressed = false;
    end->pos_rect = 2;
    return (end);
}

void position_end(st_global *g)
{
    if (g->key_pressed.Enter)
        if (g->ui->end->pressed) {
            switch (g->ui->end->pos_rect) {
                case 1:
                    sfRenderWindow_close(g->window->window);
                    g->ui->end->existing = false;
                    break;
                case 2:
                    g->window->screen = 2;
                    g->ui->end->existing = false;
                    break;
                default:
                    break;
            }
            g->ui->end->pressed = false;
        }
}

void display_end(st_global *g)
{
    if (g->ui->end->existing) {
        position_end(g);
        sfSprite_setPosition(g->ui->end->ui[0]->sprite, (sfVector2f){409, 327});
        sfSprite_setPosition(g->ui->end->ui[1]->sprite, (sfVector2f){487, 225});
        sfSprite_setPosition(g->ui->end->ui[2]->sprite, (sfVector2f){645, 231});
        end_rect_left(g);
        end_rect_right(g);
        rect_position_end(g);
        position_bg_end(g);
        position_win(g);
        text_position_end(g);
    }
}

void position_win(st_global *g)
{
    if (g->win) {
        sfSprite_setPosition(g->ui->end->ui[1]->sprite, (sfVector2f)
        {sfSprite_getPosition(g->ui->end->ui[1]->sprite).x +\
        g->ship->viewrect.left, \
        sfSprite_getPosition(g->ui->end->ui[1]->sprite).y + \
        g->ship->viewrect.top});
        sfRenderWindow_drawSprite(g->window->window, \
        g->ui->end->ui[1]->sprite, \
        NULL);
    } else {
        sfSprite_setPosition(g->ui->end->ui[2]->sprite, (sfVector2f)
        {sfSprite_getPosition(g->ui->end->ui[2]->sprite).x +\
        g->ship->viewrect.left, \
        sfSprite_getPosition(g->ui->end->ui[2]->sprite).y + \
        g->ship->viewrect.top});
        sfRenderWindow_drawSprite(g->window->window, \
        g->ui->end->ui[2]->sprite, \
        NULL);
    }
}

void destroy_end(st_end *end)
{
    destroy_object(end->ui[0]);
    destroy_object(end->ui[1]);
    destroy_object(end->ui[2]);
    destroy_object(end->ui[3]);
    sfText_destroy(end->text);
    sfFont_destroy(end->font);
}