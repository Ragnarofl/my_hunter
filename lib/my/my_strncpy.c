/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** simon-perraud
*/

#include <unistd.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (!dest || !src)
        return (NULL);
    for (; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';
    dest[i] = '\0';
    return (dest);
}
