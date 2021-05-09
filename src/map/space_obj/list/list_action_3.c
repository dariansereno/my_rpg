/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_action_3
*/

#include "my_rpg.h"

list_spaceobj pop_back_spaceobj(list_spaceobj list)
{
    list_elem_spaceobj *temp = NULL;
    list_elem_spaceobj *buf = NULL;

    if (list == NULL)
        return (NULL);
    if (list->next == NULL) {
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
    temp = NULL;
    return (list);
}