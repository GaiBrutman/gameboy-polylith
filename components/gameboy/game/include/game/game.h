#pragma once

#include <stdbool.h>

#include "ui/screen.h"

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 256

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];

    bool (*run)(ui_screen_t *screen);
} game_t;

/**
 * @brief Run the game.
 *
 * @param game The game to run.
 * @param screen The screen to run the game on.
 * @return Whether the game was run successfully.
 */
bool game__run(game_t *game, ui_screen_t *screen);
