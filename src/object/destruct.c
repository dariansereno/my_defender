/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** destrucT
*/

#include "game.h"

void destruct_object(st_object *object)
{
    sfClock_destroy(object->timer->clock);
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
}