/*
 * Description:
 * Header file for Caesar Cipher functionality. It contains the function 
 * declarations for encrypting and decrypting text using the Caesar Cipher.
 * This cipher shifts each character of the text by a given number of positions.
 *
 * Author: Alexis Corona
 * Version: Development
 */

#ifndef CAESAR_H
#define CAESAR_H

#include <string>

/**
 * @brief Submenu module for handling Caesar Cipher user operations.
 * Renders the interaction loop for capturing text inputs, validating offset shifts,
 * executing the appropriate cipher subroutine, and returning the processing results.
 * @return std::string The status message or processing results.
 */
std::string caesar();

/**
 * @brief Encrypts a given text using the Caesar Cipher algorithm.
 * @param text The original plaintext string to encrypt.
 * @param shift The number of positions to shift each letter.
 * @return std::string The resulting encrypted ciphertext.
 */
std::string caesarEncrypt(const std::string& text, int shift);

/**
 * @brief Decrypts a ciphertext string using the Caesar Cipher algorithm.
 * @param text The encrypted ciphertext string to decrypt.
 * @param shift The number of positions to shift back each letter.
 * @return std::string The resulting decrypted plaintext.
 */
std::string caesarDecrypt(const std::string& text, int shift);

#endif // CAESAR_H
