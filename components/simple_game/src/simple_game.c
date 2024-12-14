#include <stdbool.h>
#include <stddef.h>

#include "ui/screen.h"
#include "ui/draw.h"
#include "ui/trigger.h"
#include "game/game.h"

#include "simple_game/game.h"

#define INPUT_TIMEOUT_MS (100)

#define PLAYER_CHAR ('o')
#define QUIT_CHAR ('q')
#define UP_CHAR ('w')
#define LEFT_CHAR ('a')
#define DOWN_CHAR ('s')
#define RIGHT_CHAR ('d')

typedef struct
{
    struct
    {
        int x;
        int y;
    } position;
} player_t;

static player_t sg_player = {
    .position = {
        .x = 2,
        .y = 2,
    },
};

static bool draw_player(ui_screen_t *screen)
{
    return ui_draw__draw_char(screen, sg_player.position.x, sg_player.position.y, PLAYER_CHAR);
}

static void move_player_constrained(player_t *player, ui_screen_t *screen, int dx, int dy)
{
    if (NULL == player || NULL == screen)
    {
        return;
    }

    player->position.x += dx;
    player->position.y += dy;

    if (player->position.x < 0)
    {
        player->position.x = 0;
    }
    else if (player->position.x >= screen->size.width)
    {
        player->position.x = screen->size.width - 1;
    }

    if (player->position.y < 0)
    {
        player->position.y = 0;
    }
    else if (player->position.y >= screen->size.height)
    {
        player->position.y = screen->size.height - 1;
    }
}

static bool run_simple_game(ui_screen_t *screen)
{
    bool done = false;
    char input_char = '\0';
    int vel_x = 1;
    int vel_y = 0;

    draw_player(screen);

    while (!done)
    {
        input_char = ui_trigger__get_input_char(INPUT_TIMEOUT_MS);
        switch (input_char)
        {
        case UP_CHAR:
            vel_x = 0;
            vel_y = -1;
            break;
        case LEFT_CHAR:
            vel_x = -1;
            vel_y = 0;
            break;
        case DOWN_CHAR:
            vel_x = 0;
            vel_y = 1;
            break;
        case RIGHT_CHAR:
            vel_x = 1;
            vel_y = 0;
            break;
        case QUIT_CHAR:
            done = true;
            break;
        case UI_TRIGGER_TIMEOUT:
            break;
        }
        move_player_constrained(&sg_player, screen, vel_x, vel_y);
        draw_player(screen);
    }

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
