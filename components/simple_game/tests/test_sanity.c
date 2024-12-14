#include <unity.h>

#include "ui/screen.h"
#include "simple_game/game.h"

void setUp(void) {}
void tearDown(void) {}

bool ui_draw__draw_char(ui_screen_t *screen, int x, int y, char c) { return true; }
char ui_trigger__get_input_char(int timeout_ms) { return '\0'; }

void test_simple_game__sanity(void)
{
    game_t game = simple_game_get_game();
    TEST_ASSERT_EQUAL_STRING("Simple Game", game.name);
    TEST_ASSERT_EQUAL_STRING("An example of a simple gameboy game.", game.description);
    TEST_ASSERT_NOT_NULL(game.run);
}

int main(void)
{
    UnityBegin(__FILE__);

    RUN_TEST(test_simple_game__sanity);

    return (UnityEnd());
}
