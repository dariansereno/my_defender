/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** merge_sort
*/

#include "game.h"

void split_list(list_astar source, list_astar *front_ref, list_astar *back_ref)
{
    list_astar fast;
    list_astar slow;

    slow = source;
    fast = source->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front_ref = source;
    *back_ref = slow->next;
    slow->next = NULL;
}

list_astar sorted_merge(list_astar a, list_astar b)
{
    list_astar result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (a->node->g_cost <= b->node->g_cost) {
        result = a;
        result->next = sorted_merge(a->next, b);
    }
    else {
        result = b;
        result->next = sorted_merge(a, b->next);
    }
    return (result);
}

void merge_sort(list_astar *head_ref)
{
    list_astar head = *head_ref;
    list_astar a;
    list_astar b;
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    split_list(head, &a, &b);
    merge_sort(&a);
    merge_sort(&b);
    *head_ref = sorted_merge(a, b); 
}

