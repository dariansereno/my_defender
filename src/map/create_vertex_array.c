/*
** EPITECH PROJECT, 2021
** bs_my_world
** File description:
** create_vertex
*/

#include "game.h"

sfVector2f project_iso_point(int x, int y, int z) // cos(0.7854) et sin (0.6109)
{
    sfVector2f two_d_point = {0, 0};
    two_d_point.x = cos(0.7854) * x - cos(0.7854) * y;
    two_d_point.y = cos(0.7854) * y + sin(0.5000) * x - z;

    return (two_d_point);
}

sfVector2f **create_2d_map(st_map *map)
{
    sfVector2f **converted = malloc(sizeof(sfVector2f*) * (map->map_height * 2));

    for (int i = 0; i < map->map_height * 2; i++) {
        converted[i] = malloc(sizeof(sfVector2f) * (map->map_width * 2));
        for (int j = 0; j < map->map_width * 2; j++)
            converted[i][j] = project_iso_point(i * map->resize, j * map->resize, map->map_int[i][j] * 5);
    }
    return (converted);
}

sfVertexArray *create_quad(sfVector2f *point1 , sfVector2f *point2, sfVector2f *point3, sfVector2f *point4) {
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfWhite, .texCoords = (sfVector2f){0, 0}};
    sfVertex vertex2 = {.position = *point2, .color = sfWhite, .texCoords = (sfVector2f){128, 0}};
    sfVertex vertex3 = {.position = *point3, .color = sfWhite, .texCoords = (sfVector2f){128, 128}};
    sfVertex vertex4 = {.position = *point4, .color = sfWhite, .texCoords = (sfVector2f){0, 128}};
    vertex1.position.x += 800;
    vertex1.position.y += 165;
    vertex2.position.x += 800;
    vertex2.position.y += 165;
    vertex3.position.x += 800;
    vertex3.position.y += 165;
    vertex4.position.x += 800;
    vertex4.position.y += 165;
    sfVertexArray_append(vertex_array , vertex1);
    sfVertexArray_append(vertex_array , vertex2);
    sfVertexArray_append(vertex_array , vertex3);
    sfVertexArray_append(vertex_array , vertex4);
    sfVertexArray_setPrimitiveType(vertex_array , sfQuads);
    return (vertex_array);
}

sfRenderStates *rendering(sfTexture *texture)
{
    sfRenderStates *render = malloc(sizeof(*render));
    render->texture = texture;
    render->blendMode = sfBlendAlpha;
    render->shader = NULL;
    render->transform = sfTransform_Identity;

    return (render);
}
