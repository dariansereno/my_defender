/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** path
*/

#include "game.h"

list_n generate_neighbor(path_node *current, st_global *global, path_node ***map_nodes)
{
    list_n list = NULL;

    if (current->pos.y > 0)
        list = push_back_list_n(list, map_nodes[current->pos.y - 1][\
        current->pos.x] , current);
    // if (current->pos.y > 0 && current->pos.x > 0)
    //     list = push_back_list_n(list, map_nodes[current->pos.y - 1]\
    //     [current->pos.x - 1], current);
    if (current->pos.y < global->map->map_height - 1)
        list = push_back_list_n(list, map_nodes[current->pos.y + 1]\
        [current->pos.x], current);
    // if (current->pos.y < global->map->map_height - 1 && \
    // current->pos.x < global->map->map_width - 1)
    //     list = push_back_list_n(list, map_nodes[current->pos.y + 1]\
    //     [current->pos.x + 1], current);
    if (current->pos.x > 0)
        list = push_back_list_n(list, map_nodes[current->pos.y]\
        [current->pos.x - 1], current);
    // if (current->pos.x > 0 && current->pos.y < global->map->map_height - 1)
    //     list = push_back_list_n(list, map_nodes[current->pos.y + 1]\
    //     [current->pos.x - 1], current);
    if (current->pos.x < global->map->map_width - 1)
        list = push_back_list_n(list, map_nodes[current->pos.y]\
        [current->pos.x + 1], current);
    // if (current->pos.x < global->map->map_width - 1 && current->pos.y > 0)
    //     list = push_back_list_n(list, map_nodes[current->pos.y - 1]\
    //     [current->pos.x + 1], current);
    return (list);
}

path_node ***create_all_neighbor(st_global *global, path_node ***map_nodes)
{
    for (int y = 0; y < global->map->map_height; y++) {
        for (int x = 0; x < global->map->map_width; x++) {
            map_nodes[y][x]->neighbours = NULL;
            map_nodes[y][x]->neighbours = generate_neighbor(map_nodes[y][x], \
            global, map_nodes);
        }
    }
    return (map_nodes);
}

int heuristic_by_pos(sfVector2i start, sfVector2i stop)
{
    int x_dst = abs(start.x - stop.x);
    int y_dst = abs(start.y - stop.y);

    if (x_dst > y_dst)
        return (14 * y_dst + 10 * (x_dst - y_dst));
    return (14 * x_dst + 10 * (y_dst - x_dst));
}

path_node ***convert_map_to_node(st_global *global, sfVector2i start)
{
    path_node ***tab_node = malloc(sizeof(path_node **) * \
    global->map->map_height);
    for (int i = 0; i < global->map->map_height; i++) {
        tab_node[i] = malloc(sizeof(path_node *) * global->map->map_width);
        for (int j = 0; j < global->map->map_width; j++) {
            tab_node[i][j] = malloc(sizeof(path_node));
            tab_node[i][j]->pos.x = j;
            tab_node[i][j]->pos.y = i;
            tab_node[i][j]->h_cost = 10000;
            tab_node[i][j]->g_cost = \
            heuristic_by_pos((sfVector2i){j, i}, start);
            tab_node[i][j]->f_cost = 10000;
            tab_node[i][j]->bVisited = sfFalse;
            tab_node[i][j]->bObstacle = sfFalse;
            tab_node[i][j]->start = start;
            if (global->map->props[find_index(global->map->props, \
            global->map->map[i][j], global->map)].filled == 1)
                tab_node[i][j]->bObstacle = sfTrue;
            tab_node[i][j]->parent = NULL;
        }
    }
    tab_node = create_all_neighbor(global, tab_node);
    return (tab_node);
}

path_node return_pos_value(st_global *global, sfVector2i pos, \
path_node **tab)
{
    for (int i = 0; i < global->map->map_height; i++) {
        for (int j = 0; j < global->map->map_width; j++) {
            if (pos.x == tab[i][j].pos.x && pos.y == tab[i][j].pos.y)
                return (tab[i][j]);
        }
    }
    return (tab[0][0]);
}

list_astar compute_path(a_star *astar, st_global *global)
{
    list_astar path = NULL;

    while (astar->current != NULL) {
        global->map->map[astar->current->pos.y][astar->current->pos.x] = 'X';
        path = push_front_list_astar(path, astar->current, \
        astar->current->parent);
        astar->current = astar->current->parent;
    }
    free(astar->current);
    free(astar->start);
    free(astar->target);
    free(astar);
    astar = NULL;
    return (path);
}

int heuristic(path_node *current, path_node *target)
{
    sfVector2i start = current->pos;
    sfVector2i stop = target->pos;
    int x_dst = abs(start.x - stop.x);
    int y_dst = abs(start.y - stop.y);

    if (x_dst > y_dst)
        return (14 * y_dst + 10 * (x_dst - y_dst));
    return (14 * x_dst + 10 * (y_dst - x_dst));
}

path_node *generate_target_near(path_node ***map_nodes, path_node *target, st_global *global)
{
    list_n list = NULL;
    int i = 0;
    int index = 0;

    if (target->pos.y > 0)
        if (map_nodes[target->pos.y - 1][target->pos.x]->bObstacle == sfFalse)
            list = push_back_list_n(list, map_nodes[target->pos.y - 1][target->pos.x] , target);
    if (target->pos.y > 0 && target->pos.x > 0)
        if (map_nodes[target->pos.y - 1][target->pos.x - 1]->bObstacle == sfFalse)
            list = push_back_list_n(list, map_nodes[target->pos.y - 1][target->pos.x - 1], target);
    if (target->pos.y < global->map->map_height - 1)
        if (map_nodes[target->pos.y + 1][target->pos.x]->bObstacle == sfFalse)
            list = push_back_list_n(list, map_nodes[target->pos.y + 1][target->pos.x], target);
    if (target->pos.y < global->map->map_height - 1 && target->pos.x < global->map->map_width - 1)
        if (map_nodes[target->pos.y + 1][target->pos.x + 1]->bObstacle == sfFalse)
            list = push_back_list_n(list, map_nodes[target->pos.y + 1][target->pos.x + 1], target);
    if (target->pos.x > 0)
        if (map_nodes[target->pos.y][target->pos.x - 1]->bObstacle == sfFalse)
            list = push_back_list_n(list, map_nodes[target->pos.y][target->pos.x - 1], target);
    if (target->pos.x > 0 && target->pos.y < global->map->map_height - 1)
        if (map_nodes[target->pos.y + 1][target->pos.x - 1]->bObstacle == sfFalse)
            list = push_back_list_n(list, map_nodes[target->pos.y + 1][target->pos.x - 1], target);
    if (target->pos.x < global->map->map_width - 1)
        if (map_nodes[target->pos.y][target->pos.x + 1]->bObstacle == sfFalse)
            list = push_back_list_n(list, map_nodes[target->pos.y][target->pos.x + 1], target);
    if (target->pos.x < global->map->map_width - 1 && target->pos.y > 0)
        if (map_nodes[target->pos.y - 1][target->pos.x + 1]->bObstacle == sfFalse)
            list = push_back_list_n(list, map_nodes[target->pos.y - 1][target->pos.x + 1], target);

    if (size_list_n(list) == 0)
        return (NULL);
    return(list->node);
}

a_star *initialise_struct_astar(st_global *global, sfVector2i pos_start, sfVector2i target, sfVector2i *last)
{
    path_node *node = malloc(sizeof(*node));
    a_star *astar = malloc(sizeof(*astar));
    sfVector2i pos;

    astar->current = malloc(sizeof(*astar->current ));
    astar->current->parent = malloc(sizeof(*astar->current->parent));
    astar->closed = NULL;
    astar->open = NULL;
    astar->map_nodes = convert_map_to_node(global, pos_start);
    astar->start = malloc(sizeof(*astar->start));
    astar->start = astar->map_nodes[pos_start.y][pos_start.x];
    astar->target = malloc(sizeof(*astar->target));
    astar->target = astar->map_nodes[target.y][target.x];
    *last = astar->target->pos;
    // node = generate_target_near(astar->map_nodes, astar->target, global);
    // astar->target = node;
    astar->start->pos = pos_start;
    return (astar);
}

void actualise_current(list_astar list, path_node **current, \
a_star *a)
{
    list_astar li = malloc(sizeof(li));
    li = list;

    while (li != NULL) {
        if (li->node->f_cost < (*current)->f_cost || \
        li->node->f_cost == (*current)->f_cost) {
            if (li->node->h_cost + heuristic((*current), li->node) < (*current)->h_cost)
                *current = li->node;
        }
        li = li->next;
    }
}

list_astar path_finding(st_global *global, sfVector2i pos_start, sfVector2i target, sfVector2i *last)
{
    a_star *astar = initialise_struct_astar(global, pos_start, target, last);
    int new_move = 0;
    path_node *node = malloc(sizeof(path_node *));
    list_n li_temp = malloc(sizeof(li_temp));
    int i = 0;

    astar->open = push_back_list_astar(astar->open, astar->start, NULL);
    while (size_list_astar(astar->open) > 0) {
        astar->current = first_astar(astar->open);
        actualise_current(astar->open, &astar->current, astar);
        pop_pos_astar(&astar->open, astar->current->pos);
        astar->closed = push_back_list_astar(astar->closed, \
        astar->current, NULL);
        if (astar->current->pos.x == astar->target->pos.x && \
        astar->current->pos.y == astar->target->pos.y)
            break ;
        li_temp = NULL;
        li_temp = astar->current->neighbours;
        while (li_temp != NULL) {
            if (li_temp->node->bObstacle == sfFalse && \
            is_in_list_astar(astar->closed, astar->map_nodes\
            [li_temp->node->pos.y][li_temp->node->pos.x]->pos) == 0) {
                new_move = astar->map_nodes[astar->current->pos.y]\
                [astar->current->pos.x]->g_cost + heuristic(astar->map_nodes\
                [astar->current->pos.y][astar->current->pos.x], \
                astar->map_nodes[li_temp->node->pos.y][li_temp->node->pos.x]);
                if (new_move <= astar->map_nodes[li_temp->node->pos.y]\
                [li_temp->node->pos.x]->g_cost || \
                is_in_list_astar(astar->open, astar->map_nodes\
                [li_temp->node->pos.y][li_temp->node->pos.x]->pos) == 0) {
                    astar->map_nodes[li_temp->node->pos.y]\
                    [li_temp->node->pos.x]->g_cost = new_move;
                    astar->map_nodes[li_temp->node->pos.y]\
                    [li_temp->node->pos.x]->h_cost = \
                    heuristic(astar->map_nodes[li_temp->node->pos.y]\
                    [li_temp->node->pos.x], astar->target);
                    astar->map_nodes[li_temp->node->pos.y]\
                    [li_temp->node->pos.x]->f_cost = new_move + \
                    astar->map_nodes[li_temp->node->pos.y]\
                    [li_temp->node->pos.x]->h_cost;
                    astar->map_nodes[li_temp->node->pos.y]\
                    [li_temp->node->pos.x]->parent = \
                    astar->map_nodes[astar->current->pos.y]\
                    [astar->current->pos.x];
                    if (is_in_list_astar(astar->open, \
                    astar->map_nodes[li_temp->node->pos.y]\
                    [li_temp->node->pos.x]->pos) == 0)
                        astar->open = \
                        push_back_list_astar(astar->open, astar->map_nodes\
                        [li_temp->node->pos.y][li_temp->node->pos.x], \
                        astar->map_nodes[astar->current->pos.y]\
                        [astar->current->pos.x]);
                }
            }
            li_temp = li_temp->next;
        }
    }
    pop_all_list_astar(astar->open);
    pop_all_list_astar(astar->closed);
    return(compute_path(astar,global));
}