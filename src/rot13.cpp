/*
 * Description:
 * This program implements the ROT13 cipher, a simple encryption method 
 * that shifts each letter by 13 positions in the alphabet. The ROT13 cipher 
 * is commonly used to obscure text in a reversible manner, and the same 
 * function can be used for both encryption and decryption.
 * The user can choose to either encrypt or decrypt text.
 *
 * Author: Alexis Corona
 * Version: 1.0.0
 */

#include <iostream>
#include <string>
#include <limits>
#include "caesar.h"
#include "colors.h"

using namespace std;

/**
 * @brief Submenu module for handling ROT13 Cipher user operations.
 * Renders the interaction loop for capturing text inputs, routing them to 
 * the Caesar cipher subroutines with a fixed shift of 13, and returning the results.
 * @return std::string The status message or processing results.
 */
string rot13() {
    string text;
    int option;

    // Submenu interaction loop.
    while (true) {
        cout << color(TITLE) << "\n\nSelect what you want to do:\n" << color(RESET);
        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "3. Back\n\n";
        cout << color(PROMPT) << "> " << color(RESET);
        
        // Validate that the input is an integer within the permitted menu range.
        if (cin >> option && (option >= 1 && option <= 3)) {
            break;
        } else {
            cout << color(ERROR) << "\nInvalid option\n" << color(RESET);
            cin.clear(); // Clear input error.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore until the next newline.
        }
    }

    // Return to the main menu if the user chooses to go back.
    if (option == 3) return color(MUTED) + "\nReturning to main menu..." + color(RESET);

    // Clear the trailing newline character from the menu selection.
    cin.ignore();

    // Loop for requesting and validating text input.
    while (true) {
        cout << "\nEnter the text to be encrypted or decrypted: ";
        getline(cin, text);

        if (text.empty()) {
            cout << color(ERROR) << "\nError: The text cannot be empty.\n" << color(RESET);
        } else {
            break;
        }
    }

   // Process the selected cipher operation and return the result.
    if (option == 1) {
        return color(SUCCESS) + "\nEncrypted text: " + caesarEncrypt(text, 13) + color(RESET);
    } else if (option == 2) {
        return color(SUCCESS) + "\nDecrypted text: " + caesarDecrypt(text, 13) + color(RESET);
    }

    return "";
}