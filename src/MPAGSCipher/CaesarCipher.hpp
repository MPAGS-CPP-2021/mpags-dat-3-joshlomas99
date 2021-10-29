#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>

class CaesarCipher {
    public:
        CaesarCipher(const std::size_t cipherKey);

        std::size_t key_{0}; ///< Cipher key.
};

#endif    // MPAGSCIPHER_CAESARCIPHER_HPP