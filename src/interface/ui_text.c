/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** ui_text
*/

#include "game.h"

const char *nb_in_text(int number)
{
    char *str = malloc(sizeof(char) * 10);
    int increment = 0;

    for (; number > 0; increment++) {
        str[increment] = (number % 10) + 48;
        number /= 10;
    }
    str[increment] = '\0';
    my_revstr(str);
    return (str);
    free(str);
}

int offset_text(st_global *global)
{
    int offset = 0;
    int money = global->ui->money;

    for (; money > 10; offset++)
        money /= 10;
    return (offset);
}

int level_bank(st_global *global)
{
    list_tower *node = global->tower_list;
    int level = 0;

    while (node != NULL) {
        if (node->variable.position == 67)
            return (node->variable.level);
        node = node->next;
    }
    return (level);
}

void update_text(st_global *global)
{
    float seconds = 0;
    sfTime time;
    int level = level_bank(global);

    time = sfClock_getElapsedTime(global->ui->money_clock->clock);
    seconds = time.microseconds / 1000;
    global->variable->money_time = 70 - ((level - 1) * 30);
    if (seconds > global->variable->money_time) {
        global->ui->money += 1;
        if (global->ui->money > 1000)
            global->ui->money = 1000;
        sfClock_restart(global->ui->money_clock->clock);
    }
}

void ui_text_bars(st_global *global, sfRenderWindow *window)
{
    int offset = 0;

    update_text(global);
    sfText_setString(global->ui->money_text, nb_in_text(global->ui->money));
    sfText_setString(global->ui->heal_text, nb_in_text(global->ui->heal));
    sfText_setPosition(global->ui->money_text, \
    (sfVector2f){1720, 46});
    sfText_setPosition(global->ui->heal_text, (sfVector2f){1720, 125});
    sfText_setFont(global->ui->money_text, global->ui->font);
    sfText_setFont(global->ui->heal_text, global->ui->font);
    sfText_setCharacterSize(global->ui->money_text, 26);
    sfText_setCharacterSize(global->ui->heal_text, 26);
    sfText_setColor(global->ui->money_text, sfWhite);
    sfText_setColor(global->ui->heal_text, sfWhite);
    sfText_setOutlineColor(global->ui->money_text, sfBlack);
    sfText_setOutlineColor(global->ui->heal_text, sfBlack);
    sfText_setOutlineThickness(global->ui->money_text, 3);
    sfText_setOutlineThickness(global->ui->heal_text, 3);
    sfRenderWindow_drawText(window, global->ui->money_text, NULL);
    sfRenderWindow_drawText(window, global->ui->heal_text, NULL);
}