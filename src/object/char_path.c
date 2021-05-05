/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** char_path
*/

#include "game.h"

void face_char_target(list_char *li_char)
{
    list_char li = malloc(sizeof(li));
    li = *li_char;

    while (li != NULL) {
        li->variable.pos = sfSprite_getPosition(li->object->sprite);

        if ((int)li->variable.pos.x == (int)li->variable.next_target.x && (int)li->variable.pos.y > (int)li->variable.next_target.y)
            li->variable.facing = 0;
        else if ((int)li->variable.pos.x == (int)li->variable.next_target.x && (int)li->variable.pos.y < (int)li->variable.next_target.y)
            li->variable.facing = 4;
        else if ((int)li->variable.pos.x > (int)li->variable.next_target.x && (int)li->variable.pos.y == (int)li->variable.next_target.y)
            li->variable.facing = 6;
        else if ((int)li->variable.pos.x < (int)li->variable.next_target.x && (int)li->variable.pos.y == (int)li->variable.next_target.y)
            li->variable.facing = 2;
        else if ((int)li->variable.pos.x == (int)li->variable.next_target.x && (int)li->variable.pos.y == (int)li->variable.next_target.y)
            li->variable.facing = -1;
        else if ((int)li->variable.pos.x > (int)li->variable.next_target.x && (int)li->variable.pos.y > (int)li->variable.next_target.y)
            li->variable.facing = 7;
        else if ((int)li->variable.pos.x < (int)li->variable.next_target.x && (int)li->variable.pos.y > (int)li->variable.next_target.y)
            li->variable.facing = 1;
        else if ((int)li->variable.pos.x > (int)li->variable.next_target.x && (int)li->variable.pos.y < (int)li->variable.next_target.y)
            li->variable.facing = 5;
        else if ((int)li->variable.pos.x < (int)li->variable.next_target.x && (int)li->variable.pos.y < (int)li->variable.next_target.y)
            li->variable.facing = 3;
        li = li->next;
    }
}

sfVector2i convert_pos_to_mappos(sfVector2f pos, st_global **global)
{
    list_char node_char = malloc(sizeof(node_char));
    node_char = (*global)->character_list;
    list_ground node_ground = malloc(sizeof(node_ground));
    node_ground = (*global)->map->li_ground;
    st_vertex *vertex = malloc(sizeof(*vertex));

    generation_vertex(vertex);
    while (node_char != NULL) {
            while (node_ground != NULL) {
                vertex->a = sfVertexArray_getVertex(node_ground->array, 0)->position;
                vertex->b = sfVertexArray_getVertex(node_ground->array, 1)->position;
                vertex->c = sfVertexArray_getVertex(node_ground->array, 2)->position;
                vertex->d = sfVertexArray_getVertex(node_ground->array, 3)->position;
                if (is_intersection_character(vertex, (sfVector2f){pos.x, pos.y}))
                    return (node_ground->pos);
                node_ground = node_ground->next;
            }
            node_char = node_char->next;
        }
}

sfVector2i generate_random_target(st_global *global)
{
    list_3D li = malloc(sizeof(li));
    li = global->map->li_3D;
    int size = size_list_3D(li);
    int index = 0;
    int i = 0;

    if (size == 0)
        return ((sfVector2i){0, 0});
    index = random_between(1, size);
    while (li != NULL) {
        if (i == index - 1)
            return (li->pos);
        i++;
        li = li->next;
    }
    return ((sfVector2i){0, 0});
}

void go_first_node_char(list_char *list, st_global *global)
{
    list_char li = malloc(sizeof(li));
    li = *list;

    while (li != NULL) {
        li->variable.next_target = global->map->map_center[0][3];
        li->variable.out_of_grid = true;
        li = li->next;
    }
}

void can_start_path(list_char *list, st_global *global)
{
    list_char li = malloc(sizeof(li));
    li = *list;

    while (li != NULL) {
        if ((int)li->variable.pos.x == (int)li->variable.next_target.x &&
        (int)li->variable.pos.y == (int)li->variable.next_target.y &&
        (int)li->variable.out_of_grid == true) {
            li->variable.out_of_grid = false;
            li->variable.path_finded = true;
        }
        li = li->next;
    }
}

void actualise_next_target(st_global **global)
{
    list_char li = malloc(sizeof(li));
    li = (*global)->character_list;

    while (li != NULL) {
        if (li->variable.out_of_grid == false) {
            if (((int)li->variable.pos.x ==
            (int)(*global)->map->map_center[li->variable.g_target.y]
            [li->variable.g_target.x].x &&
            (int)li->variable.pos.y == (int)(*global)->map->map_center[li->variable.g_target.y]
            [li->variable.g_target.x].y && li->variable.termined == false)
            || size_list_astar(li->variable.path) ==1 ) {
                li->variable.path_finded = true;
                li->variable.termined = true;
            }
            if ((int)li->variable.pos.x == (int)li->variable.next_target.x &&
            (int)li->variable.pos.y == (int)li->variable.next_target.y &&
            size_list_astar(li->variable.path) > 1 && li->variable.termined == false) {
                li->variable.path = pop_front_astar(li->variable.path);
                li->variable.next_target = (*global)->map->map_center[li->variable.path->node->pos.y][li->variable.path->node->pos.x];
            }
        }
        li = li->next;
    }
}

void generate_path(st_global **global)
{
    sfVector2f playerpos = {0, 0};
    sfVector2i pos_result = {0, 0};
    list_char li = malloc(sizeof(li));
    li = (*global)->character_list;
    sfVector2i random;
    sfVector2i last_pos;
    sfVector2i arnak;

    while (li != NULL) {
        random = generate_random_target(*global);
        playerpos = sfSprite_getPosition(li->object->sprite);
        playerpos.y += 82.5;
        playerpos.x += 24;
        pos_result = convert_pos_to_mappos(playerpos, global);
        if (li->variable.path_finded == true && (pos_result.x >= 0 && pos_result.x <= (*global)->map->map_width)
        &&  (pos_result.y >= 0 && pos_result.y <= (*global)->map->map_height) && li->variable.termined == false){
            li->variable.path = path_finding(*global, pos_result, random, &last_pos);
            li->variable.path = pop_front_astar(li->variable.path);
            li->variable.g_target = last_pos;
            li->variable.next_target = (*global)->map->map_center[li->variable.path->node->pos.y][li->variable.path->node->pos.x];
            li->variable.path_finded = false;    
        }
        else if (li->variable.out_of_grid == false && li->variable.path_finded
        == false && (pos_result.x >= 0 && pos_result.x <=(*global)->map->map_width) &&
        (pos_result.y >= 0 && pos_result.y <= (*global)->map->map_height) && li->variable.termined == false){
            li->variable.path = path_finding(*global, pos_result, li->variable.g_target, &arnak);
        }
        li = li->next;
    }
}