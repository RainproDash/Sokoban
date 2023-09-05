/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-vivien.boitard
** File description:
** header
*/

#ifndef HEADER_H_
    #define HEADER_H_

    #include "../src/lib/my/my.h"
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <ncurses.h>

typedef struct sokoban_s {
    char **map;
    char **map_copy;
    int ch;
    int nb_o;
    int nb_x;
    int nb_p;
    int p_pos_i;
    int p_pos_j;
} sokoban_t;

char **copy_tab(char **tab);
void manage_error(sokoban_t *sokoban);
void manage_game(sokoban_t *sokoban);
void check_stuck(sokoban_t *sokoban);
void check_win(sokoban_t *sokoban);
void manage_key(sokoban_t *sokoban);
void destroy_map(sokoban_t *sokoban);

#endif /* !HEADER_H_ */
