/*
** EPITECH PROJECT, 2021
** animations
** File description:
** my_defender
*/

#include "game.h"

void clock_animation(sfClock *clock, float speed)
{
    sfTime time;
    float seconds = 0;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000;
    if (seconds > speed)
        sfClock_restart(clock);
}