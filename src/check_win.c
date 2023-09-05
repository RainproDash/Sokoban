/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-sokoban-vivien.boitard
** File description:
** check_win
*/

#include "../include/header.h"

static int is_target(sokoban_t *sokoban, int i)
{
    for (int j = 0; sokoban->map[i][j] != '\0'; j++)
        if (sokoban->map[i][j] == 'O')
            return 1;
    return 0;
}

void check_win(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->map[i] != NULL; i++) {
        if (is_target(sokoban, i) == 1)
            return;
    }
    if (sokoban->map_copy[sokoban->p_pos_i][sokoban->p_pos_j] != 'O') {
        endwin();
        destroy_map(sokoban);
        exit(0);
    }
}
