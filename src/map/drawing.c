/*
** EPITECH PROJECT, 2021
** bs_my_world
** File description:
** drawing
*/

#include "game.h"

st_map *floor_tile(sfVector2i pos, sfRenderWindow *window, st_map *map)
{
    if ((pos.y + 1 < map->map_height * 2&& pos.x + 1 < map->map_width * 2) \
    && ((map->map_int[pos.y][pos.x] == 0) || (map->map_int[pos.y][pos.x] > 0 \
    && map->map_int[pos.y][pos.x + 1] == 0)
    || (map->map_int[pos.y][pos.x] > 0 && map->map_int[pos.y + 1][pos.x] \
    == 0))) {
        sfVector2f point1 = project_iso_point(pos.y * map->resize - map->y, \
        pos.x * map->resize - map->x, 0);
        sfVector2f point2 = project_iso_point(pos.y * map->resize - map->y, \
        (pos.x + 1) *
        map->resize - map->x, 0);
        sfVector2f point3 = project_iso_point((pos.y + 1) * map->resize - \
        map->y, (pos.x + 1) *
        map->resize - map->x, 0);
        sfVector2f point4 = project_iso_point((pos.y + 1) * map->resize - \
        map->y, pos.x *
        map->resize - map->x, 0);
        sfVertexArray *array = create_quad(&point1, &point2, &point3, &point4);
        map->map_center[pos.y / 2][pos.x / 2].y =
        ((sfVertexArray_getVertex(array, 0)->position.y -
        sfVertexArray_getVertex(array, 1)->position.y) / 2) +
        (sfVertexArray_getVertex(array, 0)->position.y);
        map->map_center[pos.y / 2][pos.x / 2].x =
        ((sfVertexArray_getVertex(array, 2)->position.x -
        sfVertexArray_getVertex(array, 3)->position.x) / 2) +
        (sfVertexArray_getVertex(array, 2)->position.x);
        map->li_ground = push_back_ground(map->li_ground, array,
        map->map[pos.y / 2][pos.x / 2], (sfVector2i){pos.x / 2, pos.y / 2});
    }
    return (map);
}

st_map *high_tile(sfVector2i pos, sfRenderWindow *window, st_map *map)
{
    sfVertexArray *v_array[4] = {sfVertexArray_create(), \
    sfVertexArray_create(), sfVertexArray_create(), sfVertexArray_create()};
    sfVector2f vector[3] = {{0, 0}, {0, 0}, {0, 0}};

    if (pos.x + 1 < map->map_width * 2 && pos.y + 1 < map->map_height * 2 \
    && map->map_int[pos.y][pos.x] > 0 && map->map_int[pos.y][pos.x + 1] > 0 \
    && map->map_int[pos.y + 1][pos.x] > 0 && \
    map->map_int[pos.y + 1][pos.x + 1] > 0 ) {
        sfVector2f point1 = project_iso_point(pos.y * map->resize - map->y, \
        pos.x * map->resize - map->x, 0);
        sfVector2f point2 = project_iso_point(pos.y * map->resize - map->y, \
        (pos.x + 1) * map->resize - map->x, 0);
        sfVector2f point3 = project_iso_point((pos.y + 1) * map->resize - \
        map->y, (pos.x + 1) * map->resize - map->x, 0);
        sfVector2f point4 = project_iso_point((pos.y + 1) * map->resize - \
        map->y, pos.x * map->resize - map->x, 0);
        sfVector2f point4high = project_iso_point(pos.y * map->resize - \
        map->y, pos.x * map->resize - map->x, map->props[find_index(\
        map->props, map->map[pos.y / 2][pos.x / 2], map)].height * 5);
        sfVector2f point3high = project_iso_point(pos.y * map->resize - \
        map->y, (pos.x + 1) * map->resize - map->x, map->props[find_index(\
        map->props, map->map[pos.y / 2][pos.x / 2], map)].height * 5);
        sfVector2f point1high = project_iso_point((pos.y + 1) * map->resize \
        - map->y, (pos.x + 1) * map->resize - map->x, map->props[find_index(\
        map->props, map->map[pos.y / 2][pos.x / 2], map)].height * 5);
        sfVector2f point2high = project_iso_point((pos.y + 1) * map->resize - \
        map->y, pos.x * map->resize - map->x, map->props[find_index(\
        map->props, map->map[pos.y / 2][pos.x / 2], map)].height * 5);
        v_array[0] = create_quad(&point4, &point3, &point1high, &point2high);
        v_array[1] = create_quad(&point2, &point3, &point1high, &point3high);;
        v_array[2] = create_quad(&point4high, &point3high, &point1high, \
        &point2high);
        v_array[3] = create_quad(&point1, &point2, &point3, &point4);
        vector[0] = sfVertexArray_getVertex(v_array[0], 0)->position;
        vector[1] = sfVertexArray_getVertex(v_array[1], 0)->position;
        vector[2] = sfVertexArray_getVertex(v_array[0], 1)->position;
        map->li_3D = push_back_3D(map->li_3D, v_array, (d3_handling){map->map[pos.y / 2]\
        [pos.x / 2], vector, (sfVector2i){pos.x / 2, pos.y / 2} });
    }
    return (map);
}

st_map *draw_2d_map(sfRenderWindow *window, st_map *map)
{
    map->li_3D = NULL;
    map->li_ground = NULL;
    map->map_center = malloc(sizeof(sfVector2f *) * map->map_height);
    int r = 0;
    map->x = 0;
    map->y = 0;

    for (int i = 0; i < map->map_height * 2; i += 2) {
        map->map_center[r] = malloc(sizeof(sfVector2f) * map->map_width);
        for (int j = 0; j < map->map_width * 2; j += 2) {
            map = high_tile((sfVector2i){j, i}, window, map);
            map = floor_tile((sfVector2i){j, i}, window, map);
            map->x += map->resize;
        }
        r++;
        map->x = 0;
        map->y += map->resize;
    }
    return (map);
}