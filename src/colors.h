/*
 * Description:
 * Header file for terminal UI color configuration. It contains the enum
 * declarations and utility functions to apply ANSI escape codes to the text.
 * This allows the application to standardise UI highlights across all modules.
 *
 * Author: Alexis Corona
 * Version: 1.1.0
 */

#ifndef COLORS_H
#define COLORS_H

#include <string>

/**
 * @brief Enumeration representing the available terminal UI colors.
 * This allows us to use semantic names instead of raw ANSI codes.
 */
enum TermColor {
    RESET,
    TITLE,
    PROMPT,
    ERROR,
    SUCCESS,
    MUTED
};

/**
 * @brief Returns the corresponding ANSI escape code for the selected color.
 * @param selection The TermColor enum value.
 * @return std::string The ANSI escape sequence.
 */
inline std::string color(TermColor selection) {
    switch (selection) {
        case RESET: return "\033[0m";
        case TITLE: return "\033[36m"; // Cyan
        case PROMPT: return "\033[33m"; // Yellow
        case ERROR: return "\033[31m"; // Red
        case SUCCESS: return "\033[32m"; // Green
        case MUTED: return "\033[90m"; // Dark Gray
        default: return "\033[0m";
    }
}

#endif // COLORS_H