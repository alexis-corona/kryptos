/*
 * Description:
 * This program implements the Vigenère Cipher, an encryption method based on 
 * a keyword. The cipher uses the keyword to shift each letter of the text 
 * in a cyclical manner, making it more secure than simple substitution ciphers.
 * The user can choose to either encrypt or decrypt text using the provided key.
 *
 * Author: Alexis Corona
 * Version: 1.0.0 (stable)
 */

#include <iostream>
#include <string>
#include <limits>

using namespace std;

string vigenereEncrypt(const string& text, const string& key);
string vigenereDecrypt(const string& text, const string& key);

string vigenere() {
    string text, key;
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

    while (true) {
        cout << "\nEnter the key to encrypt or decrypt: ";
        getline(cin, key);
    
        if (key.empty()) {
            cout << "\nError: The key cannot be empty.\n";
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
            cout << "\nError: The key must only contain letters.\n";
        } else {
            break;
        }
    }

    if (option == 1) {
        return "\nEncrypted text: " + vigenereEncrypt(text, key);
    } else if (option == 2) {
        return "\nDecrypted text: " + vigenereDecrypt(text, key);
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