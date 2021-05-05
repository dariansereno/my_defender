/*
** EPITECH PROJECT, 2021
** character
** File description:
** my_defender
*/

#include "game.h"

void display_character(sfRenderWindow *window, sfSprite *sprite, sfIntRect rect)
{
    sfSprite_setTextureRect(sprite, rect);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}