/*
 * Description:
 * Header file for the Strophe Cipher functionality. It contains the function 
 * declarations for encrypting and decrypting text using the 6-round Strophe 
 * Cascade algorithm with dynamic asymmetric key mutations.
 *
 * Author: Alexis Corona
 * Version: 1.1.0
 */

#ifndef STROPHE_H
#define STROPHE_H

#include <string>

/**
 * @brief Submenu module for handling Strophe Cipher user operations.
 * Manages UI interactions, string validations for text/keys, and numerical
 * constraints for the 6-digit seed required during decryption.
 * @return std::string The processing results or redirection message.
 */
std::string strophe();

/**
 * @brief Encrypts plaintext using the 6-round Strophe Cascade algorithm.
 * Generates a random 6-digit seed to drive asymmetric key mutations.
 * @param text The original plaintext string to encrypt.
 * @param key The base alphabetic keyword.
 * @return std::string The resulting encrypted ciphertext followed by the generated seed.
 */
std::string stropheEncrypt(const std::string& text, const std::string& key);

/**
 * @brief Decrypts ciphertext by reversing the 6-round Strophe Cascade.
 * Pre-calculates the key mutation history using the provided seed.
 * @param text The ciphertext string to decrypt.
 * @param key The base alphabetic keyword.
 * @param seed A 6-character numeric string acting as the decryption key.
 * @return std::string The resulting decrypted plaintext.
 */
std::string stropheDecrypt(const std::string& text, const std::string& key, const std::string& seed);

#endif // STROPHE_H
