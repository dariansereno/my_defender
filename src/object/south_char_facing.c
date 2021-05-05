/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** south_char_facing
*/

#include "game.h"

void facing_south_east(list_elem_char *character)
{
    if (character->variable.previous_facing != 3) {
        character->object->animation.left = 1020;
        character->object->animation.top = 166;
    }
    character->object->position.x += 1;
    character->object->position.y += 1;
    character->object->animation.top = 166;
    character->variable.previous_facing = 3;
    character->object->animation.left += 85;
    if (character->object->animation.left >= 1530)
        character->object->animation.left = 1020;
    sfClock_restart(character->object->timer->clock);
}

void facing_south(list_elem_char *character)
{
    if (character->variable.previous_facing != 4) {
        character->object->animation.left = 1530;
        character->object->animation.top = 166;
    }
    character->object->position.y += 1;
    character->object->animation.top = 166;
    character->variable.previous_facing = 4;
    character->object->animation.left += 85;
    if (character->object->animation.left >= 2040)
        character->object->animation.left = 1530;
    sfClock_restart(character->object->timer->clock);
}

void facing_south_west(list_elem_char *character)
{
    if (character->variable.previous_facing != 5) {
        character->object->animation.left = 510;
        character->object->animation.top = 166;
    }
    character->object->position.x -= 1;
    character->object->position.y += 1;
    character->object->animation.top = 166;
    character->variable.previous_facing = 5;
    character->object->animation.left += 85;
    if (character->object->animation.left >= 1020)
        character->object->animation.left = 510;
    sfClock_restart(character->object->timer->clock);
}

void facing_west(list_elem_char *character)
{
    if (character->variable.previous_facing != 6) {
        character->object->animation.left = 0;
        character->object->animation.top = 166;
    }
    character->object->position.x -= 1;
    character->object->animation.top = 166;
    character->variable.previous_facing = 6;
    character->object->animation.left += 85;
    if (character->object->animation.left >= 510)
        character->object->animation.left = 0;
    sfClock_restart(character->object->timer->clock);
}