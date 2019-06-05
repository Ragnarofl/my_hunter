/*
** EPITECH PROJECT, 2018
** my_find_prime_sup.c
** File description:
** simon-perraud
*/

#include <limits.h>

int my_is_prime(int);

int my_find_prime_sup(int nb)
{
    while (1) {
        if (my_is_prime(nb) == 1 && nb <= INT_MAX)
            return (nb);
        nb++;
    }
}
