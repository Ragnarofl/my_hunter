/*
** EPITECH PROJECT, 2018
** test_my_strcmp.c
** File description:
** simon-perraud
*/

#include <unistd.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int c1 = 0;
    int c2 = 0;

    for (int i = 0; s1[i] != '\0' && i < n; i++)
        c1 += s1[i];
    for (int i = 0; s2[i] != '\0' && i < n; i++)
        c2 += s2[i];
    if (c1 == c2)
        return (0);
    else if (c1 < c2)
        return (-1);
    return (1);
}
