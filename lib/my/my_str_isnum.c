/*
** EPITECH PROJECT, 2018
** my_str_isnum.c
** File description:
** simon-perraud
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str[0] == '-')
        i++;
    for (; str[i] != '\0';) {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}
