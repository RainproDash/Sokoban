/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-sokoban-vivien.boitard
** File description:
** manage_error
*/

#include "../include/header.h"

void manage_error(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->map[i] != NULL; i++) {
        for (int j = 0; sokoban->map[i][j] != '\0'; j++) {
            (sokoban->map[i][j] == 'O') ? (sokoban->nb_o++) : (0);
            (sokoban->map[i][j] == 'X') ? (sokoban->nb_x++) : (0);
            (sokoban->map[i][j] == 'P') ? (sokoban->nb_p++) : (0);
            (sokoban->map[i][j] != '#' && sokoban->map[i][j] != 'O' &&
            sokoban->map[i][j] != 'X' && sokoban->map[i][j] != 'P' &&
            sokoban->map[i][j] != '\n' && sokoban->map[i][j] != ' ') ?
            (destroy_map(sokoban), exit(84)) : (0);
        }
    }
    (sokoban->nb_o != sokoban->nb_x || sokoban->nb_p != 1) ?
    (destroy_map(sokoban), exit(84)) : (0);
}
