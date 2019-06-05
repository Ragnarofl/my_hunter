/*
** EPITECH PROJECT, 2018
** my_str_islower.c
** File description:
** simon-perraud
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0';) {
        if (str[i] >= 'a' && str[i] <= 'z')
            i++;
        else
            return (0);
    }
    return (1);
}
