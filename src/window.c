/*
** EPITECH PROJECT, 2018
** window
** File description:
** well, real programmers use ed
*/

#include <stdlib.h>
#include <math.h>
#include "world.h"
#include "my.h"

void ft_game(my_game_t *game)
{
    while (sfRenderWindow_isOpen(game->win->window)) {
        make_time(game);
        //if (game->obj && game->map->update == 1) {
        game->map->update = 0;
        display_room(game);
        //}
        update(game);
        check(game);
    }
}

int     window(void)
{
    my_game_t    *game = NULL;
    win_t win;

    init_w(&win);
    if (!(game = set_game()))
        return (84);
    game->camera->move.x = 5;
    game->camera->move.y = 1;
    game->camera->move.z = 5;
    game->clock = sfClock_create();
    game->time_fg = sfClock_getElapsedTime(game->clock).microseconds;
    game->in_game = 1;
    menu_window(&win, game);
    return (0);
}
