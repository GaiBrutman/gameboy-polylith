#include <stdbool.h>
#include <stddef.h>

#include "ui/screen.h"
#include "game/game.h"

bool game__run(game_t *game, ui_screen_t *screen)
{
    if (NULL == game || NULL == screen || !screen->is_initialized)
    {
        return false;
    }

    return game->run(screen);
}
