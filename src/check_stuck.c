/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-sokoban-vivien.boitard
** File description:
** check_stuck
*/

#include "../include/header.h"
#include <ncurses.h>

void check_stuck(sokoban_t *sokoban)
{
    int x = 0;

    for (int i = 0; sokoban->map[i] != NULL; i++) {
        for (int j = 0; sokoban->map[i][j] != '\0'; j++) {
            (sokoban->map[i][j] == 'X') ? ((sokoban->map[i + 1][j] == '#' &&
            sokoban->map[i][j + 1] == '#') || (sokoban->map[i + 1][j] == '#' &&
            sokoban->map[i][j - 1] == '#') || (sokoban->map[i - 1][j] == '#' &&
            sokoban->map[i][j + 1] == '#') || (sokoban->map[i - 1][j] == '#' &&
            sokoban->map[i][j - 1] == '#') ? (x++) : (0)) : (0);
        }
    }
    if (x == sokoban->nb_x) {
        endwin();
        destroy_map(sokoban);
        exit(1);
    }
}
