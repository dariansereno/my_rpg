/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** list_action2
*/

#include "my_rpg.h"

list_inventory pop_back_inventory(list_inventory list)
{
    list_elem_inventory *temp = NULL;
    list_elem_inventory *buf = NULL;

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
    // destroy_inventory(temp); a faire
    free(temp);
    temp = NULL;
    return (list);
}

// list_inventory inventory_from_index(int index, list_inventory li)
// {
//     list_inventory temp = li;

//     if (temp == NULL)
//         return (NULL);
//     while (temp->index != index)
//         temp = temp->next;
//     if (temp == NULL)
//         return (NULL);
//     return (temp);
// }