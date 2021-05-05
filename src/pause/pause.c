/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** pause
*/

#include "game.h"

void pauseloop(st_global *global, sfRenderWindow *window)
{
    sfEvent event;
    global->map->map_int = convert_map_to_valid_map(global->map);
    global->map->map_vector = create_2d_map(global->map);
    generate_bank(global);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        global->map = draw_2d_map(window, global->map);
        while (sfRenderWindow_pollEvent(window, &event)) {
            events_close(event, window);
            event_in_pause(event, window, global);
        }
        display_map(global, window, event);
        sfRenderWindow_drawSprite(window, global->pause->sprite, NULL);
        change_texture_death(global);
        sfRenderWindow_display(window);
    }
}