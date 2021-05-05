// /*
// ** EPITECH PROJECT, 2021
// ** GALAXY
// ** File description:
// ** list_action2
// */

// #include "my_rpg.h"

// list_planet pop_back_planet(list_planet list)
// {
//     list_elem_planet *temp = NULL;
//     list_elem_planet *buf = NULL;

//     if (list == NULL)
//         return (NULL);
//     if (list->next == NULL) {
//         free(list);
//         list = NULL;
//         return (NULL);
//     }
//     temp = list;
//     buf = list;
//     while (temp->next != NULL) {
//         buf = temp;
//         temp = temp->next;
//     }
//     buf->next = NULL;
//     destroy_planet(temp);
//     free(temp);
//     temp = NULL;
//     return (list);
// }

// list_planet planet_from_index(int index, list_planet li)
// {
//     list_planet temp = li;

//     if (temp == NULL)
//         return (NULL);
//     while (temp->index != index)
//         temp = temp->next;
//     if (temp == NULL)
//         return (NULL);
//     return (temp);
// }

// void print_planet_list_stat(list_planet li)
// {
//     while (li != NULL){
//         printf("%d, %d, %d, %d, %d, %d, %d, %d\n", li->planet.stats.co2, li->planet.stats.h2o, li->planet.stats.h,
//         li->planet.stats.n2, li->planet.stats.N, li->planet.stats.o, li->planet.stats.pressure, li->planet.climate);
//         li = li->next;
//     }
// }