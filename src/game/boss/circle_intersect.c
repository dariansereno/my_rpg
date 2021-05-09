/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** circle_intersect
*/

#include "my_rpg.h"

sfVector2f calculate_coord_intersect(int d, float phi, sfVector2f c)
{
    sfVector2f pos;

    pos.x = d * cos(phi) + c.x;
    pos.y = d * sin(phi) + c.y;
    return (pos);
}

int circle_intersect(sfVector2f c1, sfVector2f c2, int d1, int d2)
{
    float a = (float)d2;
    float b = (float)d1;
    float c = sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) *
    (c1.y - c2.y));
    float A = acos((b * b + c * c - a * a) / (2 * b * c));
    float theta = atan2(c2.y - c1.y, c2.x - c1.x);
    float phi1 = theta+A;
    float phi2 = theta-A;
    sfVector2f p3;
    sfVector2f p4;

    if (d1 < 0 || d2 < 0)
        return (0);
    p3 = calculate_coord_intersect(d1, phi1, c1);
    p4 = calculate_coord_intersect(d1, phi2, c1);
    if (isnan(p3.x) && isnan(p3.y) && isnan(p4.x) && isnan(p4.y))
        return (0);
    return (1);
}