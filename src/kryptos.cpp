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
 * Version: 1.1.0
 */

#include <iostream>
#include <string>
#include <limits>
#include "caesar.h"
#include "vigenere.h"
#include "rot13.h"
#include "strophe.h"
#include "colors.h"

using namespace std;

/**
 * @brief Main entry point of the Kryptos application.
 * Manages the primary CLI loop, rendering the main menu, handling user selection,
 * and routing execution to the selected cryptographic algorithm module.
 */
int main() {
    string stringOption;
    int option;

    // Main execution loop for user interaction.
    while (true) {
        cout << color(TITLE) << "\nSelect what type of encryption or decryption you want:\n" << color(RESET); 
        cout << "1. Caesar\n";
        cout << "2. Vigenère\n";
        cout << "3. ROT13\n";
        cout << "4. Strophe (Custom Hybrid Cipher)\n";
        cout << "5. Exit\n\n";
        cout << color(PROMPT) << "> " << color(RESET);

        // Captures the full line entered by the user to avoid leaving trailing newlines.
        getline(cin, stringOption);

        try {
            // Attempt to convert the string input into an integer.
            option = stoi(stringOption);

            // Validate that the input is an integer within the permitted menu range.
            if (option >= 1 && option <= 5) {

                // Terminate the execution loop and close the application.
                if (option == 5) {
                    cout << color(MUTED) << "\nEnding program...\n" << color(RESET);
                    break;
                }

                // Launch the Caesar Cipher submenu module.
                if (option == 1) {
                    cout << caesar() + "\n\n";
                // Launch the Vigenère Cipher submenu module.
                } else if (option == 2) {
                    cout << vigenere() + "\n\n";
                // Launch the ROT13 Cipher submenu module.
                } else if (option == 3) {
                    cout << rot13() + "\n\n";
                } else if (option == 4) {
                    cout << strophe() + "\n\n";
                }

            } else {
                // Handle out-of-range numeric choices.
                cout << color(ERROR) << "\nError: Invalid option\n\n" << color(RESET);
            }
        } catch (...) {
            // Handle empty inputs (Enter key) or non-numeric strings intercepted by stoi.
            cout << color(ERROR) << "\nError: You must enter a number\n\n" << color(RESET);
        }
    }

    return 0;
}
