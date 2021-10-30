#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>
#include <vector>

class CaesarCipher {
    public:
        explicit CaesarCipher(const std::size_t cipherKey);
        explicit CaesarCipher(const std::string cipherKey);
        std::string applyCipher(const std::string inputText, const bool encrypt);
    
    private:
        std::size_t key_{0}; ///< Cipher key.
        std::vector<char> alphabet_{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; ///< Alphabet container.
};

#endif    // MPAGSCIPHER_CAESARCIPHER_HPP