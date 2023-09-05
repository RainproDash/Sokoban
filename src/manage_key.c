/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-sokoban-vivien.boitard
** File description:
** manage_key
*/

#include "../include/header.h"

static void move_up(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->p_pos_i - 1][sokoban->p_pos_j] == 'X' &&
    (sokoban->map[sokoban->p_pos_i - 2][sokoban->p_pos_j] == 'X' ||
    sokoban->map[sokoban->p_pos_i - 2][sokoban->p_pos_j] == '#'))
        return;
    if (sokoban->map[sokoban->p_pos_i - 1][sokoban->p_pos_j] == 'X' &&
    (sokoban->map[sokoban->p_pos_i - 2][sokoban->p_pos_j] != '#' ||
    sokoban->map[sokoban->p_pos_i - 2][sokoban->p_pos_j] != 'X')) {
        sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j] = ' ';
        sokoban->map[sokoban->p_pos_i - 1][sokoban->p_pos_j] = 'P';
        sokoban->map[sokoban->p_pos_i - 2][sokoban->p_pos_j] = 'X';
        sokoban->p_pos_i--;
        return;
    }
    if (sokoban->map[sokoban->p_pos_i - 1][sokoban->p_pos_j] == ' ' ||
    sokoban->map[sokoban->p_pos_i - 1][sokoban->p_pos_j] == 'O') {
        sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j] = ' ';
        sokoban->map[sokoban->p_pos_i - 1][sokoban->p_pos_j] = 'P';
        sokoban->p_pos_i--;
        return;
    }
}

static void move_down(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->p_pos_i + 1][sokoban->p_pos_j] == 'X' &&
    (sokoban->map[sokoban->p_pos_i + 2][sokoban->p_pos_j] == 'X' ||
    sokoban->map[sokoban->p_pos_i + 2][sokoban->p_pos_j] == '#'))
        return;
    if (sokoban->map[sokoban->p_pos_i + 1][sokoban->p_pos_j] == 'X' &&
    (sokoban->map[sokoban->p_pos_i + 2][sokoban->p_pos_j] != '#' ||
    sokoban->map[sokoban->p_pos_i + 2][sokoban->p_pos_j] != 'X')) {
        sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j] = ' ';
        sokoban->map[sokoban->p_pos_i + 1][sokoban->p_pos_j] = 'P';
        sokoban->map[sokoban->p_pos_i + 2][sokoban->p_pos_j] = 'X';
        sokoban->p_pos_i++;
        return;
    }
    if (sokoban->map[sokoban->p_pos_i + 1][sokoban->p_pos_j] == ' ' ||
    sokoban->map[sokoban->p_pos_i + 1][sokoban->p_pos_j] == 'O') {
        sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j] = ' ';
        sokoban->map[sokoban->p_pos_i + 1][sokoban->p_pos_j] = 'P';
        sokoban->p_pos_i++;
        return;
    }
}

static void move_left(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j - 1] == 'X' &&
    (sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j - 2] == 'X' ||
    sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j - 2] == '#'))
        return;
    if (sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j - 1] == 'X' &&
    (sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j - 2] != '#' ||
    sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j - 2] != 'X')) {
        sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j] = ' ';
        sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j - 1] = 'P';
        sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j - 2] = 'X';
        sokoban->p_pos_j--;
        return;
    }
    if (sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j - 1] == ' ' ||
    sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j - 1] == 'O') {
        sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j] = ' ';
        sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j - 1] = 'P';
        sokoban->p_pos_j--;
        return;
    }
}

static void move_right(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j + 1] == 'X' &&
    (sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j + 2] == 'X' ||
    sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j + 2] == '#'))
        return;
    if (sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j + 1] == 'X' &&
    (sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j + 2] != '#' ||
    sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j + 2] != 'X')) {
        sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j] = ' ';
        sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j + 1] = 'P';
        sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j + 2] = 'X';
        sokoban->p_pos_j++;
        return;
    }
    if (sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j + 1] == ' ' ||
    sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j + 1] == 'O') {
        sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j] = ' ';
        sokoban->map[sokoban->p_pos_i][sokoban->p_pos_j + 1] = 'P';
        sokoban->p_pos_j++;
        return;
    }
}

void manage_key(sokoban_t *sokoban)
{
    switch (sokoban->ch) {
        case KEY_UP: move_up(sokoban); break;
        case KEY_DOWN: move_down(sokoban); break;
        case KEY_LEFT: move_left(sokoban); break;
        case KEY_RIGHT: move_right(sokoban); break;
    }
}
