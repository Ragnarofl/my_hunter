/*
** EPITECH PROJECT, 2018
** my_strlowcase.c
** File description:
** simon-perraud
*/

char *my_strcapitalize(char *str)
{
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] >= 97 && str[i] <= 122 && (!((str[i - 1] >= 97 &&
            str[i - 1] <= 122) ||
            (str[i - 1] >= 65 && str[i - 1] <= 90))))
            str[i] -= 32;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return (str);
}
