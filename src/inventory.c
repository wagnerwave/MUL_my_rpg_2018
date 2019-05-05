/*
** EPITECH PROJECT, 2019
** inventory
** File description:
** inventory management
*/

#include "my.h"

static void show_items(play_t *play, my_game_t *game, item_t *items)
{
    sfSprite_setPosition((items[0]).sprite, (sfVector2f) 
    {1710.0 / 4 , 230.0 / 4});
    sfSprite_setPosition((items[1]).sprite, (sfVector2f)
    {1760.0 / 4 , 230.0 / 4});
    sfSprite_setPosition((items[2]).sprite, (sfVector2f)
    {1810.0 / 4 , 230.0 / 4});
    sfRenderWindow_drawSprite(game->win->window, (items[0]).sprite, NULL);
    sfRenderWindow_drawSprite(game->win->window, (items[1]).sprite, NULL);
    sfRenderWindow_drawSprite(game->win->window, (items[2]).sprite, NULL);
}

static void inv_loop(play_t *play, my_game_t *game)
{
    sfVector2i mouse;

    sfRenderWindow_setMouseCursorVisible(game->win->window, sfTrue);
    while (sfRenderWindow_isOpen(game->win->window)) {
        mouse = sfMouse_getPositionRenderWindow(game->win->window);
        sfRenderWindow_drawSprite(game->win->window, play->s_inv, NULL);
        show_items(play, game, play->items);
        if (mouse.x >= 1370 && mouse.x <= 1480 && mouse.y >= 80 &&
            mouse.y <= 160 && sfMouse_isButtonPressed(sfMouseLeft)) {
            play->inventory = false;
            break;
        }
        sfRenderWindow_display(game->win->window);
    }
    sfRenderWindow_setMouseCursorVisible(game->win->window, sfFalse);
}

void inventory(play_t *play, my_game_t *game)
{
    play->inventory = !play->inventory;
    
    if (play->inventory == false)
        return;
    inv_loop(play, game);
}