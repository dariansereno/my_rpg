/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** add_backslash_n
*/

#include "my_rpg.h"

cpy_backslash_s *generate_cpy(void)
{
    cpy_backslash_s *cpy_backslash = my_malloc(sizeof(*cpy_backslash));

    cpy_backslash->begin = 0;
    cpy_backslash->end = 0;
    cpy_backslash->len = 0;
    cpy_backslash->space = false;
    return (cpy_backslash);
}

void automatically_set_text_max(st_global *g)
{
    char *s1 = my_malloc(sizeof(char) * (my_strlen(g->text->str) + 1));

    my_strcpy(s1, g->text->str);
    for (g->text->c->end = 0; s1[g->text->c->end]; g->text->c->end++, \
    g->text->c->len = (g->text->c->end - g->text->c->begin) * 13.8) {
        if (g->text->c->len > 1140)
            s1 = manage_copy_n(s1, g);
        g->text->c->len = 0;
    }
    g->text->str = s1;
}

char *manage_copy_n(char *str, st_global *g)
{
    if (str[g->text->c->end] == ' ')
        str[g->text->c->end] = '\n';
    else {
        str = add_backslash_n_to_space(str, g);
        if (g->text->c->space == false)
            str = add_backslash_n(str, g);
    }
    g->text->c->space = false;
    g->text->c->begin = g->text->c->end + 1;
    return (str);
}

char *add_backslash_n_to_space(char *str, st_global *g)
{
    for (int j = g->text->c->end, k = 0; k < 10; j--, k++) {
        if (j == 0) {
            return (str);
        }
        if (str[j] == ' ') {
            str[j] = '\n';
            g->text->c->space = true;
            return (str);
        }
    }
    return (str);
}

char *add_backslash_n(char *str, st_global *g)
{
    char *str1 = NULL;
    char *str2 = NULL;
    char *result = NULL;

    str1 = my_malloc(sizeof(char) * (g->text->c->end - g->text->c->begin + 2));
    my_strncpy(str1, str + g->text->c->begin, \
    g->text->c->end - g->text->c->begin);
    str1[g->text->c->end - g->text->c->begin] = 0;
    my_strcat(str1, "\n");
    str1[g->text->c->end - g->text->c->begin + 1] = 0;
    g->text->c->begin = g->text->c->end;
    str2 = my_malloc(sizeof(char) * (my_strlen(str) - g->text->c->begin + 2));
    my_strncpy(str2, str + g->text->c->begin, \
    my_strlen(str) - g->text->c->begin);
    str2[my_strlen(str) - g->text->c->begin] = 0;
    result = my_malloc(sizeof(char) * (my_strlen(str) + 2));
    my_strcpy(result, str1);
    my_strcat(result, str2);
    result[my_strlen(str)] = 0;
    return (result);
}