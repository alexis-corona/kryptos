/*
 * Description:
 * This program is a tool that allows you to encrypt and decrypt text
 * using three different algorithms: Caesar, Vigenère, and ROT13.
 * The user can select which type of cipher to apply to a text of their choice.
 * The program offers a simple console interface where the user can choose between:
 * 
 * 1. Caesar Cipher: A shift cipher.
 * 2. Vigenère Cipher: A more complex cipher based on a key.
 * 3. ROT13: A cipher that shifts letters 13 places.
 *
 * Each option allows the user to either encrypt or decrypt a text based on their choice.
 *
 * Author: Alexis Corona
 * Version: Development
 */

#include <iostream>
#include <string>
#include <limits>
#include "caesar.h"
#include "colors.h"

using namespace std;

/**
 * @brief Main entry point of the Kryptos application.
 * Manages the primary CLI loop, rendering the main menu, handling user selection,
 * and routing execution to the selected cryptographic algorithm module.
 */
int main() {
    int option;

    // Main execution loop for user interaction.
    while (true) {
        cout << color(TITLE) << "\nSelect what type of encryption or decryption you want:\n" << color(RESET); 
        cout << "1. Caesar\n";
        cout << "2. Exit\n\n";
        cout << color(PROMPT) << "> " << color(RESET);

        // Validate that the input is an integer within the permitted menu range.
        if (cin >> option && (option >= 1 && option <= 2)) {

            // Terminate the execution loop and close the application.
            if (option == 2) {
                cout << color(MUTED) << "\nEnding program...\n" << color(RESET);
                break;
            }

            // Launch the Caesar Cipher submenu module.
            if (option == 1) {
                cout << caesar() + "\n\n";
            }

        } else {
            // Handle invalid choices or non-numeric inputs by resetting the stream.
            cout << color(ERROR) << "\nInvalid option\n\n" << color(RESET);
            cin.clear(); // Clear input error.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore until the next newline.
        }
    }

    return 0;
}
