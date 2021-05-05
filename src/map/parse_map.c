/*
** EPITECH PROJECT, 2021
** bs_my_world
** File description:
** parse_map
*/

#include "game.h"

int find_index(tile_prop *prop, char c, st_map *map)
{
    for (int i = 0; i < map->prop_size; i++) {
        if (c == prop[i].c){
            return (i);
        }
    }
}

int **convert_map_to_valid_map(st_map *map)
{
    int k = 0;
    int l = 0;
    int **map_vertex = malloc(sizeof(int *) * (map->map_height * 2));

    for (int i = 0; i < map->map_height * 2; i++)
        map_vertex[i] = map_vertex[i] = malloc(sizeof(int) * \
        (map->map_width * 2));
    for (int i = 0; i < map->map_height; i++, k += 2, l = 0)
        for (int j = 0; j < map->map_width; j++, l += 2) {
            map_vertex[k][l] = map->props\
            [find_index(map->props, map->map[i][j], map)].height;
            map_vertex[k + 1][l] = map->props\
            [find_index(map->props, map->map[i][j], map)].height;
            map_vertex[k][l + 1] = map->props\
            [find_index(map->props, map->map[i][j], map)].height;
            map_vertex[k + 1][l + 1] = map->props\
            [find_index(map->props, map->map[i][j], map)].height;
        }
    return (map_vertex);
}