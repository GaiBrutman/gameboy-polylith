#pragma once

#include <stdbool.h>

#include "ui/screen.h"

/**
 * @brief Draw a character on the screen.
 *
 * @param screen The screen to draw on.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @param c The character to draw.
 * @return Whether the character was drawn successfully.
 */
bool ui_draw__draw_char(ui_screen_t *screen, int x, int y, char c);
