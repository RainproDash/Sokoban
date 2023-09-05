/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-sokoban-vivien.boitard
** File description:
** manage_game
*/

#include "../include/header.h"

static void display_map(sokoban_t *sokoban)
{
    clear();
    for (int i = 0; sokoban->map[i] != NULL; i++)
        printw("%s\n", sokoban->map[i]);
    refresh();
}

static void init_ncurses(void)
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    noecho();
}

static void get_pos_p(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->map[i] != NULL; i++)
        for (int j = 0; sokoban->map[i][j] != '\0'; j++)
            (sokoban->map[i][j] == 'P') ? (sokoban->p_pos_i = i,
            sokoban->p_pos_j = j) : (0);
}

static void put_hole(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->map_copy[i] != NULL; i++) {
        for (int j = 0; sokoban->map_copy[i][j] != '\0'; j++) {
            (sokoban->map_copy[i][j] == 'O' && sokoban->map[i][j] == ' ') ?
            (sokoban->map[i][j] = 'O') : (0);
        }
    }
}

void manage_game(sokoban_t *sokoban)
{
    char **tmp = copy_tab(sokoban->map);

    init_ncurses();
    get_pos_p(sokoban);
    display_map(sokoban);
    while (sokoban->ch != 'q') {
        check_stuck(sokoban);
        check_win(sokoban);
        sokoban->ch = getch();
        manage_key(sokoban);
        put_hole(sokoban);
        display_map(sokoban);
        if (sokoban->ch == ' ') {
            sokoban->map = tmp;
            endwin();
            manage_game(sokoban);
        }
    }
    endwin();
}
