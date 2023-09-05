/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday08-vivien.boitard
** File description:
** my_str_to_word_array
*/

#include "my.h"
#include <stdlib.h>

char **my_str_to_word_array(char *str, char c)
{
    int count = 1;
    int token_len = 1;
    int i = 0;
    char *ptr;
    char *tmp;
    char **tab;

    for (ptr = str; *ptr != '\0'; ptr++)
        (*ptr == c) ? count++ : 0;
    tab = malloc(sizeof(char *) * count);
    for (i = 0, ptr = str; *ptr != '\0'; ptr++, token_len++)
        if (*ptr == c) {
            tmp = malloc(sizeof(char) * token_len);
            my_strncpy(tmp, ptr - token_len + 1, token_len - 1);
            tmp[token_len - 1] = '\0';
            tab[i++] = tmp;
            token_len = 0;
        }
    return (tab);
}
