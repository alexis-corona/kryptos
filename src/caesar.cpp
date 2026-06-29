/*
 * Description:
 * This program implements the Caesar Cipher, a classical encryption method
 * where each letter in the text is shifted by a specified number of positions.
 * The user can choose to either encrypt or decrypt text by providing a shift value.
 *
 * Author: Alexis Corona
 * Version: 1.1.0
 */

#include <iostream>
#include <string>
#include <limits>
#include "colors.h"

using namespace std;

/**
 * @brief Encrypts a given text using the Caesar Cipher algorithm.
 * @param text The original plaintext string to encrypt.
 * @param shift The number of positions to shift each letter.
 * @return std::string The resulting encrypted ciphertext.
 */
string caesarEncrypt(const string& text, int shift);

/**
 * @brief Decrypts a ciphertext string using the Caesar Cipher algorithm.
 * @param text The encrypted ciphertext string to decrypt.
 * @param shift The number of positions to shift back each letter.
 * @return std::string The resulting decrypted plaintext.
 */
string caesarDecrypt(const string& text, int shift);

/**
 * @brief Submenu module for handling Caesar Cipher user operations.
 * Renders the interaction loop for capturing text inputs, validating offset shifts,
 * executing the appropriate cipher subroutine, and returning the processing results.
 * @return std::string The status message or processing results.
 */
string caesar() {
    string text, stringShift, stringOption;
    int option, shift;

    // Submenu interaction loop.
    while (true) {
        cout << color(TITLE) << "\n\nSelect what you want to do:\n" << color(RESET);
        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "3. Back\n\n";
        cout << color(PROMPT) << "> " << color(RESET);

        // Captures the full line entered by the user to avoid leaving trailing newlines.
        getline(cin, stringOption);
        
        try {
            // Attempt to convert the string input into an integer.
            option = stoi(stringOption);

            // Validate that the input is an integer within the permitted menu range.
            if (option >= 1 && option <= 3) {
                break;
            } else {
                // Handle out-of-range numeric choices.
                cout << color(ERROR) << "\nError: Invalid option\n" << color(RESET);
            }
        } catch (...) {
            // Handle empty inputs (Enter key) or non-numeric strings intercepted by stoi.
            cout << color(ERROR) << "\nError: You must enter a number\n" << color(RESET);
        }
    }

    // Return to the main menu if the user chooses to go back.
    if (option == 3) return color(MUTED) + "\nReturning to main menu..." + color(RESET);
    
    // Loop for requesting and validating text input.
    while (true) {
        cout << "\nEnter the text to be encrypted or decrypted: ";
        getline(cin, text);

        if (text.empty()) {
            cout << color(ERROR) << "\nError: The text cannot be empty\n" << color(RESET);
        } else {
            break;
        }
    }

    // Loop for capturing, parsing, and validating numerical offset values.
    while (true) {
        cout << "\nEnter the offset (number of positions): ";
        getline(cin, stringShift);
    
        if (stringShift.empty()) {
            cout << color(ERROR) << "\nError: The offset cannot be empty\n" << color(RESET);
            continue; // Request entry again.
        }
    
        try {
            shift = stoi(stringShift); // Attempt to parse the input string into an integer.
    
            if (shift >= 0) {
                break; // Exit validation loop if the integer is non-negative.
            } else {
                cout << color(ERROR) << "\nError: Enter a positive number\n" << color(RESET);
            }
        } catch (const invalid_argument&) {
            cout << color(ERROR) << "\nError: You must enter a valid number\n" << color(RESET);
        } catch (const out_of_range&) {
            cout << color(ERROR) << "\nError: Number outside the allowed range\n" << color(RESET);
        }
    }

    // Process the selected cipher operation and return the result.
    if (option == 1) {
        return color(SUCCESS) + "\nEncrypted text: " + caesarEncrypt(text, shift) + color(RESET);
    } else if (option == 2) {
        return color(SUCCESS) + "\nDecrypted text: " + caesarDecrypt(text, shift) + color(RESET);
    }

    return "";
}

string caesarEncrypt(const string& text, int shift) {
    string encrypt = text;

    for (size_t i = 0; i < text.length(); i++) {
        char c = text[i];

        // Shift processing bounded to standard alphabetical ASCII intervals.
        if (c >= 'A' && c <= 'Z') {
            encrypt[i] = (c - 'A' + shift) % 26 + 'A'; // Shift within the upper-case range A-Z.
        } else if (c >= 'a' && c <= 'z') {
            encrypt[i] = (c - 'a' + shift) % 26 + 'a'; // Shift within the lower-case range a-z.
        }
    }

    return encrypt;
}

string caesarDecrypt(const string& text, int shift) {
    // Apply modulo complement logic to securely handle modular additive inverses.
    return caesarEncrypt(text, (26 - (shift % 26)) % 26);
}