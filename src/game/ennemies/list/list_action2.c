/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_action2
*/

#include "my_rpg.h"

list_ennemies pop_back_ennemies(list_ennemies list)
{
    list_elem_ennemies *temp = NULL;
    list_elem_ennemies *buf = NULL;

    if (list == NULL)
        return (NULL);
    if (list->next == NULL) {
        free(list);
        list = NULL;
        return (NULL);
    }
    temp = list;
    buf = list;
    while (temp->next != NULL) {
        buf = temp;
        temp = temp->next;
    }
    buf->next = NULL;
    // destroy_ennemies(temp); a faire
    free(temp);
    temp = NULL;
    return (list);
}

list_ennemies ennemies_from_index(int index, list_ennemies li)
{
    list_ennemies temp = li;

    if (temp == NULL)
        return (NULL);
    while (temp->index != index)
        temp = temp->next;
    if (temp == NULL)
        return (NULL);
    return (temp);
}

void print_ennemies_list_pos(list_ennemies li)
{
    if (li == NULL) {
        printf("EMPTY !\n");
        return ;
    }
    while (li != NULL){
        printf("Ennemies n*%d = [%f, %f]\n", li->index, li->ennemies.pos.x, li->ennemies.pos.y);
        li = li->next;
    }
}