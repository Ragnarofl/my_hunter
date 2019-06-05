/*
** EPITECH PROJECT, 2018
** my_str_isalpha.c
** File description:
** simon-perraud
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0';) {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 'a' && str[i] <= 'z'))
            i++;
        else
            return (0);
    }
    return (1);
}
