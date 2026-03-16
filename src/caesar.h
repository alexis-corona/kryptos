/*
 * Description:
 * Header file for Caesar Cipher functionality. It contains the function 
 * declarations for encrypting and decrypting text using the Caesar Cipher.
 * This cipher shifts each character of the text by a given number of positions.
 *
 * Functions:
 * - caesarEncrypt: Encrypts the text using a shift value.
 * - caesarDecrypt: Decrypts the text using a shift value.
 *
 * Author: Alexis Corona
 * Version: 1.0.0 (stable)
 */

#ifndef CAESAR_H
#define CAESAR_H

#include <string>

std::string caesar();
std::string caesarEncrypt(const std::string& text, int shift);
std::string caesarDecrypt(const std::string& text, int shift);

#endif
