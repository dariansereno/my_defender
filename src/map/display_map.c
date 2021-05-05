/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** display_map
*/

#include "game.h"
#include <stdio.h>

int index_prop(char c, st_map *map)
{
    int i = 0;

    while (i < map->nb_tile_x * map->nb_tile_y) {
        if (c == map->props[i].c)
            return (i);
        i++;
    }
    return (-1);
}

void display_map(st_global *global, sfRenderWindow *window, sfEvent event)
{
    sfRenderWindow_drawSprite(window, global->map_background->sprite, NULL);
    print_list_ground(global->map->li_ground, window, global->map);
    print_list_3D(global->map->li_3D, window, global->map, global);
    all_bars(window, global, event);
    generation_character_random(global);
    ennemies_annimation(global);
    sfRenderWindow_drawSprite(window, global->trees->sprite, NULL);
    damage_handling(global);
    win_conditions(global, window);
    change_texture_death(global);
    face_char_target(&global->character_list);
    can_start_path(&global->character_list, global);
    generate_path(&global);
    actualise_next_target(&global);
}

void generation_character_random(st_global *global)
{
    if (size_list_char(global->character_list) == 0)
        global->character_list = generate_random_char_between(1, 10);
}