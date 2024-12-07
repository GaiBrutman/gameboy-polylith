#include <stdbool.h>
#include <curses.h>

char ui_trigger__get_input_char(void)
{
    return getch();
}

void ui_trigger__wait_for(bool (*trigger_cb)(char))
{
    while (!trigger_cb(getch()))
        ;
}
