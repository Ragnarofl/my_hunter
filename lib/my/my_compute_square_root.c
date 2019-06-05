/*
** EPITECH PROJECT, 2018
** my_compute_square_root.c
** File description:
** simon-perraud
*/

#include <limits.h>

int my_compute_square_root(int nb)
{
    int res = 0;

    if (nb <= 0)
        return (0);
    for (int i = 1; res < nb && nb <= INT_MAX; i++) {
        if (i * i > INT_MAX)
            return (0);
        res = i * i;
        if (res == nb)
            return (i);
        else if (res > nb)
            return (0);
    }
    return (0);
}
