/*
** EPITECH PROJECT, 2018
** my_put_float.c
** File description:
** simon-perraud
*/

#include "../../include/my.h"

void my_put_float(float nb, int fd)
{
    long int x = nb*1000000;

    my_put_nbr(x / 1000000, fd);
    my_putchar('.');
    my_put_nbr(x % 1000000, fd);
}
