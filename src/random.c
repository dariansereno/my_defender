/*
** EPITECH PROJECT, 2021
** random nb
** File description:
** my_defender
*/

#include "game.h"

int random_between(int start, int stop)
{
    static bool initialized = false;
    unsigned int seed;
    FILE *in = fopen("/dev/random", "r");

    if (fread(&seed, sizeof(seed), 1, in) == 1)
        fclose(in);
    if (start > stop)
        return random_between(stop, start);
    if (start == stop)
        return (start);
    if (!initialized) {
        initialized = true;
        srand(seed);
    }
    fclose(in);
    return (rand()%((stop+1)-start) + start);
}