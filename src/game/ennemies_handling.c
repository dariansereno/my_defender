/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** ennemies_handling
*/

#include "game.h"

list_char generate_random_char_between(int min, int max)
{
    int total = random_between(min, max);
    list_char li = NULL;

    for (int i = 0; i < total; i++) {
        li = push_back_char(li, generate_object("contents/img/char.png", \
        (sfVector2f){random_between(250, 400), 100}, (sfIntRect){0, 165, 85, 165}), \
        (st_char_variables){.dead = 0, .life = 100, .position = \
        (sfVector2f){0, 0 + (i * 10)}, .facing = 4, .previous_facing = -1, \
        .index = 0, .hit = true, .mode = 0, .pause = false});
    }
    return (li);
}