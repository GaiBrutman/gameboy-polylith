#include <stdbool.h>
#include <curses.h>

#include "ui/screen.h"

static ui_screen_size_t get_screen_size(void)
{
    ui_screen_size_t size;
    getmaxyx(stdscr, size.height, size.width);
    return size;
}

static void clear_screen(void)
{
    clear();
    refresh();
}

bool ui_screen__init(ui_screen_t *screen)
{
    if (screen == NULL)
    {
        return false;
    }

    initscr();
    cbreak();
    noecho();

    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);

    clear_screen();

    screen->size = get_screen_size();
    screen->is_initialized = true;
    return true;
}

bool ui_screen__destroy(ui_screen_t *screen)
{
    if (screen == NULL)
    {
        return false;
    }

    endwin();

    screen->is_initialized = false;
    return true;
}

bool ui_screen__clear(ui_screen_t *screen)
{
    if (screen == NULL || !screen->is_initialized)
    {
        return false;
    }

    clear_screen();
    return true;
}
bool ui_screen__refresh(ui_screen_t *screen);
