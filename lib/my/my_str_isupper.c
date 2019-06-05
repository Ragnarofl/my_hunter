/*
** EPITECH PROJECT, 2018
** my_str_isupper.c
** File description:
** simon-perraud
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0';) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            i++;
        else
            return (0);
    }
    return (1);
}
