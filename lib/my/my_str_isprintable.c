/*
** EPITECH PROJECT, 2018
** my_str_isprintable.c
** File description:
** simon-perraud
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0';) {
        if (str[i] >= 0 && str[i] <= 31)
            return (0);
        else
            i++;
    }
    return (1);
}
