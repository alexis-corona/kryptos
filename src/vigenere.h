/*
 * Description:
 * Header file for Vigenère Cipher functionality. It contains the function 
 * declarations for encrypting and decrypting text using the Vigenère Cipher.
 * The Vigenère Cipher uses a keyword to shift each letter of the text in a 
 * cyclic manner.
 *
 * Author: Alexis Corona
 * Version: 1.1.0
 */

#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

/**
 * @brief Submenu module for handling Vigenère Cipher user operations.
 * Renders the interaction loop for capturing text and key inputs, validating 
 * alphabetic constraints, executing the appropriate cipher subroutine, 
 * and returning the processing results.
 * @return std::string The status message or processing results.
 */
std::string vigenere();

/**
 * @brief Encrypts a given text using the Vigenère Cipher algorithm.
 * @param text The original plaintext string to encrypt.
 * @param key The alphabetic keyword used to determine cyclical shifts.
 * @return std::string The resulting encrypted ciphertext.
 */
std::string vigenereEncrypt(const std::string& text, const std::string& key);

/**
 * @brief Decrypts a ciphertext string using the Vigenère Cipher algorithm.
 * @param text The encrypted ciphertext string to decrypt.
 * @param key The alphabetic keyword used to reverse cyclical shifts.
 * @return std::string The resulting decrypted plaintext.
 */
std::string vigenereDecrypt(const std::string& text, const std::string& key);

#endif // VIGENERE_H
