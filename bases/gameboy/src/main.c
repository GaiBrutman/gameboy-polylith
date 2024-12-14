#include <stdio.h>

#include "game/game.h"
#include "simple_game/game.h"
#include "ui/screen.h"

#define NUM_GAMES 1

#define GAMEBOY_START_SCREEN                                         \
    "  ________                     ___.                 \n"         \
    " /  _____/_____    _____   ____\\_ |__   ____ ___.__.\n"        \
    "/   \\  ___\\__  \\  /     \\_/ __ \\| __ \\ /  _ <   |  |\n"   \
    "\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/| \\_\\ (  <_> )___  |\n" \
    " \\______  (____  /__|_|  /\\___  >___  /\\____// ____|\n"      \
    "    \\/     \\/      \\/     \\/    \\/       \\/\n"

static game_t sg_games[NUM_GAMES] = {0};

static void initialize_games(void)
{
    sg_games[0] = simple_game_get_game();
}

int main(void)
{
    ui_screen_t screen;

    initialize_games();
    printf(GAMEBOY_START_SCREEN "\n");
    printf("Welcome to the Gameboy console!\n\n");

    printf("Available games:\n");
    for (int i = 0; i < NUM_GAMES; i++)
    {
        printf("%d. %s - %s\n", i + 1, sg_games[i].name, sg_games[i].description);
    }
    printf("\n");

    int game_choice = 0;
    printf("Enter the number of the game you would like to play: ");
    scanf("%d", &game_choice);
    if (game_choice < 1 || game_choice > NUM_GAMES)
    {
        printf("Invalid game choice.\n");
        return 1;
    }

    ui_screen__init(&screen);
    if (!game__run(&sg_games[game_choice - 1], &screen))
    {
        ui_screen__destroy(&screen);
        printf("Failed to run game.\n");
        return 1;
    }

    ui_screen__destroy(&screen);
    printf("Thanks for playing!\n");
    return 0;
}
