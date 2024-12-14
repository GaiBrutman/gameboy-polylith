#pragma once

#include <stdbool.h>

#define UI_TRIGGER_TIMEOUT (-1)

/**
 * @brief Get an input character.
 *
 * @param timeout_ms The amount of time to wait for input. 0 means wait indefinitely.
 * @return The input character, or UI_TRIGGER_TIMEOUT if no input was received.
 */
char ui_trigger__get_input_char(int timeout_ms);

/**
 * @brief Wait for a trigger.
 *
 * @param trigger_cb The trigger callback. Receives the input character. Return true to stop waiting.
 */
void ui_trigger__wait_for(bool (*trigger_cb)(char));
