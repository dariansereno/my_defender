/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** map
*/

#include "game.h"

void tileset_size_parsing(char **b_map, st_map *map, int i)
{
    int j = 0;
    char buff1[32];
    char buff2[32];
    int n = 0;

    while (b_map[i][j] != ' ') {
        if (b_map[i][j] >= '0' && b_map[i][j] <= '9')
            buff1[n++] = b_map[i][j];
        j++;
    }
    map->nb_tile_x = my_getnbr(buff1);
    n = 0;
    while (b_map[i][j] != '\0'){
        if (b_map[i][j] >= '0' && b_map[i][j] <= '9')
            buff2[n++] = b_map[i][j];
        j++;
    }
    map->nb_tile_y = my_getnbr(buff2);
}

void tileset_tile_size_parsing(char **b_map, st_map *map, int i)
{
    int j = 0;
    char buff1[32];
    char buff2[32];
    int n = 0;

    while (b_map[i][j] != ' ') {
        if (b_map[i][j] >= '0' && b_map[i][j] <= '9')
            buff1[n++] = b_map[i][j];
        j++;
    }
    map->width_tile = my_getnbr(buff1);
    n = 0;
    while (b_map[i][j] != '\0'){
        if (b_map[i][j] >= '0' && b_map[i][j] <= '9')
            buff2[n++] = b_map[i][j];
        j++;
    }
    map->height_tile = my_getnbr(buff2);
}

st_map *parse_height(char *str, int numtiles, st_map *map, int i)
{
    char *buff = malloc(sizeof(char) * 12);
    int j = 0;

    for (i; str[i] >= '0' && str[i] <= '9'; i++) {
        buff[j] = str[i];
        j++;
    }
    buff[j] = '\0';
    map->props[numtiles].height = my_getnbr(buff);
    free(buff);
    return (map);
}

st_map *parse_fill_and_height(char *str, int numtiles, st_map *map)
{
    char *buff = malloc(sizeof(char) * 12);
    int j = 0;

    for (int i = 2; str[i] != '='; i++) {
        buff[j] = str[i];
        j++;
    }
    buff[j] = '\0';
    if (my_strcmp(buff, "fill") == 0)
        map->props[numtiles].filled = 1;
    else
        map->props[numtiles].filled = 0;

    map = parse_height(str, numtiles, map, j + 3);
    free(buff);
    return (map);
}

void tileset_parsing(char **b_map, st_map *map, int i)
{
    int j = 0;
    int numtiles = 0;
    int n = 0;
    int r = 0;
    int f = 0;
    int m = 0;
    int g = 0;
    sfIntRect rect;

    map->link = b_map[i++];
    tileset_size_parsing(b_map, map, i++);
    tileset_tile_size_parsing(b_map, map, i++);
    map->props = malloc(sizeof(*map->props) * \
    (map->nb_tile_x * map->nb_tile_y));
    for (int y = 0; y < map->nb_tile_y; y++) {
        for (int x = 0; x < map->nb_tile_x; x++) {
            if (g + m == map->nb_tile_x)
                break;
            map = parse_fill_and_height(b_map[i], numtiles, map);
            map->props[numtiles].c = b_map[i][0];
            if (map->props[numtiles].height > 0) {
                map->props[numtiles].textures = malloc(sizeof(*map->props[numtiles].textures) \
                * 3);
                for (int r = 0; r < 3; r++) {
                    rect = (sfIntRect){.height = map->height_tile, .width = map->width_tile,
                    .top = y * map->height_tile, .left = x * \
                    (map->width_tile) + (f * map->width_tile) + (r * \
                    map->width_tile)};
                    map->props[numtiles].textures[r] = \
                    sfTexture_createFromFile(map->link, &rect);
                    g++;
                }
                f += 2;
            }
            else {
                rect = (sfIntRect){.height = map->map_height, .width = map->map_width, 
                .top = y * map->height_tile, .left = x * \
                map->width_tile + ((f * 100) * map->width_tile)};
                map->props[numtiles].textures = malloc(sizeof(*map->props[numtiles].textures));
                map->props[numtiles].textures[0] = \
                sfTexture_createFromFile(map->link, &rect);
                m++;
            }
            numtiles++;
            i++;
        }
        r = 0;
        f = 0;
    }
    map->prop_size = numtiles;
}

void parse_file(char **b_map, st_map *map)
{
    int i = 0;

    while (my_strcmp(b_map[i], "#end") != 0) {
        if (my_strcmp(b_map[i], "#tileset") == 0) {
            tileset_parsing(b_map, map, i + 1);
        }
        if (my_strcmp(b_map[i], "#map") == 0)
            parse_map(b_map, map, i + 1);
        i++;
    }
}

st_map *read_file(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat st;
    int size = 0;
    char *buff;
    st_map *map = malloc(sizeof(*map));

    stat(path, &st);
    size = st.st_size;
    buff = malloc(sizeof(char) * size);
    read(fd, buff, size);
    parse_file(my_str_to_word_array(buff, "\n$"), map);
    close(fd);
    return (map);
}