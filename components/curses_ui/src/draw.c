#include <stdbool.h>
#include <curses.h>

#include "ui/draw.h"

bool ui_draw__draw_char(ui_screen_t *screen, int x, int y, char c)
{
    if (!screen->is_initialized)
    {
        return false;
    }

    if (x < 0 || x >= screen->size.width || y < 0 || y >= screen->size.height)
    {
        return false;
    }

    mvprintw(y, x, "%c", c);
    return true;
}
