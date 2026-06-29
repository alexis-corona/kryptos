/*
 * Description:
 * This program implements the Strophe Cipher, an advanced multi-round hybrid 
 * encryption method. It utilizes a 6-digit dynamic seed to mutate a keyword 
 * asymmetrically through 6 consecutive rounds, applying interleaved layers 
 * of Caesar and Vigenère ciphers.
 *
 * Author: Alexis Corona
 * Version: 1.1.0
 */

#include <iostream>
#include <string>
#include <limits>
#include <random>
#include <sstream>
#include <iomanip>
#include <cctype>
#include "caesar.h"
#include "vigenere.h"
#include "colors.h"

using namespace std;

/**
 * @brief Encrypts plaintext using the 6-round Strophe Cascade algorithm.
 * Generates a random 6-digit seed to drive asymmetric key mutations.
 * @param text The original plaintext string to encrypt.
 * @param key The base alphabetic keyword.
 * @return std::string The resulting encrypted ciphertext followed by the generated seed.
 */
string stropheEncrypt(const string& text, const string& key);

/**
 * @brief Decrypts ciphertext by reversing the 6-round Strophe Cascade.
 * Pre-calculates the key mutation history using the provided seed.
 * @param text The ciphertext string to decrypt.
 * @param key The base alphabetic keyword.
 * @param seed A 6-character numeric string acting as the decryption key.
 * @return std::string The resulting decrypted plaintext.
 */
string stropheDecrypt(const string& text, const string& key, const string& seed);

/**
 * @brief Submenu module for handling Strophe Cipher user operations.
 * Manages UI interactions, string validations for text/keys, and numerical
 * constraints for the 6-digit seed required during decryption.
 * @return std::string The processing results or redirection message.
 */
string strophe() {
    string text, key, stringSeed, stringOption;
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
        return color(SUCCESS) + "\nEncrypted text: " + stropheEncrypt(text, key) + color(RESET);
    } else if (option == 2) {
        // Dynamic validation loop specifically for the 6-digit seed string.
        while (true) {
            cout << "\nEnter the seed (6 digits): ";
            getline(cin, stringSeed);
        
            if (stringSeed.empty()) {
                cout << color(ERROR) << "\nError: The seed cannot be empty\n" << color(RESET);
                continue;
            }
        
            if (stringSeed.length() != 6) {
                cout << color(ERROR) << "\nError: The seed must be exactly 6 digits long\n" << color(RESET);
                continue;
            }

            bool validSeed = true;
            for (char c : stringSeed) {
                if (!isdigit(c)) {
                    validSeed = false;
                    break;
                }
            }

            if (!validSeed) {
                cout << color(ERROR) << "\nError: The seed must only contain numbers\n" << color(RESET);
            } else {
                break; // Validation passed successfully
            }
        }
        return color(SUCCESS) + "\nDecrypted text: " + stropheDecrypt(text, key, stringSeed) + color(RESET);
    }

    return "";
}

string stropheEncrypt(const string& text, const string& key) {
    string encrypt = text;
    string currentKey = key;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, 999999);
    int number = distrib(gen);

    std::stringstream ss;
    ss << std::setw(6) << std::setfill('0') << number;
    std::string stringNumber = ss.str();

    int digit;

    for (size_t i = 0; i < 6; i++) {
        if ((digit = stringNumber[i] - '0') == 0) {
             digit = i + 1;
        }

        string newKey = "";
        size_t keyLength = currentKey.length();

        for (size_t j = 0; j < keyLength; j++) {
            char keyChar = currentKey[j];
            std::string keyCharString(1, keyChar);
            newKey = newKey + caesarEncrypt(keyCharString, digit + j);
        }

        if (digit % 2 == 0) {
            encrypt = vigenereEncrypt(encrypt, newKey);
        } else {
            encrypt = caesarEncrypt(encrypt, digit);
            encrypt = vigenereEncrypt(encrypt, newKey);
        }

        currentKey = newKey;
    }
    
    return encrypt + "\n\nseed: " + stringNumber;
}

string stropheDecrypt(const string& text, const string& key, const string& seed) {
    string decrypt = text;
    string keyHistory[6];
    string currentKey = key;
    int digit;

    for (size_t i = 0; i < 6; i++) {
        if ((digit = seed[i] - '0') == 0) {
            digit = i + 1;
        }

        string newKey = "";
        size_t keyLength = currentKey.length();

        for (size_t j = 0; j < keyLength; j++) {
            char keyChar = currentKey[j];
            std::string keyCharString(1, keyChar);
            newKey = newKey + caesarEncrypt(keyCharString, digit + j);
        }
        
        keyHistory[i] = newKey;
        currentKey = newKey;
    }

    for (int i = 5; i >= 0; i--) {
        if ((digit = seed[i] - '0') == 0) {
            digit = i + 1;
        }

        string roundKey = keyHistory[i];

        if (digit % 2 == 0) {
            decrypt = vigenereDecrypt(decrypt, roundKey);
        } else {
            decrypt = vigenereDecrypt(decrypt, roundKey);
            decrypt = caesarDecrypt(decrypt, digit);
        }
    }

    return decrypt;
}