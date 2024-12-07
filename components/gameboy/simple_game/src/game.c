#include <stdbool.h>

#include "ui/screen.h"
#include "ui/draw.h"
#include "ui/trigger.h"
#include "game/game.h"

#include "simple_game/game.h"

static bool is_exit_pressed(char c)
{
    return c == 'q';
}

static bool run_simple_game(ui_screen_t *screen)
{
    for (int i = 10; i < 20; i++)
    {
        for (int j = 10; j < 20; j++)
        {
            ui_draw__draw_char(screen, i, j, 'o');
        }
    }

    ui_trigger__wait_for(is_exit_pressed);
    return true;
}

game_t simple_game_get_game(void)
{
    game_t game = {
        .name = "Simple Game",
        .description = "An example of a simple gameboy game.",
        .run = run_simple_game,
    };

    return game;
}
