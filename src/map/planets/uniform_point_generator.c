/*
** EPITECH PROJECT, 2021
** GALAXY
** File description:
** uniform_point_generator
*/

#include "my_rpg.h"

double germ(int g, int q)
{
    int n = g % q;
    return (n);
}

double alea(int *n, int p, int q)
{
    *n = *n * p % q;
    return ((double)(*n - 1) / (q - 2));
}

int random_between(int start, int stop)
{
    static bool initialized = false;
    unsigned int seed;
    FILE *in = fopen("/dev/random", "r");

    if (fread(&seed, sizeof(seed), 1, in) == 1)
        fclose(in);
    if (start > stop) {
        fclose(in);
        return random_between(stop, start);
    }
    if (start == stop){
        fclose(in);
        return (start);
    }
    if (!initialized) {
        initialized = true;
        srand(seed);
    }
    fclose(in);
    return (rand()%((stop+1)-start) + start);
}

sfVector2i *scatter_plot(scatter math)
{
    sfVector2i *position = malloc(sizeof(sfVector2i) * math.kmax);
    int n2 = 1;
    int i = 0;
    int n = germ(math.germ, math.q);
    int *y = malloc(sizeof(int) * math.interval);

    for (int k = 1; k < math.kmax; k++) {
        i = floor(alea(&n, math.p, math.q) * math.interval);
        n2 = n;
        if (i > 0 && i < math.interval - 1) {
            y[i] = y[i] + 1;
            position[k].x = i;
            position[k].y = floor(alea(&n2, math.p, math.q) * math.interval);
        }
    }
    return (position);
}