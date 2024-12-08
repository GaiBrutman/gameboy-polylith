#pragma once

#include <stdbool.h>

/**
 * @brief Get an input character.
 *
 * @return The input character.
 */
char ui_trigger__get_input_char(void);

/**
 * @brief Wait for a trigger.
 *
 * @param trigger_cb The trigger callback. Receives the input character. Return true to stop waiting.
 */
void ui_trigger__wait_for(bool (*trigger_cb)(char));
