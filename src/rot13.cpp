/*
 * Description:
 * This program implements the ROT13 cipher, a simple encryption method 
 * that shifts each letter by 13 positions in the alphabet. The ROT13 cipher 
 * is commonly used to obscure text in a reversible manner, and the same 
 * function can be used for both encryption and decryption.
 * The user can choose to either encrypt or decrypt text.
 *
 * Author: Alexis Corona
 * Version: 1.0.0 (stable)
 */

#include <iostream>
#include <string>
#include <limits>
#include "caesar.h"

using namespace std;

string rot13() {
    string text;
    int option;

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

    if (option == 1) {
        return "\nEncrypted text: " + caesarEncrypt(text, 13);
    } else if (option == 2) {
        return "\nDecrypted text: " + caesarDecrypt(text, 13);
    }

    return "";
}