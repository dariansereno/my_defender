/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** my_strcapitalize.c
*/

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    i = 0;
    while (str[i] != '\0') {
        if (!((str[i - 1] >= 'a' && str[i - 1] <= 'z') ||
        (str[i - 1] >= 'A' && str[i - 1] <= 'Z') ||
        (str[i - 1] >= '0' && str[i - 1] <= '9')) &&
        (str[i] >= 'a' && str[i] <= 'z'))
            str[i] -= 32;
        i++;
    }
    return (str);
}
