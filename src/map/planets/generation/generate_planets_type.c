/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** generate_planets
*/

#include "my_rpg.h"

planet_climate climate_from_type_2(planet_type planet)
{
    if ((planet >= 14 && planet <= 19) || (planet >= 21 && planet <= 23))
        return (NORMAL);
    else if ((planet >= 24 && planet <= 28) || planet == 20)
        return (COLD);
    else
        return (FROSTEN);
}

planet_climate climate_from_type(planet_type planet)
{
    int i = 1;
    if (planet >= 0 && planet <= 6)
        return (ARDENT);
    else if (planet >= 7 && planet <= 13)
        return (WARM);
    else
        return (climate_from_type_2(planet));
}

planet_animation animation_from_type(planet_type planet)
{
    if (planet >= 7 && planet <= 20)
        return (ANIMATED);
    return (NON_ANIMATED);
}