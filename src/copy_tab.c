/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-sokoban-vivien.boitard
** File description:
** copy_tab
*/

#include "../include/header.h"

char **copy_tab(char **tab)
{
    char **new_tab = NULL;
    int i = 0;

    for (; tab[i] != NULL; i++);
    new_tab = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; j < i; j++) {
        new_tab[j] = malloc(sizeof(char) * (my_strlen(tab[j]) + 1));
        new_tab[j] = my_strcpy(new_tab[j], tab[j]);
    }
    new_tab[i] = NULL;
    return (new_tab);
}
