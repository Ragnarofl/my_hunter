/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** simon-perraud
*/

#include <unistd.h>

int my_strcmp(char const *s1, char const *s2)
{
    int c1 = 0;
    int c2 = 0;

    if (!s1 || !s2)
        return (0);
    for (int i = 0; s1[i] != '\0'; i++)
        c1 += s1[i];
    for (int i = 0; s2[i] != '\0'; i++)
        c2 += s2[i];
    if (c1 == c2)
        return (0);
    else if (c1 < c2)
        return (-1);
    return (1);
}
