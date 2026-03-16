/*
 * Description:
 * This program implements the Caesar Cipher, a classical encryption method
 * where each letter in the text is shifted by a specified number of positions.
 * The user can choose to either encrypt or decrypt text by providing a shift value.
 *
 * Author: Alexis Corona
 * Version: 1.0.0 (stable)
 */

#include <iostream>
#include <string>
#include <limits>

using namespace std;

string caesarEncrypt(const string& text, int shift);
string caesarDecrypt(const string& text, int shift);

string caesar() {
    string text, stringShift;
    int option, shift;

    while (true) {
        cout << "\nSelect what you want to do:\n";
        cout << "1. Encrypt \n2. Decrypt\n";
        
        if (cin >> option && (option == 1 || option == 2)) {
            break;
        } else {
            cout << "\nInvalid option\n";
            cin.clear(); // Clear input error.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore until the next newline.
        }
    }

    while (true) {
        cout << "\nEnter the text to be encrypted or decrypted: ";
        cin.ignore();
        getline(cin, text);

        if (text.empty()) {
            cout << "\nError: The text cannot be empty.\n";
        } else {
            break;
        }
    }

    while (true) {
        cout << "\nEnter the offset (number of positions): ";
        getline(cin, stringShift);
    
        if (stringShift.empty()) {
            cout << "\nError: The offset cannot be empty\n";
            continue; // Request entry again.
        }
    
        try {
            shift = stoi(stringShift); // Try to convert the input to a number.
    
            if (shift >= 0) {
                break; // Exit the loop if the number is valid.
            } else {
                cout << "\nError: Enter a positive number.\n";
            }
        } catch (const invalid_argument&) {
            cout << "\nError: You must enter a valid number.\n";
        } catch (const out_of_range&) {
            cout << "\nError: Number outside the allowed range.\n";
        }
    }

    if (option == 1) {
        return "\nEncrypted text: " + caesarEncrypt(text, shift);
    } else if (option == 2) {
        return "\nDecrypted text: " + caesarDecrypt(text, shift);
    }

    return "";
}

string caesarEncrypt(const string& text, int shift) {
    string encrypt = text;

    for (size_t i = 0; i < text.length(); i++) {
        char c = text[i];

        if (c >= 'A' && c <= 'Z') {
            encrypt[i] = (c - 'A' + shift) % 26 + 'A'; // Move within the range A-Z.
        } else if (c >= 'a' && c <= 'z') {
            encrypt[i] = (c - 'a' + shift) % 26 + 'a'; // Move within the range a-z.
        }
    }

    return encrypt;
}

string caesarDecrypt(const string& text, int shift) {
    return caesarEncrypt(text, (26 - (shift % 26)) % 26); // Use the complement to ensure positive range.
}