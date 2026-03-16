/*
 * Description:
 * Header file for Vigenère Cipher functionality. It contains the function 
 * declarations for encrypting and decrypting text using the Vigenère Cipher.
 * The Vigenère Cipher uses a keyword to shift each letter of the text in a 
 * cyclic manner.
 *
 * Functions:
 * - vigenereEncrypt: Encrypts the text using the provided keyword.
 * - vigenereDecrypt: Decrypts the text using the provided keyword.
 *
 * Author: Alexis Corona
 * Version: 1.0.0 (stable)
 */

#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

std::string vigenere();
std::string vigenereEncrypt(const std::string& text, const std::string& key);
std::string vigenereDecrypt(const std::string& text, const std::string& key);

#endif
