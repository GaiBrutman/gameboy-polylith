#include <unity.h>

#include "ui/screen.h"
#include "game/game.h"

void setUp(void) {}
void tearDown(void) {}

static bool dummy_run(ui_screen_t *screen)
{
    return true;
}

static game_t sg_valid_game = {
    .name = "Test Game",
    .description = "Test Game Description",
    .run = dummy_run,
};

static ui_screen_t sg_valid_screen = {
    .size = {
        .width = 10,
        .height = 10,
    },
    .is_initialized = true,
};

static ui_screen_t sg_uninitialized_screen = {
    .size = {
        .width = 10,
        .height = 10,
    },
    .is_initialized = false,
};

void test_game__run__sanity(void)
{
    TEST_ASSERT_EQUAL(true, game__run(&sg_valid_game, &sg_valid_screen));
}

void test_game__run__invalid_args(void)
{
    TEST_ASSERT_EQUAL(false, game__run(&sg_valid_game, NULL));
    TEST_ASSERT_EQUAL(false, game__run(NULL, &sg_valid_screen));
    TEST_ASSERT_EQUAL(false, game__run(NULL, NULL));
    TEST_ASSERT_EQUAL(false, game__run(&sg_valid_game, &sg_uninitialized_screen));
}

int main(void)
{
    UnityBegin(__FILE__);

    RUN_TEST(test_game__run__sanity);
    RUN_TEST(test_game__run__invalid_args);

    return (UnityEnd());
}
