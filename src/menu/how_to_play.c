/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** how_to_play
*/

#include "game.h"

void how_to_play(st_global *global, sfRenderWindow *window)
{
    sfEvent event;

    global->variable->menu = 0;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        while (sfRenderWindow_pollEvent(window, &event)) {
            events_close(event, window);
            events_how_to_play(event, global, window);
        }
        sfRenderWindow_drawSprite(window, global->how_to_play->sprite, NULL);
        sfRenderWindow_display(window);
    }
}