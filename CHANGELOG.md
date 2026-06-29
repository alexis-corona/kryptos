# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/2.0.0/), and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.1.0] - 2026-06-28
### Changed
- **Input Handling Architecture:** Upgraded data capturing across the core application by replacing unsafe `std::cin` streams with `getline` and `stoi`.
- **CLI Stability:** Enhanced input validation to prevent buffer overflows, handling empty inputs and non-numeric strings safely without crashes.

## [1.0.0] - 2026-06-22
### Added
- **Caesar Cipher:** Full implementation for encrypting and decrypting text using customizable shift values.
- **Vigenère Cipher:** Support for polyalphabetic substitution using a keyword for enhanced security.
- **ROT13 Cipher:** Quick encryption and decryption with a fixed 13-character shift.
- **Interactive Menu:** User-friendly command-line interface with semantic terminal colors to select ciphers and operations.
- **Robust Input Validation:** Complete protection against invalid choices and empty inputs across all submenus.