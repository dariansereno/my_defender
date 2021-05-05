/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** win
*/

#include "game.h"

void win_conditions(st_global *global, sfRenderWindow *window)
{
    list_tower *node_tower = global->tower_list;
    float seconds = 0;
    sfTime time;

    time = sfClock_getElapsedTime(global->time_passed->clock);
    seconds = time.microseconds / 1000000;
    if (seconds > 180) {
        global->variable->win = 1;
        sfClock_restart(global->time_passed->clock);
    }
    while (node_tower != NULL) {
        if (node_tower->variable.position == 67 && \
        node_tower->variable.dead == 1)
            global->variable->win = -1;
        node_tower = node_tower->next;
    }
    check_who_wins(global, window);
}

void check_who_wins(st_global *global, sfRenderWindow *window)
{
    if (global->variable->win == -1)
        win(global, window);
    else if (global->variable->win == 1)
        lose(global, window);
}

void win(st_global *global, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        while (sfRenderWindow_pollEvent(window, &event)) {
            events_close(event, window);
            events_win_lose(event, window, global);
        }
        sfRenderWindow_drawSprite(window, global->win->sprite, NULL);
        sfRenderWindow_display(window);
    }
}

void lose(st_global *global, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        while (sfRenderWindow_pollEvent(window, &event)) {
            events_close(event, window);
            events_win_lose(event, window, global);
        }
        sfRenderWindow_drawSprite(window, global->lose->sprite, NULL);
        sfRenderWindow_display(window);
    }
}