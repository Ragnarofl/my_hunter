/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** simon-perraud
*/

#include <unistd.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!dest || !src)
        return (NULL);
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
