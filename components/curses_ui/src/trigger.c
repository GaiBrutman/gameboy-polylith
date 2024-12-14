#include <stdbool.h>
#include <curses.h>

#include "ui/trigger.h"

static int timeout_ms_to_tenths(int timeout_ms)
{
    int timeout_tenths = timeout_ms / 100;

    if (timeout_tenths > 255)
    {
        timeout_tenths = 255;
    }
    if (timeout_ms < 100) {
        // ncurses does not support sub-tenth of a second timeouts, set to minimum
        timeout_tenths = 1;
    }

    return timeout_tenths;
}

char ui_trigger__get_input_char(int timeout_ms)
{
    char input_char = '\0';

    // Set input timeout, ncurses only supports timeout in tenths of a second.
    halfdelay(timeout_ms_to_tenths(timeout_ms));

    input_char = getch();
    if (ERR == input_char)
    {
        input_char = UI_TRIGGER_TIMEOUT;
    }

    return input_char;
}

void ui_trigger__wait_for(bool (*trigger_cb)(char))
{
    // Set non-blocking mode to false to save CPU cycles
    nodelay(stdscr, FALSE);

    while (!trigger_cb(getch()))
        ;
}
