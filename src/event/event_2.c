/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** events
*/

#include "game.h"

void event_character(sfEvent event, sfRenderWindow *window, st_global *global)
{
    global->timer->time = sfClock_getElapsedTime(clock);

    global->timer->seconds = global->timer->time.microseconds / 1000;
    if (global->timer->seconds > 1) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight){
            change_list_facing(1, global->character_list);
            return ;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft){
            change_list_facing(-1, global->character_list);
            return ;
        }
    sfClock_restart(global->timer->clock);
    }
}

void event_pause(sfEvent event, sfRenderWindow *window, st_global *global)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP) {
        ennemies_pause(global);
        pauseloop(global, window);
    }
}

void event_in_pause(sfEvent event, sfRenderWindow *window, st_global *global)
{
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == \
    sfMouseLeft && event.mouseButton.x >= 801 && event.mouseButton.y >= 372 \
    && event.mouseButton.x <= 1122 && event.mouseButton.y <= 454) {
        ennemies_not_pause(global);
        game_normal(global, window);
    }
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == \
    sfMouseLeft && event.mouseButton.x >= 801 && event.mouseButton.y >= 498 \
    && event.mouseButton.x <= 1122 && event.mouseButton.y <= 581) {
        ennemies_not_pause(global);
        menuloop(window, global);
    }
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == \
    sfMouseLeft && event.mouseButton.x >= 801 && event.mouseButton.y >= 625 \
    && event.mouseButton.x <= 1122 && event.mouseButton.y <= 708)
        sfRenderWindow_close(window);
}

void events_how_to_play(sfEvent event, st_global *global, \
sfRenderWindow *window)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
        menuloop(window, global);
}

void events_win_lose(sfEvent event, sfRenderWindow *window, st_global *global)
{
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button \
    == sfMouseLeft && event.mouseButton.x >= 801 && event.mouseButton.y >= 562\
    && event.mouseButton.x <= 1121 && event.mouseButton.y <= 647)
        menuloop(window, global);
}