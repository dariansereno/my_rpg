/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_action2
*/

#include "my_rpg.h"

list_planet pop_back_planet(list_planet list)
{
    list_elem_planet *temp = NULL;
    list_elem_planet *buf = NULL;

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
    destroy_planet(temp);
    free(temp);
    temp = NULL;
    return (list);
}