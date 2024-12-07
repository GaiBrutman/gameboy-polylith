#pragma once

#include <stdbool.h>

typedef struct
{
    int width;
    int height;
} ui_screen_size_t;

typedef struct
{
    ui_screen_size_t size;
    bool is_initialized;
} ui_screen_t;

/**
 * @brief Initialize the screen.
 *
 * @param screen The screen to initialize.
 * @return Whether the screen was initialized successfully.
 */
bool ui_screen__init(ui_screen_t *screen);

/**
 * @brief Destroy the screen. Must be called after ui_screen__init.
 *
 * @param screen The screen to destroy.
 * @return Whether the screen was destroyed successfully.
 */
bool ui_screen__destroy(ui_screen_t *screen);

/**
 * @brief Clear the screen. Must be called after ui_screen__init.
 *
 * @param screen The screen to clear.
 * @return Whether the screen was cleared successfully.
 */
bool ui_screen__clear(ui_screen_t *screen);

/**
 * @brief Refresh the screen. Must be called after ui_screen__init.
 *
 * @param screen The screen to refresh.
 * @return Whether the screen was refreshed successfully.
 */
bool ui_screen__refresh(ui_screen_t *screen);
