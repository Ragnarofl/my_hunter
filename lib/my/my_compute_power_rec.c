/*
** EPITECH PROJECT, 2018
** my_compute_power_rec.c
** File description:
** simon-perraud
*/

#include <limits.h>

int my_compute_power_rec(int nb, int p)
{
    int res = nb;

    if (p == 0)
        return (1);
    else if (p < 0)
        return (0);
    if (res * res > INT_MAX)
        return (0);
    res *= my_compute_power_rec(res, p - 1);
    return (res);
}
