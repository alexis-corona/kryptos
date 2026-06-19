/*
 * Description:
 * Header file for ROT13 Cipher functionality. It contains the function 
 * declaration for encrypting and decrypting text using the ROT13 Cipher.
 * The ROT13 Cipher shifts each letter of the text by 13 positions.
 *
 * Author: Alexis Corona
 * Version: Development
 */

#ifndef ROT13_H
#define ROT13_H

#include <string>

/**
 * @brief Submenu module for handling ROT13 Cipher user operations.
 * Renders the interaction loop for capturing text inputs, routing them to 
 * the Caesar cipher subroutines with a fixed shift of 13, and returning the results.
 * @return std::string The status message or processing results.
 */
std::string rot13();

#endif // ROT13_H
