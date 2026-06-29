/*
 * Description:
 * This program implements the Vigenère Cipher, an encryption method based on 
 * a keyword. The cipher uses the keyword to shift each letter of the text 
 * in a cyclical manner, making it more secure than simple substitution ciphers.
 * The user can choose to either encrypt or decrypt text using the provided key.
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
 * @brief Encrypts a given text using the Vigenère Cipher algorithm.
 * @param text The original plaintext string to encrypt.
 * @param key The alphabetic keyword used to determine cyclical shifts.
 * @return std::string The resulting encrypted ciphertext.
 */
string vigenereEncrypt(const string& text, const string& key);

/**
 * @brief Decrypts a ciphertext string using the Vigenère Cipher algorithm.
 * @param text The encrypted ciphertext string to decrypt.
 * @param key The alphabetic keyword used to reverse cyclical shifts.
 * @return std::string The resulting decrypted plaintext.
 */
string vigenereDecrypt(const string& text, const string& key);

/**
 * @brief Submenu module for handling Vigenère Cipher user operations.
 * Renders the interaction loop for capturing text and key inputs, validating 
 * alphabetic constraints, executing the appropriate cipher subroutine, 
 * and returning the processing results.
 * @return std::string The status message or processing results.
 */
string vigenere() {
    string text, key, stringOption;
    int option;

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

    // Loop for requesting and validating the keyword.
    while (true) {
        cout << "\nEnter the key to encrypt or decrypt: ";
        getline(cin, key);
    
        if (key.empty()) {
            cout << color(ERROR) << "\nError: The key cannot be empty\n" << color(RESET);
            continue;
        }
    
        bool validKey = true;
        for (char c : key) {
            if (!isalpha(c)) {
                validKey = false;
                break; // If it finds an invalid character, it stops checking.
            }
        }
    
        if (!validKey) {
            cout << color(ERROR) << "\nError: The key must only contain letters\n" << color(RESET);
        } else {
            break;
        }
    }

    // Process the selected cipher operation and return the result.
    if (option == 1) {
        return color(SUCCESS) + "\nEncrypted text: " + vigenereEncrypt(text, key) + color(RESET);
    } else if (option == 2) {
        return color(SUCCESS) + "\nDecrypted text: " + vigenereDecrypt(text, key) + color(RESET);
    }

    return "";
}

string vigenereEncrypt(const string& text, const string& key) {
    string encrypt = "";
    size_t keyLength = key.length();
    
    for (size_t i = 0, j = 0; i < text.length(); i++) {
        char c = text[i];
        
        // Only letters are encrypted, other characters are ignored.
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            char charKey = islower(text[i]) ? tolower(key[j % keyLength]) : toupper(key[j % keyLength]);
            int shift = charKey - base; // Determine the offset using the key.
            
            c = (c - base + shift) % 26 + base; // Add the offset to encrypt.
            j++; // Advance only if it is a letter.
        }
    
        encrypt += c;
    }
    
    return encrypt;
}

string vigenereDecrypt(const string& text, const string& key) {
    string decrypt = "";
    int keyLength = key.length();
    
    for (size_t i = 0, j = 0; i < text.length(); i++) {
        char c = text[i];
        
        // Only letters are decrypted, other characters are ignored.
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            char charKey = islower(text[i]) ? tolower(key[j % keyLength]) : toupper(key[j % keyLength]);
            int shift = charKey - base;  // Determine the offset using the key.
            
            c = (c - base - shift + 26) % 26 + base;  // Subtract the offset to decrypt.
            j++; // Advance only if it is a letter.
        }
        
        decrypt += c;
    }
    
    return decrypt;
}