/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** north_char_animation
*/

#include "game.h"

void facing_north_west(list_elem_char *character)
{
    if (character->variable.previous_facing != 7) {
        character->object->animation.left = 1530;
        character->object->animation.top = 0;
    }
    character->object->position.x -= 1;
    character->object->position.y -= 1;
    character->object->animation.top = 0;
    character->variable.previous_facing = 7;
    character->object->animation.left += 85;
    if (character->object->animation.left >= 2040)
        character->object->animation.left = 1530;
    sfClock_restart(character->object->timer->clock);
}

void facing_north(list_elem_char *character)
{
    if (character->variable.previous_facing != 0) {
        character->object->animation.left = 1020;
        character->object->animation.top = 0;
    }
    character->object->position.y -= 1;
    character->object->animation.top = 0;
    character->variable.previous_facing = 0;
    character->object->animation.left += 85;
    if (character->object->animation.left >= 1530)
        character->object->animation.left = 1020;
    sfClock_restart(character->object->timer->clock);
}

void facing_north_east(list_elem_char *character)
{
    if (character->variable.previous_facing != 1) {
        character->object->animation.left = 510;
        character->object->animation.top = 0;
    }
    character->object->position.x += 1;
    character->object->position.y -= 1;
    character->object->animation.top = 0;
    character->variable.previous_facing = 1;
    character->object->animation.left += 85;
    if (character->object->animation.left >= 1020)
        character->object->animation.left = 510;
    sfClock_restart(character->object->timer->clock);
}

void facing_east(list_elem_char *character)
{
    if (character->variable.previous_facing != 2) {
        character->object->animation.left = 0;
        character->object->animation.top = 0;
    }
    character->object->position.x += 1;
    character->object->animation.top = 0;
    character->variable.previous_facing = 2;
    character->object->animation.left += 85;
    if (character->object->animation.left >= 510)
        character->object->animation.left = 0;
    sfClock_restart(character->object->timer->clock);
}

void facing_stop(list_elem_char *character)
{
    return ;
}