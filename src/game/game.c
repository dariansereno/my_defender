/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** game
*/

#include "game.h"

void game_normal(st_global *global, sfRenderWindow *window)
{
    sfEvent event;
    global->map->map_int = convert_map_to_valid_map(global->map);
    global->map->map_vector = create_2d_map(global->map);
    global->variable->menu = 0;
    sfVector2i lol = {0, 0};
    list_astar list = malloc(sizeof(list));
    generate_bank(global);

    global->map = draw_2d_map(window, global->map);
    go_first_node_char(&global->character_list, global);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        global->map = draw_2d_map(window, global->map);
        while (sfRenderWindow_pollEvent(window, &event)) {
            event_character(event, window, global);
            events_game_normal(event, window, global);
        }
        display_map(global, window, event);
        damage_handling(global);
        win_conditions(global, window);
        change_texture_death(global);
        face_char_target(&global->character_list);
        can_start_path(&global->character_list, global);
        generate_path(&global);
        actualise_next_target(&global);
        sfRenderWindow_display(window);
    }
}